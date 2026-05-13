/*
 * <character encoding>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </character encoding>
 *
 * <summary>
 *   CEcoASNOnePER1_F509D9E8
 * </summary>
 *
 * <description>
 *   This source code describes the implementation of the interfaces for CEcoASNOnePER1_F509D9E8
 * </description>
 *
 * <author>
 *   Copyright (c) 2026 Vladimir Bashev. All rights reserved.
 * </author>
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoASNOnePER1.h"

 /* ========== –≈¿À»«¿÷»ﬂ ¡»“Œ¬Œ√Œ ¡”‘≈–¿ ========== */

static void bitbuf_init(BitBuf* buf, PER_Variant var, IEcoMemoryAllocator1* mem) {
    if (buf == NULL || mem == NULL) return;
    buf->capacity = 256;
    buf->variant = var;
    buf->bit_len = 0;
    buf->mem = mem;
    buf->data = (uint8_t*)mem->pVTbl->Alloc(mem, buf->capacity);
    if (buf->data != NULL) memset(buf->data, 0, buf->capacity);
}

static void bitbuf_ensure(BitBuf* buf, size_t need_bit) {
    if (buf == NULL || buf->mem == NULL || buf->capacity <= 0) return;
    size_t need_byte = (buf->bit_len + need_bit + 7) / 8;
    if (need_byte <= (size_t)buf->capacity) return;
    size_t new_capacity = (size_t)buf->capacity * 2;
    if (new_capacity < need_byte) new_capacity = need_byte;
    uint8_t* new_data = (uint8_t*)buf->mem->pVTbl->Alloc(buf->mem, new_capacity);
    if (new_data == NULL) return;
    memset(new_data, 0, new_capacity);
    if (buf->data != NULL && buf->capacity > 0) {
        memcpy(new_data, buf->data, buf->capacity);
        buf->mem->pVTbl->Free(buf->mem, buf->data);
    }
    buf->data = new_data;
    buf->capacity = (int)new_capacity;
}

static void bitbuf_append(BitBuf* buf, uint64_t value, int bit) {
    if (buf == NULL || buf->data == NULL || bit <= 0) return;
    bitbuf_ensure(buf, (size_t)bit);
    int rem = bit;
    while (rem > 0) {
        int byte_idx = buf->bit_len / 8;
        int bit_off = buf->bit_len % 8;
        int bit_free = 8 - bit_off;
        int bit_record = (rem < bit_free) ? rem : bit_free;
        uint64_t mask = (bit_record == 64) ? 0xFFFFFFFFFFFFFFFFULL : ((1ULL << bit_record) - 1);
        int shift = rem - bit_record;
        uint64_t part = (value >> shift) & mask;
        buf->data[byte_idx] |= (uint8_t)(part << (bit_free - bit_record));
        buf->bit_len += bit_record;
        rem -= bit_record;
    }
}

static void bitbuf_align(BitBuf* buf) {
    if (buf == NULL) return;
    if (buf->variant == PER_UNALIGNED) return;
    int pad = (8 - (buf->bit_len % 8)) % 8;
    if (pad > 0) bitbuf_append(buf, 0, pad);
}

static uint8_t* bitbuf_finalize(BitBuf* buf, uint32_t* out_len) {
    if (buf == NULL || out_len == NULL) return NULL;
    bitbuf_align(buf);
    if (buf->bit_len == 0) bitbuf_append(buf, 0, 8);
    *out_len = (uint32_t)(buf->bit_len / 8);
    return buf->data;
}

/* ==========  Œƒ»–Œ¬¿Õ»≈ PER ========== */

static void encode_int(BitBuf* buf, int64_t n, int64_t lb, int64_t ub) {
    if (buf == NULL) return;
    int64_t range = ub - lb + 1;
    if (range == 1) return;
    uint64_t offset = (uint64_t)(n - lb);
    if (range <= 255) {
        int bits;
        if (range > 128) bits = 8;
        else if (range > 64) bits = 7;
        else if (range > 32) bits = 6;
        else if (range > 16) bits = 5;
        else if (range > 8) bits = 4;
        else if (range > 4) bits = 3;
        else if (range > 2) bits = 2;
        else bits = 1;
        bitbuf_append(buf, offset, bits);
    }
    else if (range == 256) {
        bitbuf_align(buf);
        bitbuf_append(buf, offset, 8);
    }
    else if (range <= 65536) {
        bitbuf_align(buf);
        bitbuf_append(buf, offset, 16);
    }
    else {
        bitbuf_align(buf);
        int octets = 1;
        while (offset >> (octets * 8)) octets++;
        bitbuf_append(buf, offset, octets * 8);
    }
}

