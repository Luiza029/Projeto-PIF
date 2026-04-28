#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "Meu Jogo");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Olá, mundo!", 300, 280, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
