#pragma once
#include "Entity.hpp"

class System {
public:
    virtual ~System() = default;
    virtual void update(Entity& entity, float dt) = 0;
};