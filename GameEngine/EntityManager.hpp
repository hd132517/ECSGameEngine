#pragma once
#include <vector>
#include "Entity.hpp"

class EntityManager {
public:
    Entity& createEntity() {
        entities.emplace_back(nextId++);
        return entities.back();
    }

    std::vector<Entity>& getEntities() { return entities; }

private:
    int nextId = 0;
    std::vector<Entity> entities;
};