static void encode_string(BitBuf* buf, const char* s, uint32_t max_len) {
    if (buf == NULL) return;
    uint32_t len = (s != NULL) ? (uint32_t)strlen(s) : 0;
    if (len > max_len) len = max_len;
    encode_int(buf, len, 0, max_len);
    for (uint32_t i = 0; i < len; i++) bitbuf_append(buf, (uint8_t)s[i], 8);
}

static void encode_name(BitBuf* buf, Name* name, uint32_t max_len) {
    if (buf == NULL || name == NULL) return;
    encode_string(buf, name->givenName, max_len);
    encode_string(buf, name->initial, 1);
    encode_string(buf, name->familyName, max_len);
}

static void encode_personnel(BitBuf* buf, PersonnelRecord* rec) {
    if (buf == NULL || rec == NULL) return;
    bitbuf_append(buf, (rec->childCount > 0) ? 1 : 0, 1);
    encode_name(buf, &rec->name, 64);
    encode_string(buf, rec->title, 100);
    encode_int(buf, rec->number, 0, 999999);
    encode_string(buf, rec->DateOfHire, 10);
    encode_name(buf, &rec->nameOfSpouse, 64);
    if (rec->childCount > 0) {
        encode_int(buf, rec->childCount, 0, 1000);
        Child* c = rec->children;
        while (c != NULL) {
            encode_name(buf, &c->name, 64);
            encode_string(buf, c->dateOfBirth, 10);
            c = c->next;
        }
    }
}

/* ========== ƒ≈ Œƒ»–Œ¬¿Õ»≈ ========== */

typedef struct {
    uint8_t* data;
    size_t bit_len;
    size_t read_pos;
    IEcoMemoryAllocator1* mem;
} BitReader;

static void bitreader_init(BitReader* r, uint8_t* data, size_t byte_len, IEcoMemoryAllocator1* mem) {
    if (r == NULL) return;
    r->data = data;
    r->bit_len = byte_len * 8;
    r->read_pos = 0;
    r->mem = mem;
}

static uint64_t bitreader_read(BitReader* r, int bits) {
    if (r == NULL || r->data == NULL || bits <= 0 || r->read_pos + bits > r->bit_len) return 0;
    uint64_t val = 0;
    int remaining = bits;
    while (remaining > 0) {
        size_t byte_idx = r->read_pos / 8;
        int bit_off = (int)(r->read_pos % 8);
        int free_bits = 8 - bit_off;
        int take = (remaining < free_bits) ? remaining : free_bits;
        uint8_t byte = r->data[byte_idx];
        uint8_t part = (byte >> (free_bits - take)) & ((1 << take) - 1);
        val = (val << take) | part;
        r->read_pos += take;
        remaining -= take;
    }
    return val;
}

static void decode_int(BitReader* r, int64_t* out, int64_t lb, int64_t ub) {
    if (r == NULL || out == NULL) return;
    int64_t range = ub - lb + 1;
    if (range == 1) { *out = lb; return; }
    uint64_t offset = 0;
    if (range <= 255) {
        int bits;
        if (range > 128) bits = 8;
        else if (range > 64) bits = 7;
        else if (range > 32) bits = 6;
        else if (range > 16) bits = 5;
        else if (range > 8) bits = 4;
        else if (range > 4) bits = 3;
        else if (range > 2) bits = 2;
        else bits = 1;
        offset = bitreader_read(r, bits);
    }
    else if (range == 256) offset = bitreader_read(r, 8);
    else if (range <= 65536) offset = bitreader_read(r, 16);
    else offset = bitreader_read(r, 8);
    *out = lb + (int64_t)offset;
}

static char* decode_string(BitReader* r, IEcoMemoryAllocator1* mem, uint32_t max_len) {
    if (r == NULL || mem == NULL) return NULL;
    int64_t len;
    decode_int(r, &len, 0, max_len);
    if (len < 0) len = 0;
    char* str = (char*)mem->pVTbl->Alloc(mem, (size_t)len + 1);
    if (str == NULL) return NULL;
    for (int64_t i = 0; i < len; i++) str[i] = (char)bitreader_read(r, 8);
    str[len] = 0;
    return str;
}

static void decode_name(BitReader* r, Name* name, IEcoMemoryAllocator1* mem, uint32_t max_len) {
    if (r == NULL || name == NULL || mem == NULL) return;
    name->givenName = decode_string(r, mem, max_len);
    name->initial = decode_string(r, mem, 1);
    name->familyName = decode_string(r, mem, max_len);
}

static void free_personnel(PersonnelRecord* rec, IEcoMemoryAllocator1* mem);

