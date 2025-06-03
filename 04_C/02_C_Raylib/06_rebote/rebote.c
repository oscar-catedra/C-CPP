
#include "raylib.h"
#include <math.h>  // Para usar fabsf

// Comentario educativo:
// En C, no hay clases ni objetos, por lo que usamos structs y funciones aparte.

typedef struct {
    Vector2 position;
    Vector2 speed;
    float radius;
    Color color;
} Ball;

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "C - Rebote con colisiones físicas");
    SetTargetFPS(60);

    Ball ball = { { screenWidth / 2, screenHeight / 2 }, { 4, 3 }, 20, RED };

    while (!WindowShouldClose()) {
        // Movimiento
        ball.position.x += ball.speed.x;
        ball.position.y += ball.speed.y;

        // Colisiones con bordes
        if ((ball.position.x - ball.radius <= 0) || (ball.position.x + ball.radius >= screenWidth)) {
            ball.speed.x *= -1;
        }
        if ((ball.position.y - ball.radius <= 0) || (ball.position.y + ball.radius >= screenHeight)) {
            ball.speed.y *= -1;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Pelota rebotando (C)", 10, 10, 20, DARKGRAY);
            DrawCircleV(ball.position, ball.radius, ball.color);
        EndDrawing();
    }

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
