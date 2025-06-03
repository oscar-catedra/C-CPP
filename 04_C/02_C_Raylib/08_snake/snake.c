

#include "raylib.h"

#define MAX_SEGMENTS 256
#define CELL_SIZE 20

typedef struct Segment {
    int x, y;
} Segment;

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Snake - C");

    Segment snake[MAX_SEGMENTS];
    int snakeLength = 5;
    for (int i = 0; i < snakeLength; i++) {
        snake[i].x = 10 - i;
        snake[i].y = 10;
    }

    Segment food = { GetRandomValue(0, 39), GetRandomValue(0, 29) };
    int dirX = 1, dirY = 0;
    float timer = 0.0f, delay = 0.1f;
    bool gameOver = false;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        if (!gameOver) {
            timer += GetFrameTime();

            if (IsKeyPressed(KEY_UP) && dirY == 0) { dirX = 0; dirY = -1; }
            if (IsKeyPressed(KEY_DOWN) && dirY == 0) { dirX = 0; dirY = 1; }
            if (IsKeyPressed(KEY_LEFT) && dirX == 0) { dirX = -1; dirY = 0; }
            if (IsKeyPressed(KEY_RIGHT) && dirX == 0) { dirX = 1; dirY = 0; }

            if (timer >= delay) {
                timer = 0.0f;

                for (int i = snakeLength - 1; i > 0; i--)
                    snake[i] = snake[i - 1];

                snake[0].x += dirX;
                snake[0].y += dirY;

                if (snake[0].x == food.x && snake[0].y == food.y) {
                    food.x = GetRandomValue(0, 39);
                    food.y = GetRandomValue(0, 29);
                    snakeLength++;
                }

                for (int i = 1; i < snakeLength; i++) {
                    if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
                        gameOver = true;
                        break;
                    }
                }

                if (snake[0].x < 0 || snake[0].x >= 40 || snake[0].y < 0 || snake[0].y >= 30)
                    gameOver = true;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < snakeLength; i++) {
            DrawRectangle(snake[i].x * CELL_SIZE, snake[i].y * CELL_SIZE, CELL_SIZE - 2, CELL_SIZE - 2, GREEN);
        }

        DrawRectangle(food.x * CELL_SIZE, food.y * CELL_SIZE, CELL_SIZE - 2, CELL_SIZE - 2, RED);

        if (gameOver) {
            DrawText("GAME OVER", 300, 250, 40, RAYWHITE);
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
