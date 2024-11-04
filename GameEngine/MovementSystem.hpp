#pragma once
#include "System.hpp"
#include "TransformComponent.hpp"
#include "VelocityComponent.hpp"

class MovementSystem : public System {
public:
    void update(Entity& entity, float dt) override {
        auto* transform = entity.getComponent<TransformComponent>();
        auto* velocity = entity.getComponent<VelocityComponent>();

        if (transform && velocity) {
            transform->x += velocity->vx * dt;
            transform->y += velocity->vy * dt;
        }
    }
};