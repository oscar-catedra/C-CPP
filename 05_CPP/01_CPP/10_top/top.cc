
//top.cc

#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <iomanip>

using namespace std;

void mostrarProcesos() {
    HANDLE hSnapshot;
    PROCESSENTRY32 pe;
    system("cls"); // Limpiar pantalla

    hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        cout << "Error al obtener snapshot de procesos." << endl;
        return;
    }

    pe.dwSize = sizeof(PROCESSENTRY32);
    if (Process32First(hSnapshot, &pe)) {
        cout << left << setw(6) << "PID" << " " << setw(30) << "Nombre del Proceso" << endl;
        cout << "=========================================" << endl;
        do {
            cout << left << setw(6) << pe.th32ProcessID << " " << setw(30) << pe.szExeFile << endl;
        } while (Process32Next(hSnapshot, &pe));
    } else {
        cout << "Error al listar procesos." << endl;
    }

    CloseHandle(hSnapshot);
}

int main() {
    while (true) {
        mostrarProcesos();
        Sleep(2000); // 2 segundos
    }
    return 0;
}


// OpenAI. (2025, abril 28). Creación de un programa tipo "touch" para consola CMD de 
// Windows en C y C++ compilado con MinGW64 (UCRT64). ChatGPT.
// https://chatgpt.com/share/680f753d-df38-8013-9f6a-e662a9b9cda6

// g++ top.cc -o top.exe -lpsapi

