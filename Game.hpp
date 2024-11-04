#pragma once
#include "GameEngine/EntityManager.hpp"
#include "GameEngine/MovementSystem.hpp"
#include "GameEngine/TransformComponent.hpp"
#include "GameEngine/VelocityComponent.hpp"
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void run();

private:
    void processInput();
    void update(float dt);
    void render();
    
    EntityManager entityManager;
    MovementSystem movementSystem;
    
    sf::RenderWindow window;
    Entity player;
    std::vector<Entity> enemies;
};