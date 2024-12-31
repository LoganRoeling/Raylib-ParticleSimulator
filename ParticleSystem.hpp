#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include <random>
#include <vector>

#include "Particle.hpp"

class ParticleSystem {
   private:
    float gravity;
    int leftThreshold;
    int rightThreshold;
    int upThreshold;
    int downThreshold;
    std::vector<Particle> getRandomParticles(int numParticles);

   public:
    ParticleSystem(int numParticles, float gravity, int leftThreshold,
                   int rightThreshold, int upThreshold, int downThreshold);
    std::vector<Particle> particles;
    void step(float dt);
    void draw();
};

#endif
