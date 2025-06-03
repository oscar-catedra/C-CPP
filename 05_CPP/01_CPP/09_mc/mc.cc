// mini_commander.cpp
// Un "mini Midnight Commander" en C++ para CMD de Windows

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>

class Commander {
private:
    std::vector<std::string> files;
    int selected = 0;

public:
    void listFiles(const std::string& path) {
        WIN32_FIND_DATA findFileData;
        HANDLE hFind = INVALID_HANDLE_VALUE;
        std::string dirSpec = path + "\\*";

        hFind = FindFirstFile(dirSpec.c_str(), &findFileData);
        if (hFind == INVALID_HANDLE_VALUE) {
            std::cout << "No se pudo abrir el directorio." << std::endl;
            return;
        }

        do {
            files.push_back(findFileData.cFileName);
        } while (FindNextFile(hFind, &findFileData) != 0);

        FindClose(hFind);
    }

    void draw() {
        system("cls");
        std::cout << "Mini Commander C++ - Directorio Actual" << std::endl;
        std::cout << "(Usa las flechas Arriba/Abajo y ESC para salir)\n" << std::endl;

        for (size_t i = 0; i < files.size(); ++i) {
            if ((int)i == selected) {
                std::cout << "--> " << files[i] << std::endl;
            } else {
                std::cout << "    " << files[i] << std::endl;
            }
        }
    }

    void run() {
        draw();
        while (true) {
            int ch = _getch();
            if (ch == 224) { // Tecla especial
                ch = _getch();
                if (ch == 72) { // Flecha arriba
                    if (selected > 0) selected--;
                } else if (ch == 80) { // Flecha abajo
                    if (selected < (int)files.size() - 1) selected++;
                }
            } else if (ch == 27) { // ESC
                break;
            }
            draw();
        }
        std::cout << "\nSaliendo..." << std::endl;
    }
};

int main() {
    Commander commander;
    commander.listFiles(".");
    commander.run();

    return 0;
}

// https://chatgpt.com/share/680f753d-df38-8013-9f6a-e662a9b9cda6

// g++ mc.cc -o mc.exe