
// archivo: texto_animado.cpp

#include "raylib.h"
#include <string>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib C++ - Texto animado");

    float posX = 0.0f;
    float speed = 200.0f; // pixeles por segundo
    float fontSize = 20.0f;
    bool growing = true;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        posX += speed * deltaTime;
        if (posX > screenWidth) posX = -200; // reinicia desde la izquierda

        if (growing) {
            fontSize += 30 * deltaTime;
            if (fontSize >= 40) growing = false;
        } else {
            fontSize -= 30 * deltaTime;
            if (fontSize <= 20) growing = true;
        }

        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Texto animado en C++ con Raylib", (int)posX, screenHeight/2, (int)fontSize, GREEN);
            DrawText("Presiona ESC para salir", 10, screenHeight - 30, 20, GRAY);
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
