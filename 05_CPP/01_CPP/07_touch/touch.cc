#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " nombre_archivo" << endl;
        return 1;
    }

    ofstream archivo(argv[1], ios::app | ios::binary);
    if (!archivo) {
        cerr << "Error al abrir/crear el archivo" << endl;
        return 1;
    }

    archivo.close();
    return 0;
}

// OpenAI. (2025, abril 28). Creación de un programa tipo "touch" para consola CMD
// de Windows en C y C++ compilado con MinGW64 (UCRT64). ChatGPT.
// https://chatgpt.com/share/680f753d-df38-8013-9f6a-e662a9b9cda6

// g++ touch.cc -o touch.exe
