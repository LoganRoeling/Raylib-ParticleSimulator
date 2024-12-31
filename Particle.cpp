#include "Particle.hpp"

// PRIVATE METHODS

void Particle::bounceLeft(int threshold) {
    this->velocity.x *= -1.0f * this->dampCoeff;
    this->position.x = threshold + this->radius;
}

void Particle::bounceRight(int threshold) {
    this->velocity.x *= -1.0f * this->dampCoeff;
    this->position.x = threshold - this->radius;
}

void Particle::bounceUp(int threshold) {
    this->velocity.y *= -1.0f * this->dampCoeff;
    this->position.y = threshold + this->radius;
}

void Particle::bounceDown(int threshold) {
    this->velocity.y *= -1.0f * this->dampCoeff;
    this->position.y = threshold - this->radius;
}

// PUBLIC METHODS

Particle::Particle(Vec2 position, Vec2 velocity, Vec2 acceleration,
                   float radius, float dampCoeff, Color color) {
    this->position = position;
    this->velocity = velocity;
    this->acceleration = acceleration;
    this->radius = radius;
    this->dampCoeff = dampCoeff;
    this->color = color;
}

void Particle::step(float dt) {
    // v_1 = v_0 + a*dt
    // x_1 = x_0 + v_1*dt
    Vec2 dv = this->acceleration.scale(dt);
    Vec2 newVelocity = this->velocity.add(dv);
    Vec2 dx = newVelocity.scale(dt);
    Vec2 newPosition = this->position.add(dx);
    this->position = newPosition;
    this->velocity = newVelocity;
}

void Particle::draw() {
    int posX = static_cast<int>(std::round(this->position.x));
    int posY = static_cast<int>(std::round(this->position.y));
    DrawCircle(posX, posY, this->radius, this->color);
}
