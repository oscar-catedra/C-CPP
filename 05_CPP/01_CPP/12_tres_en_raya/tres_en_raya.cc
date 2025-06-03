
// tres_en_raya.cc

#include <iostream>
using namespace std;
// Declaración de funciones
void mostrar_tablero(char tablero[3][3]);
int verificar_ganador(char tablero[3][3]);
int movimiento_valido(char tablero[3][3], int fila, int col);
void jugar();
int main() {
    jugar();
    return 0;
}
void jugar() {
    char tablero[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int turno = 0, fila, col, ganador = 0;
    char jugador = 'X';
    while (1) {
        mostrar_tablero(tablero);
        // Turno de jugador
        cout << "Jugador " << jugador << ", ingresa fila (1-3) y columna (1-3): ";
        cin >> fila >> col;
        fila--; col--; // Ajuste de índice para 0 basado
        if (movimiento_valido(tablero, fila, col)) {
            tablero[fila][col] = jugador;
            ganador = verificar_ganador(tablero);
            if (ganador != 0) {
                mostrar_tablero(tablero);
                cout << "¡El Jugador " << jugador << " ha ganado!" << endl;
                break;
            }
            // Cambiar de jugador
            jugador = (jugador == 'X') ? 'O' : 'X';
            turno++;
            if (turno == 9) {
                mostrar_tablero(tablero);
                cout << "Es un empate" << endl;
                break;
            }
        } else {
            cout << "Movimiento inválido, intenta de nuevo." << endl;
        }
    }
}
void mostrar_tablero(char tablero[3][3]) {
    cout << "\nTablero:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}
int verificar_ganador(char tablero[3][3]) {
    // Verificar filas y columnas
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2])
            return 1;
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i])
            return 1;
    }
    // Verificar diagonales
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
        return 1;
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
        return 1;
    return 0; // No hay ganador aún
}
int movimiento_valido(char tablero[3][3], int fila, int col) {
    if (fila < 0 || fila >= 3 || col < 0 || col >= 3)
        return 0; // Fuera de rango
    if (tablero[fila][col] == 'X' || tablero[fila][col] == 'O')
        return 0; // Casilla ocupada
    return 1;
}

/*
EXPLICACION
Tablero: El tablero se representa como una matriz de 3x3 
que contiene los números del 1 al 9 inicialmente.

Verificación de Ganador: Después de cada movimiento, se revisa 
si hay un ganador, verificando las filas, columnas y las dos diagonales.

Entrada del Usuario: Los jugadores ingresan las filas y columnas 
para colocar sus marcas (X u O).

Cambio de Turno: Después de cada movimiento válido, el programa 
cambia el turno entre los jugadores.
*/
// Jugador X, ingresa fila (1-3) y columna (1-3): 1 1
// Jugador O, ingresa fila (1-3) y columna (1-3): 2 2 
// Jugador X, ingresa fila (1-3) y columna (1-3): 1 2
// Jugador O, ingresa fila (1-3) y columna (1-3): 3 3

// REFERENCIA
// https://chatgpt.com/share/67f6b4cb-0b00-800a-a1e4-4c80ddc8453d

// g++ tres_en_raya.cc -o tres_en_raya.exe

