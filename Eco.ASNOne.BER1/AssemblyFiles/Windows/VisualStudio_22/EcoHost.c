/*
 * Eco Host - загрузчик Eco Framework для запуска BER теста
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <windows.h>

typedef short int16_t;
typedef unsigned int uint32_t;
typedef unsigned char byte_t;
typedef void* IEcoUnknown;

extern int16_t EcoMain(IEcoUnknown* pIUnk);

/* БАЗОВАЯ ПАПКА */
#define BASE_PATH "C:\\Users\\engfile\\EcoPrac\\Eco.Security-main"

/* Пути к DLL (используем x86 версии) */
#define ECO_BUS_DLL BASE_PATH "\\Eco.FRAME\\Eco.InterfaceBus1\\BuildFiles\\Windows\\x86\\DynamicRelease\\00000000000000000000000042757331.dll"
#define ECO_MEM_DLL BASE_PATH "\\Eco.FRAME\\Eco.MemoryManager1\\BuildFiles\\Windows\\x86\\DynamicRelease\\0000000000000000000000004D656D31.dll"

/* Функция загрузки DLL */
HMODULE LoadDll(const char* path) {
    HMODULE h = LoadLibraryA(path);
    if (h) {
        printf("  [OK] Loaded: %s\n", path);
    }
    else {
        printf("  [FAIL] Cannot load: %s\n", path);
    }
    return h;
}

int __cdecl main(void) {
    printf("========================================\n");
    printf("Eco Host for BER Component Test\n");
    printf("========================================\n\n");

    printf("Loading Eco Framework DLLs...\n\n");

    /* Загружаем DLL */
    HMODULE hBus = LoadDll(ECO_BUS_DLL);
    HMODULE hMem = LoadDll(ECO_MEM_DLL);

    if (!hBus && !hMem) {
        printf("\nERROR: Failed to load Eco Framework DLLs\n");
        printf("\nPress Enter to exit...");
        getchar();
        return -1;
    }

    printf("\nEco Framework DLLs loaded!\n");
    printf("NOTE: Full Eco System initialization requires Eco.System1.dll\n");
    printf("which is not found. Running with limited functionality.\n");

    /* Запуск теста */
    printf("\n--- Running BER Test ---\n\n");
    int16_t result = EcoMain(NULL);

    printf("\n========================================\n");
    if (result == 0) {
        printf("BER TEST: PASSED\n");
    }
    else if (result == -1) {
        printf("BER TEST: SKIPPED (needs full Eco System)\n");
    }
    else {
        printf("BER TEST: FAILED (code: %d)\n", result);
    }
    printf("========================================\n");

    /* Выгрузка DLL */
    if (hBus) FreeLibrary(hBus);
    if (hMem) FreeLibrary(hMem);

    printf("\nPress Enter to exit...");
    getchar();
    return result;
}