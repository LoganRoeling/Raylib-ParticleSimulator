#ifndef PARTICLE_H
#define PARTICLE_H

#include <raylib.h>

#include <cmath>

#include "Vec2.hpp"

class Particle {
   private:
   public:
    Particle(Vec2 position, Vec2 velocity, Vec2 acceleration, float radius,
             float dampCoeff, float fricCoeff, Color color);
    Vec2 position;
    Vec2 velocity;
    Vec2 acceleration;
    float radius;
    float dampCoeff;  // 1.0 = Perfectly Elastic, < 1.0 = Lost Energy, > 1.0 =
                      // Gained Energy
    float fricCoeff;
    Color color;
    void step(float dt);
    void bounceLeft(int threshold);
    void bounceRight(int threshold);
    void bounceUp(int threshold);
    void bounceDown(int threshold);
    void draw();
};

#endif
