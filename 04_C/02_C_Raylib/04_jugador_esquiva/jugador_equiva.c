
#include "raylib.h"
#include <stdlib.h>
#include <time.h>

#define NUM_OBSTACULOS 10

typedef struct Obstacle {
    Rectangle rect;
    float speed;
} Obstacle;

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Raylib C - Esquivar obstáculos");

    Rectangle jugador = { 50, screenHeight/2 - 25, 30, 30 };
    Obstacle obstaculos[NUM_OBSTACULOS];

    srand(time(NULL));

    for (int i = 0; i < NUM_OBSTACULOS; i++) {
        obstaculos[i].rect.x = 800 + rand() % 400;
        obstaculos[i].rect.y = rand() % (screenHeight - 20);
        obstaculos[i].rect.width = 20;
        obstaculos[i].rect.height = 20;
        obstaculos[i].speed = 200 + rand() % 200;
    }

    int puntos = 0;
    int gameOver = 0;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        if (!gameOver) {
            if (IsKeyDown(KEY_UP)) jugador.y -= 5;
            if (IsKeyDown(KEY_DOWN)) jugador.y += 5;

            for (int i = 0; i < NUM_OBSTACULOS; i++) {
                obstaculos[i].rect.x -= obstaculos[i].speed * GetFrameTime();

                if (CheckCollisionRecs(jugador, obstaculos[i].rect)) {
                    gameOver = 1;
                }

                if (obstaculos[i].rect.x < -20) {
                    obstaculos[i].rect.x = 800 + rand() % 400;
                    obstaculos[i].rect.y = rand() % (screenHeight - 20);
                    puntos++;
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (gameOver) {
            DrawText("¡Game Over!", 300, 200, 40, RED);
            DrawText("Presiona R para reiniciar", 270, 250, 20, GRAY);
            if (IsKeyPressed(KEY_R)) {
                jugador.y = screenHeight/2 - 25;
                gameOver = 0;
                puntos = 0;
                for (int i = 0; i < NUM_OBSTACULOS; i++) {
                    obstaculos[i].rect.x = 800 + rand() % 400;
                    obstaculos[i].rect.y = rand() % (screenHeight - 20);
                }
            }
        } else {
            DrawRectangleRec(jugador, BLUE);
            for (int i = 0; i < NUM_OBSTACULOS; i++) {
                DrawRectangleRec(obstaculos[i].rect, RED);
            }
            DrawText(TextFormat("Puntos: %d", puntos), 10, 10, 20, DARKGRAY);
        }

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
