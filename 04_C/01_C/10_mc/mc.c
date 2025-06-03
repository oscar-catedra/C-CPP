// mini_commander.c
// Un "mini Midnight Commander" en C para CMD de Windows

#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define MAX_FILES 100
#define MAX_NAME 260

char files[MAX_FILES][MAX_NAME];
int file_count = 0;
int selected = 0;

void list_files(const char *path) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    char dirSpec[MAX_NAME];

    snprintf(dirSpec, MAX_NAME, "%s\\*", path);

    hFind = FindFirstFile(dirSpec, &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("No se pudo abrir el directorio.\n");
        return;
    }

    do {
        if (file_count < MAX_FILES) {
            snprintf(files[file_count], MAX_NAME, "%s", findFileData.cFileName);
            file_count++;
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}

void draw() {
    system("cls");
    printf("Mini Commander - Directorio Actual\n");
    printf("(Usa las flechas Arriba/Abajo y ESC para salir)\n\n");

    for (int i = 0; i < file_count; i++) {
        if (i == selected) {
            printf("--> %s\n", files[i]);
        } else {
            printf("    %s\n", files[i]);
        }
    }
}

int main() {
    list_files(".");

    draw();

    while (1) {
        int ch = _getch();
        if (ch == 224) { // Tecla especial
            ch = _getch();
            if (ch == 72) { // Flecha arriba
                if (selected > 0) selected--;
            } else if (ch == 80) { // Flecha abajo
                if (selected < file_count - 1) selected++;
            }
        } else if (ch == 27) { // ESC
            break;
        }

        draw();
    }

    printf("\nSaliendo...\n");
    return 0;
}

// gcc mc.c -o mc.exe