static int16_t decode_personnel(BitReader* r, PersonnelRecord** out_rec, IEcoMemoryAllocator1* mem) {
    if (r == NULL || out_rec == NULL || mem == NULL) return ERR_ECO_POINTER;
    PersonnelRecord* rec = (PersonnelRecord*)mem->pVTbl->Alloc(mem, sizeof(PersonnelRecord));
    if (rec == NULL) return ERR_ECO_OUTOFMEMORY;
    memset(rec, 0, sizeof(PersonnelRecord));
    uint64_t children_present = bitreader_read(r, 1);
    decode_name(r, &rec->name, mem, 64);
    rec->title = decode_string(r, mem, 100);
    decode_int(r, &rec->number, 0, 999999);
    rec->DateOfHire = decode_string(r, mem, 10);
    decode_name(r, &rec->nameOfSpouse, mem, 64);
    if (children_present) {
        int64_t cnt;
        decode_int(r, &cnt, 0, 1000);
        if (cnt < 0) cnt = 0;
        rec->childCount = (uint32_t)cnt;
        Child** tail = &rec->children;
        for (uint32_t i = 0; i < rec->childCount; i++) {
            Child* child = (Child*)mem->pVTbl->Alloc(mem, sizeof(Child));
            if (child == NULL) { free_personnel(rec, mem); return ERR_ECO_OUTOFMEMORY; }
            memset(child, 0, sizeof(Child));
            decode_name(r, &child->name, mem, 64);
            child->dateOfBirth = decode_string(r, mem, 10);
            *tail = child;
            tail = &child->next;
        }
    }
    *out_rec = rec;
    return ERR_ECO_SUCCESES;
}

static void free_personnel(PersonnelRecord* rec, IEcoMemoryAllocator1* mem) {
    if (rec == NULL || mem == NULL) return;
#define FREE(p) if (p) { mem->pVTbl->Free(mem, (void*)(p)); (p) = NULL; }
    FREE(rec->name.givenName);
    FREE(rec->name.initial);
    FREE(rec->name.familyName);
    FREE(rec->title);
    FREE(rec->DateOfHire);
    FREE(rec->nameOfSpouse.givenName);
    FREE(rec->nameOfSpouse.initial);
    FREE(rec->nameOfSpouse.familyName);
    Child* c = rec->children;
    while (c != NULL) {
        Child* next = c->next;
        FREE(c->name.givenName);
        FREE(c->name.initial);
        FREE(c->name.familyName);
        FREE(c->dateOfBirth);
        mem->pVTbl->Free(mem, c);
        c = next;
    }
    mem->pVTbl->Free(mem, rec);
#undef FREE
}

/* ========== Ã≈“Œƒ€ »Õ“≈–‘≈…—¿ ========== */

static int16_t ECOCALLMETHOD CEcoASNOnePER1_F509D9E8_QueryInterface(IEcoASNOnePER1Ptr_t me, const UGUID* riid, void** ppv) {
    CEcoASNOnePER1_F509D9E8* pCMe = (CEcoASNOnePER1_F509D9E8*)me;
    if (me == 0 || ppv == 0) return ERR_ECO_POINTER;
    if (IsEqualUGUID(riid, &IID_IEcoASNOnePER1) || IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIEcoASNOnePER1;
        ((IEcoASNOnePER1VTblExt*)(*ppv))->AddRef(me);
        return ERR_ECO_SUCCESES;
    }
    *ppv = 0;
    return ERR_ECO_NOINTERFACE;
}

static uint32_t ECOCALLMETHOD CEcoASNOnePER1_F509D9E8_AddRef(IEcoASNOnePER1Ptr_t me) {
    CEcoASNOnePER1_F509D9E8* pCMe = (CEcoASNOnePER1_F509D9E8*)me;
    if (me == 0) return (uint32_t)-1;
    return atomicincrement_int32_t(&pCMe->m_cRef);
}

static uint32_t ECOCALLMETHOD CEcoASNOnePER1_F509D9E8_Release(IEcoASNOnePER1Ptr_t me) {
    CEcoASNOnePER1_F509D9E8* pCMe = (CEcoASNOnePER1_F509D9E8*)me;
    if (me == 0) return (uint32_t)-1;
    atomicdecrement_int32_t(&pCMe->m_cRef);
    if (pCMe->m_cRef == 0) { pCMe->Delete(pCMe); return 0; }
    return pCMe->m_cRef;
}

