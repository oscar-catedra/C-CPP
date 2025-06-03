
// jugar_esquivar.cpp

#include "raylib.h"
#include <vector>
#include <cstdlib>
#include <ctime>

struct Obstacle {
    Rectangle rect;
    float speed;
};

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Raylib C++ - Esquivar obstáculos");

    Rectangle jugador = { 50, screenHeight / 2.0f - 25, 30, 30 };
    std::vector<Obstacle> obstaculos;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < 10; ++i) {
        Obstacle o;
        o.rect.x = 800 + std::rand() % 400;
        o.rect.y = std::rand() % (screenHeight - 20);
        o.rect.width = 20;
        o.rect.height = 20;
        o.speed = 200 + std::rand() % 200;
        obstaculos.push_back(o);
    }

    int puntos = 0;
    bool gameOver = false;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        if (!gameOver) {
            if (IsKeyDown(KEY_UP)) jugador.y -= 5;
            if (IsKeyDown(KEY_DOWN)) jugador.y += 5;

            for (auto& o : obstaculos) {
                o.rect.x -= o.speed * GetFrameTime();

                if (CheckCollisionRecs(jugador, o.rect)) {
                    gameOver = true;
                }

                if (o.rect.x < -20) {
                    o.rect.x = 800 + std::rand() % 400;
                    o.rect.y = std::rand() % (screenHeight - 20);
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
                jugador.y = screenHeight / 2.0f - 25;
                gameOver = false;
                puntos = 0;
                for (auto& o : obstaculos) {
                    o.rect.x = 800 + std::rand() % 400;
                    o.rect.y = std::rand() % (screenHeight - 20);
                }
            }
        } else {
            DrawRectangleRec(jugador, BLUE);
            for (const auto& o : obstaculos) {
                DrawRectangleRec(o.rect, RED);
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
