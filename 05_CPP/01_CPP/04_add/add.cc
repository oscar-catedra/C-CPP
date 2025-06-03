#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cout << "Uso: " << argv[0] << " <nombre_archivo> <texto_a_agregar>\n";
        return 1;
    }

    std::ofstream archivo(argv[1], std::ios::app); // modo append (añadir al final)
    if (!archivo) {
        std::cerr << "Error al abrir o crear el archivo.\n";
        return 1;
    }

    // Agregar todos los argumentos después del nombre del archivo
    for (int i = 2; i < argc; ++i) {
        archivo << argv[i];
        if (i < argc - 1) {
            archivo << ' ';
        }
    }
    archivo << '\n'; // Salto de línea al final

    archivo.close();
    std::cout << "Texto agregado correctamente.\n";
    return 0;
}

// https://chatgpt.com/share/68101692-58b4-8013-a8e9-9a3f6595a086

// g++ -o add.exe add.cc

// add.exe miarchivo.txt Este es el texto que quiero agregar

