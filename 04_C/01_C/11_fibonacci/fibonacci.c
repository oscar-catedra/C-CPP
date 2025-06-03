#include <stdio.h>

int main() {
    int n, i;
    unsigned long long int a = 0, b = 1, siguiente;

    printf("Ingrese el número de términos de la serie de Fibonacci: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Por favor, ingrese un número positivo.\n");
        return 1;
    }

    printf("Serie de Fibonacci:\n");

    for (i = 0; i < n; ++i) {
        printf("%llu ", a);
        siguiente = a + b;
        a = b;
        b = siguiente;
    }

    printf("\n");
    return 0;
}

// https://chatgpt.com/share/680fc0b7-c494-8013-b24e-232079c26345

// gcc fibonacci.c -o fibonacci.exe

