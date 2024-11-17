#include <GL/glut.h>
#include <cstdlib>
#include "rain.h"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

RainEffect::RainEffect(int particleCount)
    : particleCount(particleCount)
{
    particles.resize(particleCount);
    initializeParticles();
}

void RainEffect::initializeParticles()
{
    for (auto& particle : particles)
    {
        particle.x = rand() % SCREEN_WIDTH;
        particle.y = rand() % SCREEN_HEIGHT;
        particle.speedY = (rand() % 5 + 5) * 0.5f; // Random speed between 2.5 and 5.0
        particle.active = true;
    }
}

void RainEffect::update()
{
    for (auto& particle : particles)
    {
        if (particle.active)
        {
            particle.y += particle.speedY;

            // Reset particle if it moves off the screen
            if (particle.y > SCREEN_HEIGHT)
            {
                particle.x = rand() % SCREEN_WIDTH;
                particle.y = 0;
                particle.speedY = (rand() % 5 + 5) * 0.5f;
            }
        }
    }
}

void RainEffect::draw() const
{
    glColor3f(0.5f, 0.5f, 1.0f); // Light blue for rain

    glBegin(GL_LINES);
    for (const auto& particle : particles)
    {
        if (particle.active)
        {
            glVertex2f(particle.x, particle.y);
            glVertex2f(particle.x, particle.y + 10); // Draw rain streak
        }
    }
    glEnd();
}
