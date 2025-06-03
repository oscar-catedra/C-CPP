
// jugador_vs_maquina.cpp

#include "raylib.h"

// Comentario educativo:
// En C++ usamos clases para encapsular entidad y comportamiento.

class Entity {
public:
    Rectangle rect;
    Color color;

    Entity(float x, float y, float w, float h, Color c) {
        rect = {x, y, w, h};
        color = c;
    }

    void Move(float dx, float dy) {
        rect.x += dx;
        rect.y += dy;
    }

    void Draw() const {
        DrawRectangleRec(rect, color);
    }

    bool CollidesWith(const Entity& other) const {
        return CheckCollisionRecs(rect, other.rect);
    }
};

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "C++ - Jugador vs Máquina");
    InitAudioDevice();

    Sound collisionSound = LoadSound("resources/collision.wav");

    Entity player(100, 200, 40, 40, RED);
    Entity enemy(600, 200, 40, 40, BLUE);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Movimiento jugador
        if (IsKeyDown(KEY_RIGHT)) player.Move(5, 0);
        if (IsKeyDown(KEY_LEFT))  player.Move(-5, 0);
        if (IsKeyDown(KEY_DOWN))  player.Move(0, 5);
        if (IsKeyDown(KEY_UP))    player.Move(0, -5);

        // Movimiento enemigo (IA simple)
        if (enemy.rect.x < player.rect.x) enemy.Move(2, 0);
        if (enemy.rect.x > player.rect.x) enemy.Move(-2, 0);
        if (enemy.rect.y < player.rect.y) enemy.Move(0, 2);
        if (enemy.rect.y > player.rect.y) enemy.Move(0, -2);

        bool collided = player.CollidesWith(enemy);
        if (collided) PlaySound(collisionSound);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Jugador vs Maquina (C++)", 10, 10, 20, DARKGRAY);
            player.Draw();
            enemy.Draw();
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

