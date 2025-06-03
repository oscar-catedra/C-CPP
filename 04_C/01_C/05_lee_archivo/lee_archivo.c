
#include <stdio.h>

int main() {
    FILE *file;
    char line[256];
    int line_count = 0;

    // Abrir archivo para lectura
    file = fopen("archivo.txt", "r");
    if (file == NULL) {
        perror("No se puede abrir el archivo");
        return 1;
    }

    // Leer cada línea del archivo y contar las líneas
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("Línea %d: %s", ++line_count, line);
    }

    printf("\nTotal de líneas: %d\n", line_count);

    // Cerrar archivo
    fclose(file);
    return 0;
}

// REFERENCIA
// https://chatgpt.com/share/67f6b4cb-0b00-800a-a1e4-4c80ddc8453d
//
// gcc lee_archivo.c -o lee_archivo.exe
//

/*

   Diferencias clave entre C y C++ en estos ejemplos 
Manejo de Archivos:

C usa FILE * y funciones de la biblioteca estándar como fopen(), fgets(), y fclose().

C++ usa fstream que está más orientado a objetos y proporciona métodos como open(), getline() y close().

Clases y Objetos:

En C, se utilizan estructuras (struct) para agrupar datos, pero no hay soporte directo para funciones asociadas a estas estructuras.

En C++, se utiliza una clase (class), que incluye tanto los datos como las funciones (métodos) asociadas a esos datos, lo que facilita el encapsulamiento y la manipulación.

Sintaxis de Entrada y Salida:

En C, se usan funciones estándar como printf y scanf.

En C++, se utilizan los flujos de entrada y salida std::cout y std::cin, que son más fáciles de usar y más seguros, además de ser más flexibles.

*/
