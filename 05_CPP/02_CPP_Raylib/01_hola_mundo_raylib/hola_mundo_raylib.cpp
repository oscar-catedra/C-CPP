#include <raylib.h>

int main() {
    InitWindow(800, 600, "Hola Raylib en C++");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hola mundo desde C++!", 180, 200, 20, DARKGREEN);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// Referencia
// OpenAI. (2025, mayo 24). Compilar y distribuir programas de Raylib en Windows 
// usando MSYS2 UCRT64 [ChatGPT]. ChatGPT. 
// https://chatgpt.com/share/6831f399-7888-8013-91da-24df84e0d612

// g++ hola_mundo_raylib.cc -o hola_mundo_raylib -lraylib -lwinmm -lgdi32
