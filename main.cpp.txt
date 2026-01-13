#include "Character.h"
#include <memory>

int main() {
    // Start character in Idle state
    auto idle = std::make_unique<IdleState>();
    Character character(std::move(idle));

    for(int i = 0; i < 6; i++) {
        std::cout << "Current State: " << character.getStateName() << std::endl;
        character.applyState();
    }

    return 0;
}
