#pragma once
#include "Component.hpp"

struct VelocityComponent : public Component {
    float vx, vy;

    VelocityComponent(float vx = 0, float vy = 0) : vx(vx), vy(vy) {}
};