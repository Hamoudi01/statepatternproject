#include "Character.h"
#include <memory>

int main() {
    GameCharacter character(std::make_unique<IdleState>());

    for (int i = 0; i < 10; ++i) {
        character.request();
    }

    return 0;
}

