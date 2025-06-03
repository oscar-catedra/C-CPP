
// fibonacci.cc

#include <iostream>

int main() {
    int n;
    unsigned long long int a = 0, b = 1, siguiente;

    std::cout << "Ingrese el número de términos de la serie de Fibonacci: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Por favor, ingrese un número positivo.\n";
        return 1;
    }

    std::cout << "Serie de Fibonacci:\n";

    for (int i = 0; i < n; ++i) {
        std::cout << a << " ";
        siguiente = a + b;
        a = b;
        b = siguiente;
    }

    std::cout << std::endl;
    return 0;
}

//  https://chatgpt.com/share/680fc0b7-c494-8013-b24e-232079c26345

// g++ fibonacci.cc -o fibonacci.exe

