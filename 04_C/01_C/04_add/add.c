// add.c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <nombre_archivo> <texto_a_agregar>\n", argv[0]);
        return 1;
    }

    FILE *archivo = fopen(argv[1], "a"); // "a" = abrir para añadir (crear si no existe)
    if (archivo == NULL) {
        perror("Error al abrir o crear el archivo");
        return 1;
    }

    // Agregar todos los argumentos después del nombre del archivo
    for (int i = 2; i < argc; ++i) {
        fprintf(archivo, "%s", argv[i]);
        if (i < argc - 1) {
            fputc(' ', archivo); // Añadir espacio entre palabras
        }
    }
    fputc('\n', archivo); // Agregar salto de línea al final

    fclose(archivo);
    printf("Texto agregado correctamente.\n");
    return 0;
}
// https://chatgpt.com/share/68101692-58b4-8013-a8e9-9a3f6595a086

// gcc -o add add.c

// add.exe nombre_del_archivo.txt Texto que quiero agregar




