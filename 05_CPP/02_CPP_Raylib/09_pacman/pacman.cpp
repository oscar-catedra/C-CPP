
// pacman.cpp

#include "raylib.h"
#include <vector>
#include <string>
#include <cmath>
#include <filesystem>
#include <iostream>

#define CELL_SIZE 32
#define MAP_WIDTH 20
#define MAP_HEIGHT 13

// Mapa del laberinto: 0 = punto, 1 = pared, 2 = punto ya comido
int map[MAP_HEIGHT][MAP_WIDTH] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1},
    {1,0,1,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1},
    {1,0,1,0,1,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1},
    {1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1},
    {1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
    {1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1},
    {1,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1},
    {1,0,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

bool soundEnabled = true;

bool FileExists(const std::string& name) {
    return std::filesystem::exists(name);
}

// Clase Pacman
class Pacman {
public:
    Vector2 position;
    Vector2 direction;
    Sound eatSound;
    bool hasSound = false;

    Pacman(float x, float y) {
        position = { x, y };
        direction = { 0, 0 };
    }

    void LoadSounds() {
        if (soundEnabled && FileExists("eat.wav")) {
            eatSound = LoadSound("eat.wav");
            hasSound = true;
        }
    }

    void Update() {
        Vector2 next = {
            position.x + direction.x * CELL_SIZE,
            position.y + direction.y * CELL_SIZE
        };

        int col = (int)(next.x / CELL_SIZE);
        int row = (int)(next.y / CELL_SIZE);

        if (row >= 0 && row < MAP_HEIGHT && col >= 0 && col < MAP_WIDTH && map[row][col] != 1) {
            position = next;

            // Comer punto si hay
            if (map[row][col] == 0) {
                map[row][col] = 2;
                if (soundEnabled && hasSound) {
                    PlaySound(eatSound);
                }
            }
        }
    }

    void Draw() {
        DrawCircleV(position, 12, YELLOW);
    }

    void Unload() {
        if (soundEnabled && hasSound) UnloadSound(eatSound);
    }
};

// Dibuja el mapa
void DrawMap() {
    for (int row = 0; row < MAP_HEIGHT; row++) {
        for (int col = 0; col < MAP_WIDTH; col++) {
            int x = col * CELL_SIZE;
            int y = row * CELL_SIZE;

            if (map[row][col] == 1)
                DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, BLUE);
            else if (map[row][col] == 0)
                DrawCircle(x + CELL_SIZE / 2, y + CELL_SIZE / 2, 4, WHITE);
        }
    }
}

int main() {
    InitWindow(MAP_WIDTH * CELL_SIZE, MAP_HEIGHT * CELL_SIZE, "Pacman Simplificado");
    InitAudioDevice();

    Pacman pacman(1 * CELL_SIZE + CELL_SIZE / 2, 1 * CELL_SIZE + CELL_SIZE / 2);
    pacman.LoadSounds();

    SetTargetFPS(10);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_UP)) pacman.direction = { 0, -1 };
        if (IsKeyPressed(KEY_DOWN)) pacman.direction = { 0, 1 };
        if (IsKeyPressed(KEY_LEFT)) pacman.direction = { -1, 0 };
        if (IsKeyPressed(KEY_RIGHT)) pacman.direction = { 1, 0 };

        pacman.Update();

        BeginDrawing();
        ClearBackground(BLACK);
        DrawMap();
        pacman.Draw();
        EndDrawing();
    }

    pacman.Unload();
    CloseAudioDevice();
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

