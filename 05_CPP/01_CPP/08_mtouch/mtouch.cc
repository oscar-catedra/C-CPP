
// mtouch.cc

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Uso: " << argv[0] << " archivo1 [archivo2 ... archivoN]" << endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        ofstream archivo(argv[i], ios::app | ios::binary);
        if (!archivo) {
            cerr << "Error al abrir/crear " << argv[i] << endl;
            continue;
        }
        archivo.close();
    }

    return 0;
}

// g++ mtouch.cc -o mtouch.exe


// OpenAI. (2025, abril 28). Creación de un programa tipo "touch" para consola CMD
// de Windows en C y C++ compilado con MinGW64 (UCRT64). ChatGPT.
// https://chatgpt.com/share/680f753d-df38-8013-9f6a-e662a9b9cda6



