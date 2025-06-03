
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Si no se pasan archivos como argumento, muestra un mensaje de uso.
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <archivo1> <archivo2> ...\n", argv[0]);
        return 1;
    }
    // Recorre todos los archivos pasados como argumentos.
    for (int i = 1; i < argc; i++) {
        FILE *archivo = fopen(argv[i], "r");
        if (archivo == NULL) {
            perror("Error al abrir el archivo");
            continue;  // Si no se puede abrir el archivo, pasa al siguiente.
        }
        printf("Contenido de %s:\n", argv[i]);
        char c;
        while ((c = fgetc(archivo)) != EOF) {
            putchar(c);
        }
        fclose(archivo);
        printf("\n\n");
    }
    return 0;
}

// REFERENCIA
// OpenAI. (2025, abril 9). Cómo hacer y compilar en MinGW64 
// un programa como el CAT de Linux para que corra en el 
// Terminal de Windows CMD. ChatGPT. 
// https://chatgpt.com/share/67f6b4cb-0b00-800a-a1e4-4c80ddc8453d												//  gcc cat.c -o cat.exe
//
//  cat.exe archivo.txt
//  cat.exe archivo_1.txt archivo_2.txt
//
