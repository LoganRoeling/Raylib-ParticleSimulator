#include <iostream>

#include "ParticleSystem.hpp"

int main() {
    const unsigned int WINDOW_WIDTH = 800;
    const unsigned int WINDOW_HEIGHT = 600;
    const char* WINDOW_TITLE = "GAME TITLE";
    const Color WINDOW_COLOR = {0, 0, 0, 255};
    const int FPS_RATE = 240;

    // Initialize Particle System
    int numParticles = 100;
    float gravity = 2500;
    int leftThreshold = 0;
    int rightThreshold = WINDOW_WIDTH;
    int upThreshold = 0;
    int downThreshold = WINDOW_HEIGHT;
    ParticleSystem particleSystem =
        ParticleSystem(numParticles, gravity, leftThreshold, rightThreshold,
                       upThreshold, downThreshold);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(FPS_RATE);
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        particleSystem.step(dt);
        BeginDrawing();
        ClearBackground(WINDOW_COLOR);
        particleSystem.draw();
        EndDrawing();
    }
    CloseWindow();
}
