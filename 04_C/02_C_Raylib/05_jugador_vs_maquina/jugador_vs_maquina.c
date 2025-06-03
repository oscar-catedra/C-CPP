
#include "raylib.h"
#include <math.h>

typedef struct {
    Rectangle rect;
    Color color;
} Entity;

bool CheckCollision(Entity a, Entity b) {
    return CheckCollisionRecs(a.rect, b.rect);
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "C - Jugador vs Máquina");
    InitAudioDevice();  // Habilita audio

    Sound collisionSound = LoadSound("resources/collision.wav");

    Entity player = {{100, 200, 40, 40}, RED};
    Entity enemy  = {{600, 200, 40, 40}, BLUE};

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Movimiento jugador
        if (IsKeyDown(KEY_RIGHT)) player.rect.x += 5;
        if (IsKeyDown(KEY_LEFT))  player.rect.x -= 5;
        if (IsKeyDown(KEY_DOWN))  player.rect.y += 5;
        if (IsKeyDown(KEY_UP))    player.rect.y -= 5;

        // Movimiento máquina (enemigo)
        if (enemy.rect.x < player.rect.x) enemy.rect.x += 2;
        if (enemy.rect.x > player.rect.x) enemy.rect.x -= 2;
        if (enemy.rect.y < player.rect.y) enemy.rect.y += 2;
        if (enemy.rect.y > player.rect.y) enemy.rect.y -= 2;

        bool collided = CheckCollision(player, enemy);
        if (collided) PlaySound(collisionSound);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Jugador vs Maquina (C)", 10, 10, 20, DARKGRAY);
            DrawRectangleRec(player.rect, player.color);
            DrawRectangleRec(enemy.rect, enemy.color);
            if (collided) DrawText("¡Colisión!", 350, 200, 20, MAROON);
        EndDrawing();
    }

    UnloadSound(collisionSound);
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
