
// sistema_solar.cpp

#include "raylib.h"
#include <cmath>
#include <vector>
#include <string>

#define PI 3.14159265f

class Planeta {
public:
    float radioOrbita;
    float velocidad;
    float angulo;
    float radio;
    Color color;

    Planeta(float orb, float vel, float rad, Color c)
        : radioOrbita(orb), velocidad(vel), angulo(0), radio(rad), color(c) {}

    void actualizar(float dt) {
        angulo += velocidad * dt;
    }

    void dibujar(Vector2 centro) const {
        float x = centro.x + cosf(angulo) * radioOrbita;
        float y = centro.y + sinf(angulo) * radioOrbita;
        DrawCircle((int)x, (int)y, radio, color);
    }
};

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Raylib C++ - Sistema solar");

    Vector2 sol = { screenWidth / 2.0f, screenHeight / 2.0f };

    std::vector<Planeta> planetas = {
        Planeta( 80, 2.0f, 5, SKYBLUE),
        Planeta(130, 1.0f, 8, ORANGE),
        Planeta(190, 0.5f, 12, GREEN),
        Planeta(250, 0.3f, 16, RED)
    };

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        for (auto& p : planetas) p.actualizar(dt);

        BeginDrawing();
        ClearBackground(BLACK);

        DrawCircleV(sol, 30, YELLOW); // el Sol
        for (const auto& p : planetas) {
            DrawCircleLines((int)sol.x, (int)sol.y, p.radioOrbita, DARKGRAY);
            p.dibujar(sol);
        }

        DrawText("Sistema Solar Simulado", 10, 10, 20, RAYWHITE);
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
