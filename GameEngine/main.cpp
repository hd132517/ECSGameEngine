#include "EntityManager.hpp"
#include "MovementSystem.hpp"
#include <iostream>

int main() {
    EntityManager entityManager;
    MovementSystem movementSystem;

    // 엔티티 생성 및 컴포넌트 추가
    Entity& entity = entityManager.createEntity();
    entity.addComponent<TransformComponent>(0.0f, 0.0f);
    entity.addComponent<VelocityComponent>(1.0f, 1.5f);

    // 게임 루프 (단순화된 예제)
    for (int i = 0; i < 10; ++i) {
        for (auto& entity : entityManager.getEntities()) {
            movementSystem.update(entity, 1.0f);  // 1초당 위치 갱신
            auto* transform = entity.getComponent<TransformComponent>();
            if (transform) {
                std::cout << "Entity position: (" << transform->x << ", " << transform->y << ")\n";
            }
        }
    }
    return 0;
}