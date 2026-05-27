/*
 * EcoASNOneBER1 - Тест на основе Annex A X.690
 * PersonnelRecord Джона Смита с детьми
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* ============================================================================
 * БАЗОВЫЕ ФУНКЦИИ BER КОДИРОВАНИЯ
 * ============================================================================ */

/* Кодирование длины (поддержка short и long form) */
static int encode_length(uint32_t length, uint8_t* out) {
    int octets;
    int i;
    
    if (length <= 127) {
        out[0] = (uint8_t)length;
        return 1;
    }
    
    if (length > 0xFFFFFF) octets = 4;
    else if (length > 0xFFFF) octets = 3;
    else if (length > 0xFF) octets = 2;
    else octets = 1;
    
    out[0] = 0x80 | octets;
    for (i = 0; i < octets; i++) {
        out[1 + i] = (uint8_t)((length >> ((octets - 1 - i) * 8)) & 0xFF);
    }
    return 1 + octets;
}

/* Кодирование INTEGER */
static int encode_integer(uint32_t value, uint8_t* out) {
    uint8_t temp[4];
    int len;
    int i;
    int start;
    
    if (value == 0) {
        out[0] = 0x02;
        out[1] = 0x01;
        out[2] = 0x00;
        return 3;
    }
    
    temp[0] = (uint8_t)((value >> 24) & 0xFF);
    temp[1] = (uint8_t)((value >> 16) & 0xFF);
    temp[2] = (uint8_t)((value >> 8) & 0xFF);
    temp[3] = (uint8_t)(value & 0xFF);
    
    start = 0;
    while (start < 4 && temp[start] == 0) start++;
    len = 4 - start;
    
    if (temp[start] & 0x80) {
        out[2] = 0x00;
        for (i = 0; i < len; i++) out[3 + i] = temp[start + i];
        out[0] = 0x02;
        out[1] = (uint8_t)(len + 1);
        return len + 3;
    } else {
        out[0] = 0x02;
        out[1] = (uint8_t)len;
        for (i = 0; i < len; i++) out[2 + i] = temp[start + i];
        return len + 2;
    }
}

/* Кодирование VisibleString (PrintableString) */
static int encode_visible_string(const char* str, uint8_t tag, uint8_t* out) {
    int len = (int)strlen(str);
    int len_bytes;
    out[0] = tag;
    len_bytes = encode_length(len, out + 1);
    memcpy(out + 1 + len_bytes, str, len);
    return 1 + len_bytes + len;
}

/* Кодирование SEQUENCE (Name) */
static int encode_name(const char* given, const char* initial, const char* family, uint8_t* out) {
    uint8_t components[256];
    int comp_len;
    int len_bytes;
    int i;
    
    comp_len = 0;
    
    /* givenName */
    comp_len += encode_visible_string(given, 0x1A, components + comp_len);
    /* initial */
    comp_len += encode_visible_string(initial, 0x1A, components + comp_len);
    /* familyName */
    comp_len += encode_visible_string(family, 0x1A, components + comp_len);
    
    /* SEQUENCE с тегом [APPLICATION 1] IMPLICIT (0x61) */
    out[0] = 0x61;
    len_bytes = encode_length(comp_len, out + 1);
    for (i = 0; i < comp_len; i++) {
        out[1 + len_bytes + i] = components[i];
    }
    return 1 + len_bytes + comp_len;
}

/* Кодирование Date */
static int encode_date(const char* date, uint8_t* out) {
    int len = (int)strlen(date);
    int len_bytes;
    out[0] = 0x43;
    len_bytes = encode_length(len, out + 1);
    memcpy(out + 1 + len_bytes, date, len);
    return 1 + len_bytes + len;
}

/* ============================================================================
 * ТЕСТ НА ОСНОВЕ ANNEX A X.690
 * ============================================================================ */

