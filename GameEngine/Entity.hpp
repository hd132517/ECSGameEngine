#pragma once
#include <vector>
#include <memory>
#include "Component.hpp"

class Entity {
public:
    Entity(int id) : id(id) {}

    template <typename T, typename... TArgs>
    void addComponent(TArgs&&... args) {
        components.emplace_back(std::make_unique<T>(std::forward<TArgs>(args)...));
    }

    template <typename T>
    T* getComponent() {
        for (auto& comp : components)
            if (T* casted = dynamic_cast<T*>(comp.get())) return casted;
        
        return nullptr;
    }

private:
    int id;
    std::vector<std::unique_ptr<Component>> components;
};
