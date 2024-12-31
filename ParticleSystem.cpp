#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(int numParticles, float gravity,
                               int leftThreshold, int rightThreshold,
                               int upThreshold, int downThreshold) {
    this->gravity = gravity;
    this->leftThreshold = leftThreshold;
    this->rightThreshold = rightThreshold;
    this->upThreshold = upThreshold;
    this->downThreshold = downThreshold;
    this->particles = this->getRandomParticles(numParticles);
}

std::vector<Particle> ParticleSystem::getRandomParticles(int numParticles) {
    std::random_device rd{};
    std::mt19937 gen{rd()};
    // Position: uniformly sample
    std::uniform_real_distribution<float> distX(this->leftThreshold,
                                                this->rightThreshold);
    std::uniform_real_distribution<float> distY(this->downThreshold,
                                                this->upThreshold);
    // Color: uniformly sample
    std::uniform_int_distribution<uint8_t> distC(0, 255);
    // Velocity: sample from normal/gaussian
    std::normal_distribution<float> distV(0.0f, 500.0f);
    // Sample from distributions
    std::vector<Particle> particles;
    for (int i = 0; i < numParticles; i++) {
        Vec2 position = Vec2(distX(gen), distY(gen));
        Vec2 velocity = Vec2(distV(gen), distV(gen));
        Vec2 acceleration = Vec2(0, this->gravity);
        float radius = 10.0f;
        float dampCoeff = 0.85f;
        // Color color = {255, 0, 255, 255};  // magenta
        Color color = {distC(gen), distC(gen), distC(gen), 255};
        Particle particle = Particle(position, velocity, acceleration, radius,
                                     dampCoeff, color);
        particles.push_back(particle);
    }
    return particles;
}

void ParticleSystem::step(float dt) {
    for (Particle& particle : this->particles) {
        particle.step(dt);
        // If position exceeds threshold ==> Negate and damp velocity vector
        if (particle.position.x - particle.radius <= this->leftThreshold) {
            particle.bounceLeft(this->leftThreshold);
        }
        if (particle.position.x + particle.radius >= this->rightThreshold) {
            particle.bounceRight(this->rightThreshold);
        }
        if (particle.position.y - particle.radius <= this->upThreshold) {
            particle.bounceUp(this->upThreshold);
        }
        if (particle.position.y + particle.radius >= this->downThreshold) {
            particle.bounceDown(downThreshold);
        }
    }
}

void ParticleSystem::draw() {
    for (Particle particle : this->particles) {
        particle.draw();
    }
}
