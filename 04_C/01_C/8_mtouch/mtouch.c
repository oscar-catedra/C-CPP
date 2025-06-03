#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s archivo1 [archivo2 ... archivoN]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        FILE *fp = fopen(argv[i], "ab"); // modo append binario
        if (fp == NULL) {
            perror(argv[i]);
            continue;
        }
        fclose(fp);
    }

    return 0;
}
// OpenAI. (2025, abril 28). Creación de un programa tipo "touch" 
// para consola CMD de Windows en C y C++ compilado con MinGW64 (UCRT64). ChatGPT.
// https://chatgpt.com/share/680f753d-df38-8013-9f6a-e662a9b9cda6

// gcc mtouch.c -o mtouch.exe

// mtouch archivo1 archivo2 archivo3

