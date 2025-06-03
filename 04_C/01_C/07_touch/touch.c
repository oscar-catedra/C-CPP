#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;

    if (argc != 2) {
        printf("Uso: %s nombre_archivo\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "ab"); // abrir en modo append binario
    if (fp == NULL) {
        perror("Error al abrir/crear el archivo");
        return 1;
    }

    fclose(fp);
    return 0;
}
// OpenAI. (2025, abril 28). Creación de un programa tipo "touch" 
// para consola CMD de Windows en C y C++ compilado con MinGW64 (UCRT64). 
// ChatGPT. https://chatgpt.com/share/680f753d-df38-8013-9f6a-e662a9b9cda6

//  gcc touch.c -o touch.exe


