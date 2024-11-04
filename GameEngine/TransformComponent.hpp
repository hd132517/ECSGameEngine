#pragma once
#include "Component.hpp"

struct TransformComponent : public Component {
    float x, y;

    TransformComponent(float x = 0, float y = 0) : x(x), y(y) {}
};