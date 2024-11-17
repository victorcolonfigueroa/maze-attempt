#ifndef RAIN_EFFECTS_H
#define RAIN_EFFECTS_H

#include <vector>

class RainEffect
{
public:
    struct RainParticle
    {
        float x, y;
        float speedY;
        bool active;
    };

    RainEffect(int particleCount = 500);

    void initializeParticles();
    void update();
    void draw() const;

private:
    int particleCount;
    std::vector<RainParticle> particles;
};

#endif
