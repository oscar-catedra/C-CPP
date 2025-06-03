
#include <iostream>
#include <string>
class Estudiante {
private:
    std::string nombre;
    int edad;
    float calificacion;
public:
    // Constructor
    Estudiante(std::string n, int e, float c) : nombre(n), edad(e), calificacion(c) {}

    // Métodos
    void mostrarInfo() const {
        std::cout << "Nombre: " << nombre << "\nEdad: " << edad << "\nCalificación: " << calificacion << std::endl;
    }
    void actualizarCalificacion(float nuevaCalificacion) {
        calificacion = nuevaCalificacion;
    }
    float obtenerCalificacion() const {
        return calificacion;
    }
};
int main() {
    Estudiante est1("Juan", 20, 85.5);
    Estudiante est2("Maria", 22, 90.0);
    std::cout << "Estudiante 1:" << std::endl;
    est1.mostrarInfo();
    std::cout << "\nEstudiante 2:" << std::endl;
    est2.mostrarInfo();
    // Actualizar calificación
    est1.actualizarCalificacion(88.0);
    std::cout << "\nActualización de calificación para Juan:" << std::endl;
    std::cout << "Nueva calificación: " << est1.obtenerCalificacion() << std::endl;
    return 0;
}


// REFERENCIA
// https://chatgpt.com/share/67f6b4cb-0b00-800a-a1e4-4c80ddc8453d
//
// g++ estudiante.cc -o estudiante.exe
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
