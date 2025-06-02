#include <stdio.h>
#include <string.h>
struct Estudiante {
    char nombre[50];
    int edad;
    float calificacion;
};
void mostrarInfo(struct Estudiante est) {
    printf("Nombre: %s\nEdad: %d\nCalificación: %.2f\n", est.nombre, est.edad, est.calificacion);
}
void actualizarCalificacion(struct Estudiante *est, float nuevaCalificacion) {
    est->calificacion = nuevaCalificacion;
}
int main() {
    struct Estudiante est1 = {"Juan", 20, 85.5};
    struct Estudiante est2 = {"Maria", 22, 90.0};

    printf("Estudiante 1:\n");
    mostrarInfo(est1);

    printf("\nEstudiante 2:\n");
    mostrarInfo(est2);

    // Actualizar calificación
    actualizarCalificacion(&est1, 88.0);
    printf("\nActualización de calificación para Juan:\n");
    printf("Nueva calificación: %.2f\n", est1.calificacion);

    return 0;
}


// REFERENCIA
// https://chatgpt.com/share/67f6b4cb-0b00-800a-a1e4-4c80ddc8453d
//
// gcc estudiante.c -o estudiante.exe
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
