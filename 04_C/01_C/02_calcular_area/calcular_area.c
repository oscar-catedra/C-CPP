#include <stdio.h>
#define PI 3.14159

// Declaración de la función
float calcular_area(float radio);

int main() {
    float radio;
    printf("Introduce el radio del círculo: ");
    scanf("%f", &radio);

    // Llamada a la función
    float area = calcular_area(radio);
    
    printf("El área del círculo con radio %.2f es: %.2f\n", radio, area);

    return 0;
}

// Definición de la función
float calcular_area(float radio) {
    return PI * radio * radio;
}



/* EXPLICACION

Explicación de ambos programas. 

Función en C:

En C, la función calcular_area se declara antes de main() 
para indicarle al compilador que existirá una función con esa firma.

La función toma un parámetro de tipo float (el radio) y devuelve el área calculada.

La declaración #define PI 3.14159 se usa para definir el valor constante de π.

Función en C++:

En C++, la función calcular_area también toma un parámetro float y devuelve el área, 
pero se utiliza std::cin y std::cout para manejar la entrada y salida 
en lugar de scanf y printf.

Funciones en C++ permiten un estilo más limpio con los flujos de entrada y salida.

Diferencias clave entre C y C++ en este ejemplo:

En C, se utilizan funciones de la biblioteca estándar como scanf() y printf(), 
mientras que en C++ se prefiere usar los flujos de entrada y salida std::cin y std::cout, 
lo que hace que el código sea más limpio y seguro.

La definición de funciones es casi idéntica, pero el manejo de entrada y salida 
es más sencillo y orientado a objetos en C++.

*/

/*
Explicación de las modificaciones:
setlocale():

Usamos setlocale(LC_ALL, "spanish") en ambos programas para configurar la localización en español. 
Esto es importante porque permite que las funciones de entrada y salida (como printf o std::cout) 
manejen correctamente los caracteres especiales como ñ y los acentos.

Terminal con codificación UTF-8:

En Windows CMD, el terminal por defecto no usa UTF-8. 
Por lo tanto, es necesario cambiar la página de códigos a UTF-8 con el comando:

chcp 65001

*/


// REFERENCIA
// OpenAI. (2025, abril 9). Cómo hacer y compilar en MinGW64 
// un programa como el CAT de Linux para que corra en el 
// Terminal de Windows CMD [Chat]. ChatGPT.
// https://chatgpt.com/share/67f6b4cb-0b00-800a-a1e4-4c80ddc8453d
//
// gcc calcular_area.c -o calcular_area.exe
//