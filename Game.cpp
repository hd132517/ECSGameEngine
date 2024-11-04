#include "Game.hpp"
#include <iostream>

Game::Game() : window(sf::VideoMode(800, 600), "Simple 2D Game"), player(entityManager.createEntity()) {
    player.addComponent<TransformComponent>(400.0f, 300.0f);
    player.addComponent<VelocityComponent>(0.0f, 0.0f);

    // 적 생성
    for (int i = 0; i < 5; ++i) {
        Entity enemy = entityManager.createEntity();
        enemy.addComponent<TransformComponent>(100.0f * (i + 1), 100.0f);
        enemy.addComponent<VelocityComponent>(0.1f, 0.0f);
        enemies.push_back(enemy);
    }
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        processInput();
        float dt = clock.restart().asSeconds();
        update(dt);
        render();
    }
}

void Game::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    // 플레이어 이동
    auto* velocity = player.getComponent<VelocityComponent>();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) velocity->vy = -1.0f;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) velocity->vy = 1.0f;
    else velocity->vy = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) velocity->vx = -1.0f;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) velocity->vx = 1.0f;
    else velocity->vx = 0.0f;
}

void Game::update(float dt) {
    movementSystem.update(player, dt);
    for (auto& enemy : enemies) {
        auto* enemyTransform = enemy.getComponent<TransformComponent>();
        auto* enemyVelocity = enemy.getComponent<VelocityComponent>();
        auto* playerTransform = player.getComponent<TransformComponent>();

        // 적이 플레이어를 향해 이동
        if (enemyTransform && enemyVelocity && playerTransform) {
            if (enemyTransform->x < playerTransform->x) enemyTransform->x += enemyVelocity->vx;
            if (enemyTransform->x > playerTransform->x) enemyTransform->x -= enemyVelocity->vx;
            if (enemyTransform->y < playerTransform->y) enemyTransform->y += enemyVelocity->vy;
            if (enemyTransform->y > playerTransform->y) enemyTransform->y -= enemyVelocity->vy;
        }
    }
}

void Game::render() {
    window.clear();
    
    // 플레이어 렌더링
    auto* playerTransform = player.getComponent<TransformComponent>();
    if (playerTransform) {
        sf::RectangleShape playerShape(sf::Vector2f(50.0f, 50.0f));
        playerShape.setFillColor(sf::Color::Green);
        playerShape.setPosition(playerTransform->x, playerTransform->y);
        window.draw(playerShape);
    }

    // 적 렌더링
    for (auto& enemy : enemies) {
        auto* enemyTransform = enemy.getComponent<TransformComponent>();
        if (enemyTransform) {
            sf::RectangleShape enemyShape(sf::Vector2f(50.0f, 50.0f));
            enemyShape.setFillColor(sf::Color::Red);
            enemyShape.setPosition(enemyTransform->x, enemyTransform->y);
            window.draw(enemyShape);
        }
    }

    window.display();
}