static int16_t ECOCALLMETHOD CEcoASNOnePER1_F509D9E8_MyFunction(IEcoASNOnePER1Ptr_t me, char_t* Name, char_t** copyName) {
    CEcoASNOnePER1_F509D9E8* pCMe = (CEcoASNOnePER1_F509D9E8*)me;
    if (me == 0 || Name == 0 || copyName == 0) return ERR_ECO_POINTER;
    size_t len = 0;
    while (Name[len] != 0) len++;
    pCMe->m_Name = (char_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, len + 1);
    if (pCMe->m_Name == NULL) return ERR_ECO_OUTOFMEMORY;
    for (size_t i = 0; i <= len; i++) pCMe->m_Name[i] = Name[i];
    *copyName = pCMe->m_Name;
    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD EncodePersonnelRecord(IEcoASNOnePER1Ptr_t me, PersonnelRecord* rec, uint8_t** outData, uint32_t* outLen) {
    CEcoASNOnePER1_F509D9E8* pCMe = (CEcoASNOnePER1_F509D9E8*)me;
    if (pCMe == NULL || rec == NULL || outData == NULL || outLen == NULL) return ERR_ECO_POINTER;
    BitBuf buf;
    bitbuf_init(&buf, PER_ALIGNED, pCMe->m_pIMem);
    encode_personnel(&buf, rec);
    *outData = bitbuf_finalize(&buf, outLen);
    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD DecodePersonnelRecord(IEcoASNOnePER1Ptr_t me, uint8_t* data, uint32_t len, PersonnelRecord** rec) {
    CEcoASNOnePER1_F509D9E8* pCMe = (CEcoASNOnePER1_F509D9E8*)me;
    if (pCMe == NULL || data == NULL || rec == NULL) return ERR_ECO_POINTER;
    BitReader rdr;
    bitreader_init(&rdr, data, len, pCMe->m_pIMem);
    return decode_personnel(&rdr, rec, pCMe->m_pIMem);
}

static void ECOCALLMETHOD FreePersonnelRecord(IEcoASNOnePER1Ptr_t me, PersonnelRecord* rec) {
    CEcoASNOnePER1_F509D9E8* pCMe = (CEcoASNOnePER1_F509D9E8*)me;
    if (pCMe == NULL) return;
    free_personnel(rec, pCMe->m_pIMem);
}

static int16_t ECOCALLMETHOD initCEcoASNOnePER1_F509D9E8(CEcoASNOnePER1_F509D9E8Ptr_t me, IEcoUnknownPtr_t pIUnkSystem) {
    CEcoASNOnePER1_F509D9E8* pCMe = (CEcoASNOnePER1_F509D9E8*)me;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    int16_t result = ERR_ECO_POINTER;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
    if (me == 0) return result;
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void**)&pIBus);
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }
    result = pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**)&pCMe->m_pIMem);
    if (result != 0 || pCMe->m_pIMem == 0) result = ERR_ECO_GET_MEMORY_ALLOCATOR;
    pIBus->pVTbl->Release(pIBus);
    return result;
}

static int16_t ECOCALLMETHOD createCEcoASNOnePER1_F509D9E8(CEcoASNOnePER1_F509D9E8Ptr_t pCMe, IEcoUnknownPtr_t pIUnkSystem, IEcoUnknownPtr_t pIUnkOuter) {
    if (pCMe == 0) return ERR_ECO_POINTER;
    return ERR_ECO_SUCCESES;
}

static void ECOCALLMETHOD deleteCEcoASNOnePER1_F509D9E8(CEcoASNOnePER1_F509D9E8Ptr_t pCMe) {
    IEcoMemoryAllocator1* pIMem = 0;
    if (pCMe != 0) {
        pIMem = pCMe->m_pIMem;
        if (pCMe->m_Name != 0) pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        if (pCMe->m_pISys != 0) pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        if (pIMem != 0) {
            pIMem->pVTbl->Free(pIMem, pCMe);
            pIMem->pVTbl->Release(pIMem);
        }
    }
}

/* –‡Ò¯ËÂÌÌ‡ˇ ‚ËÚÛ‡Î¸Ì‡ˇ Ú‡·ÎËˆ‡ (7 ÏÂÚÓ‰Ó‚) */
IEcoASNOnePER1VTblExt g_x9750A8863A3447F7B27FDA947F903361VTbl_F509D9E8 = {
    CEcoASNOnePER1_F509D9E8_QueryInterface,
    CEcoASNOnePER1_F509D9E8_AddRef,
    CEcoASNOnePER1_F509D9E8_Release,
    CEcoASNOnePER1_F509D9E8_MyFunction,
    EncodePersonnelRecord,
    DecodePersonnelRecord,
    FreePersonnelRecord
};

/* Object Instance */
CEcoASNOnePER1_F509D9E8 g_xCEcoASNOnePER1_F509D9E8 = {
    &g_x9750A8863A3447F7B27FDA947F903361VTbl_F509D9E8,
    initCEcoASNOnePER1_F509D9E8,
    createCEcoASNOnePER1_F509D9E8,
    deleteCEcoASNOnePER1_F509D9E8,
    1,
    0,
    0,
    0
};