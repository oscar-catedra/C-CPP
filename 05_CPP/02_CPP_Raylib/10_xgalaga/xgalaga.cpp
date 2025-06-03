
// xgalaga.cpp

#include "raylib.h"
#include <vector>
#include <string>

struct Enemy {
    Vector2 position;
    Vector2 velocity;
    bool active;
};

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Xgalaga C++ - Juego con sonido opcional");

    bool soundAvailable = false;
    Sound shootSound = {0};
    Sound explosionSound = {0};

    if (IsFileExtension("resources/shoot.wav", ".wav") && FileExists("resources/shoot.wav") &&
        IsFileExtension("resources/explosion.wav", ".wav") && FileExists("resources/explosion.wav")) {
        shootSound = LoadSound("resources/shoot.wav");
        explosionSound = LoadSound("resources/explosion.wav");
        soundAvailable = true;
    }

    Vector2 playerPos = { screenWidth / 2.0f, screenHeight - 40.0f };
    const float playerSpeed = 400.0f;

    Vector2 bulletPos = { -10, -10 };
    const float bulletSpeed = 800.0f;
    bool bulletActive = false;

    std::vector<Enemy> enemies;
    for (int i = 0; i < 5; ++i) {
        enemies.push_back({ {100 + i * 120, 50}, {50, 0}, true });
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
            bulletPos = { playerPos.x, playerPos.y - 20 };
            bulletActive = true;
            if (soundAvailable) PlaySound(shootSound);
        }

        // Actualizar bala
        if (bulletActive) {
            bulletPos.y -= bulletSpeed * dt;
            if (bulletPos.y < 0) bulletActive = false;
        }

        // Actualizar enemigos
        for (auto& enemy : enemies) {
            if (!enemy.active) continue;

            enemy.position.x += enemy.velocity.x * dt;

            if (enemy.position.x < 50 || enemy.position.x > screenWidth - 50)
                enemy.velocity.x *= -1;

            // Colisión bala-enemigo
            if (bulletActive && CheckCollisionCircleRec(bulletPos, 5, Rectangle{ enemy.position.x - 20, enemy.position.y - 20, 40, 40 })) {
                enemy.active = false;
                bulletActive = false;
                score += 10;
                if (soundAvailable) PlaySound(explosionSound);
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Xgalaga - Press SPACE to shoot", 10, 10, 20, DARKGRAY);
        DrawText(TextFormat("Score: %d", score), 10, 40, 20, DARKGRAY);

        DrawRectangleV({ playerPos.x - 20, playerPos.y - 10 }, { 40, 20 }, BLUE);

        if (bulletActive) DrawCircleV(bulletPos, 5, RED);

        for (const auto& enemy : enemies) {
            if (enemy.active) DrawCircleV(enemy.position, 20, GREEN);
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

