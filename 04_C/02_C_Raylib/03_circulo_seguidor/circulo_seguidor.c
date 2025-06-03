// archivo: circulo_seguidor.c
#include "raylib.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib C - Circulo seguidor");

    Color circleColor = RED;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            circleColor = (circleColor.r == RED.r) ? BLUE : RED;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Haz clic izquierdo para cambiar el color del círculo", 10, 10, 20, DARKGRAY);
            DrawCircleV(mousePos, 40, circleColor);
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