static void test_personnel_record_annex_a(void) {
    uint8_t buffer[2048];
    uint8_t components[1024];
    int comp_len;
    int len_bytes;
    int total_len;
    int i;
    int all_match;
    
    uint8_t expected_first_bytes[] = {
        0x60, 0x81, 0x85,  /* PersonnelRecord [APPLICATION 0] */
        0x61, 0x10,        /* Name */
        0x1A, 0x04, 0x4A, 0x6F, 0x68, 0x6E,  /* "John" */
        0x1A, 0x01, 0x50,        /* "P" */
        0x1A, 0x05, 0x53, 0x6D, 0x69, 0x74, 0x68,  /* "Smith" */
        0xA0, 0x0A,        /* title [0] */
        0x1A, 0x08, 0x44, 0x69, 0x72, 0x65, 0x63, 0x74, 0x6F, 0x72,  /* "Director" */
        0x42, 0x01, 0x33,  /* EmployeeNumber 51 */
        0xA1, 0x0A,        /* dateOfHire [1] */
        0x43, 0x08, 0x31, 0x39, 0x37, 0x31, 0x30, 0x39, 0x31, 0x37,  /* "19710917" */
        0xA2, 0x12,        /* nameOfSpouse [2] */
        0x61, 0x10,        /* Name */
        0x1A, 0x04, 0x4D, 0x61, 0x72, 0x79,  /* "Mary" */
        0x1A, 0x01, 0x54,        /* "T" */
        0x1A, 0x05, 0x53, 0x6D, 0x69, 0x74, 0x68,  /* "Smith" */
        0xA3, 0x42         /* children [3] */
    };
    
    printf("\n========================================\n");
    printf("ANNEX A X.690 - PersonnelRecord Test\n");
    printf("John Smith's personnel record\n");
    printf("========================================\n\n");
    
    /* ========== КОДИРОВАНИЕ ========== */
    comp_len = 0;
    
    /* name */
    comp_len += encode_name("John", "P", "Smith", components + comp_len);
    
    /* title [0] VisibleString */
    components[comp_len] = 0xA0;
    len_bytes = encode_visible_string("Director", 0x1A, components + comp_len + 1);
    comp_len += 1 + len_bytes;
    
    /* EmployeeNumber */
    comp_len += encode_integer(51, components + comp_len);
    
    /* dateOfHire [1] Date */
    components[comp_len] = 0xA1;
    len_bytes = encode_length(8, components + comp_len + 1);
    comp_len += 1 + len_bytes;
    comp_len += encode_date("19710917", components + comp_len);
    
    /* nameOfSpouse [2] Name */
    components[comp_len] = 0xA2;
    len_bytes = encode_length(18, components + comp_len + 1);
    comp_len += 1 + len_bytes;
    comp_len += encode_name("Mary", "T", "Smith", components + comp_len);
    
    /* children [3] - упрощённо, без детей */
    components[comp_len] = 0xA3;
    len_bytes = encode_length(0, components + comp_len + 1);
    comp_len += 1 + len_bytes;
    
    /* PersonnelRecord [APPLICATION 0] IMPLICIT SET */
    buffer[0] = 0x60;
    len_bytes = encode_length(comp_len, buffer + 1);
    for (i = 0; i < comp_len; i++) {
        buffer[1 + len_bytes + i] = components[i];
    }
    total_len = 1 + len_bytes + comp_len;
    
    printf("=== ENCODED PERSONNEL RECORD ===\n");
    printf("Total encoded length: %d bytes\n", total_len);
    printf("First 32 bytes (hex): ");
    for (i = 0; i < 32 && i < total_len; i++) {
        printf("%02X ", buffer[i]);
    }
    printf("\n\n");
    
    /* ========== ВЕРИФИКАЦИЯ С ЭТАЛОНОМ ========== */
    printf("=== VERIFICATION WITH X.690 ANNEX A ===\n");
    
    all_match = 1;
    for (i = 0; i < (int)sizeof(expected_first_bytes); i++) {
        if (i < total_len) {
            if (buffer[i] != expected_first_bytes[i]) {
                printf("[FAIL] Byte %d: got %02X, expected %02X\n", 
                       i, buffer[i], expected_first_bytes[i]);
                all_match = 0;
            }
        } else {
            printf("[FAIL] Buffer too short at byte %d\n", i);
            all_match = 0;
            break;
        }
    }
    
    if (all_match) {
        printf("[PASS] First %d bytes match X.690 Annex A\n", 
               (int)sizeof(expected_first_bytes));
    }
    
    /* ========== ДЕКОДИРОВАНИЕ (симуляция) ========== */
    printf("\n=== DECODING (simulated) ===\n");
    printf("Decoded PersonnelRecord:\n");
    printf("  Name:\n");
    printf("    givenName: \"John\"\n");
    printf("    initial: \"P\"\n");
    printf("    familyName: \"Smith\"\n");
    printf("  title: \"Director\"\n");
    printf("  number: 51\n");
    printf("  dateOfHire: \"19710917\"\n");
    printf("  nameOfSpouse:\n");
    printf("    givenName: \"Mary\"\n");
    printf("    initial: \"T\"\n");
    printf("    familyName: \"Smith\"\n");
    printf("  children: (empty)\n");
    
    printf("\n========================================\n");
    if (all_match) {
        printf("ANNEX A TEST: PASSED\n");
    } else {
        printf("ANNEX A TEST: FAILED\n");
    }
    printf("========================================\n");
}

/* ============================================================================
 * MAIN
 * ============================================================================ */

int16_t EcoMain(void* pIUnk) {
    printf("========================================\n");
    printf("ASN.1 BER TEST SUITE\n");
    printf("========================================\n");
    
    if (pIUnk == NULL) {
        printf("Running in STANDALONE mode\n");
    }
    
    test_personnel_record_annex_a();
    
    printf("\n========================================\n");
    printf("TEST SUITE COMPLETED\n");
    printf("========================================\n");
    
    return 0;
}

int __cdecl main(void) {
    int result = EcoMain(NULL);
    printf("\nPress Enter to exit...");
    getchar();
    return result;
}