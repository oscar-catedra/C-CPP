

#include "raylib.h"
#include <stdbool.h>

#define MAX_ENEMIES 5

typedef struct {
    Vector2 position;
    Vector2 velocity;
    bool active;
} Enemy;

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Xgalaga C - Juego con sonido opcional");

    // Intentar cargar sonidos
    Sound shootSound = {0};
    Sound explosionSound = {0};
    bool soundAvailable = false;

    // Cargar sonidos con manejo de errores
    if (IsFileExtension("resources/shoot.wav", ".wav") && FileExists("resources/shoot.wav") &&
        IsFileExtension("resources/explosion.wav", ".wav") && FileExists("resources/explosion.wav")) {
        shootSound = LoadSound("resources/shoot.wav");
        explosionSound = LoadSound("resources/explosion.wav");
        soundAvailable = true;
    }

    Vector2 playerPos = { screenWidth / 2.0f, screenHeight - 40.0f };
    float playerSpeed = 400.0f;

    Vector2 bulletPos = { -10, -10 };
    float bulletSpeed = 800.0f;
    bool bulletActive = false;

    Enemy enemies[MAX_ENEMIES];
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].position = (Vector2){ 100 + i * 120, 50 };
        enemies[i].velocity = (Vector2){ 50, 0 };
        enemies[i].active = true;
    }

    int score = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        // Movimiento jugador
        if (IsKeyDown(KEY_LEFT)) playerPos.x -= playerSpeed * dt;
        if (IsKeyDown(KEY_RIGHT)) playerPos.x += playerSpeed * dt;

        if (playerPos.x < 20) playerPos.x = 20;
        if (playerPos.x > screenWidth - 20) playerPos.x = screenWidth - 20;

        // Disparo
        if (IsKeyPressed(KEY_SPACE) && !bulletActive) {
            bulletPos = (Vector2){ playerPos.x, playerPos.y - 20 };
            bulletActive = true;
            if (soundAvailable) PlaySound(shootSound);
        }

        // Actualizar bala
        if (bulletActive) {
            bulletPos.y -= bulletSpeed * dt;
            if (bulletPos.y < 0) bulletActive = false;
        }

        // Actualizar enemigos
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (!enemies[i].active) continue;

            enemies[i].position.x += enemies[i].velocity.x * dt;

            if (enemies[i].position.x < 50 || enemies[i].position.x > screenWidth - 50)
                enemies[i].velocity.x *= -1;

            // Colisión bala-enemigo
            if (bulletActive && CheckCollisionCircleRec(bulletPos, 5, (Rectangle){ enemies[i].position.x - 20, enemies[i].position.y - 20, 40, 40 })) {
                enemies[i].active = false;
                bulletActive = false;
                score += 10;
                if (soundAvailable) PlaySound(explosionSound);
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Xgalaga - Presiona SPACE para disparar", 10, 10, 20, DARKGRAY);
        DrawText(TextFormat("Puntaje: %d", score), 10, 40, 20, DARKGRAY);

        // Dibujar jugador
        DrawRectangleV((Vector2){ playerPos.x - 20, playerPos.y - 10 }, (Vector2){ 40, 20 }, BLUE);

        // Dibujar bala
        if (bulletActive) DrawCircleV(bulletPos, 5, RED);

        // Dibujar enemigos
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (enemies[i].active) DrawCircleV(enemies[i].position, 20, GREEN);
        }

        EndDrawing();
    }

    if (soundAvailable) {
        UnloadSound(shootSound);
        UnloadSound(explosionSound);
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

