
#include "raylib.h"
#include <stdbool.h>

#define MAP_WIDTH 15
#define MAP_HEIGHT 10
#define TILE_SIZE 40

// Mapa simple: 0=camino, 1=pared, 2=punto para comer
int map[MAP_HEIGHT][MAP_WIDTH] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,2,2,1,2,2,2,2,2,1,2,2,2,1},
    {1,2,1,2,1,2,1,1,1,2,1,2,1,2,1},
    {1,2,1,2,2,2,2,1,2,2,2,2,1,2,1},
    {1,2,1,1,1,1,2,1,2,1,1,1,1,2,1},
    {1,2,2,2,2,2,2,1,2,2,2,2,2,2,1},
    {1,2,1,1,1,1,1,1,1,1,1,1,1,2,1},
    {1,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

typedef struct {
    int x;
    int y;
} Vector2i;

int main(void) {
    const int screenWidth = MAP_WIDTH * TILE_SIZE;
    const int screenHeight = MAP_HEIGHT * TILE_SIZE;

    InitWindow(screenWidth, screenHeight, "Pacman en C - sonido opcional");

    // Cargar sonidos (si existen)
    Sound eatSound = {0};
    bool soundAvailable = false;
    if (FileExists("resources/eat.wav")) {
        eatSound = LoadSound("resources/eat.wav");
        soundAvailable = true;
    }

    Vector2i pacmanPos = {1, 1};
    int score = 0;

    SetTargetFPS(10);

    while (!WindowShouldClose()) {
        // Movimiento con teclas
        Vector2i nextPos = pacmanPos;
        if (IsKeyPressed(KEY_UP)) nextPos.y--;
        if (IsKeyPressed(KEY_DOWN)) nextPos.y++;
        if (IsKeyPressed(KEY_LEFT)) nextPos.x--;
        if (IsKeyPressed(KEY_RIGHT)) nextPos.x++;

        // Verificar colisión con pared
        if (nextPos.x >= 0 && nextPos.x < MAP_WIDTH &&
            nextPos.y >= 0 && nextPos.y < MAP_HEIGHT &&
            map[nextPos.y][nextPos.x] != 1) {
            pacmanPos = nextPos;
        }

        // Comer punto
        if (map[pacmanPos.y][pacmanPos.x] == 2) {
            map[pacmanPos.y][pacmanPos.x] = 0;
            score++;
            if (soundAvailable) PlaySound(eatSound);
        }

        BeginDrawing();
        ClearBackground(BLACK);

        // Dibujar mapa
        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                Rectangle tile = { x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE };
                if (map[y][x] == 1) DrawRectangleRec(tile, BLUE);          // Pared
                else if (map[y][x] == 2) DrawCircle(x * TILE_SIZE + TILE_SIZE/2, y * TILE_SIZE + TILE_SIZE/2, 5, YELLOW); // Punto
                else DrawRectangleRec(tile, BLACK);
            }
        }

        // Dibujar Pacman (círculo amarillo)
        DrawCircle(pacmanPos.x * TILE_SIZE + TILE_SIZE/2, pacmanPos.y * TILE_SIZE + TILE_SIZE/2, TILE_SIZE/2 - 5, YELLOW);

        DrawText(TextFormat("Puntaje: %d", score), 10, 10, 20, WHITE);

        EndDrawing();
    }

    if (soundAvailable) UnloadSound(eatSound);

    CloseWindow();

    return 0;
}


// Referencia
// OpenAI. (2025, mayo 24). Compilar y distribuir programas de Raylib en Windows 
// usando MSYS2 UCRT64 [ChatGPT]. ChatGPT. 
// https://chatgpt.com/share/6831f399-7888-8013-91da-24df84e0d612

// chmod +x build_and_package.sh

// ./build_and_package.sh archivo.c
// ./build_and_package.sh archivo.cc
//  ./build_and_package.sh archivo.cpp
//  ./build_and_package.sh archivo
