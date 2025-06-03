#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>

void mostrarProcesos() {
    HANDLE hSnapshot;
    PROCESSENTRY32 pe;
    system("cls"); // Limpiar pantalla

    hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        printf("Error al obtener snapshot de procesos.\n");
        return;
    }

    pe.dwSize = sizeof(PROCESSENTRY32);
    if (Process32First(hSnapshot, &pe)) {
        printf("%-6s %-30s\n", "PID", "Nombre del Proceso");
        printf("=========================================\n");
        do {
            printf("%-6lu %-30s\n", pe.th32ProcessID, pe.szExeFile);
        } while (Process32Next(hSnapshot, &pe));
    } else {
        printf("Error al listar procesos.\n");
    }

    CloseHandle(hSnapshot);
}

int main() {
    while (1) {
        mostrarProcesos();
        Sleep(2000); // 2 segundos
    }
    return 0;
}


// OpenAI. (2025, abril 28). Creación de un programa tipo "touch" para consola CMD
// de Windows en C y C++ compilado con MinGW64 (UCRT64). ChatGPT. 
// https://chatgpt.com/share/680f753d-df38-8013-9f6a-e662a9b9cda6

// gcc top.c -o top.exe -lpsapi

