
//rebote.cpp

#include "raylib.h"
#include <cmath>  // Para std::fabs

// Comentario educativo:
// En C++ usamos clases y encapsulación para organizar el código más elegantemente.

class Ball {
public:
    Vector2 position;
    Vector2 speed;
    float radius;
    Color color;

    Ball(Vector2 pos, Vector2 spd, float r, Color c)
        : position(pos), speed(spd), radius(r), color(c) {}

    void Update(int screenWidth, int screenHeight) {
        position.x += speed.x;
        position.y += speed.y;

        // Colisiones con bordes
        if ((position.x - radius <= 0) || (position.x + radius >= screenWidth)) {
            speed.x *= -1;
        }
        if ((position.y - radius <= 0) || (position.y + radius >= screenHeight)) {
            speed.y *= -1;
        }
    }

    void Draw() const {
        DrawCircleV(position, radius, color);
    }
};

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "C++ - Rebote con colisiones físicas");
    SetTargetFPS(60);

    Ball ball({screenWidth / 2, screenHeight / 2}, {4, 3}, 20, RED);

    while (!WindowShouldClose()) {
        ball.Update(screenWidth, screenHeight);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Pelota rebotando (C++)", 10, 10, 20, DARKGRAY);
            ball.Draw();
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

