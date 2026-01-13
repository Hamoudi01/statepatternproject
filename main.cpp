#include "Character.h"
#include "Character.h"
#include <memory>

int main() {
    auto idle = std::make_unique<IdleState>();
    GameCharacter character(std::move(idle));

    // Demo: cycle 8 times
    for (int i = 0; i < 8; ++i) {
        character.request();
    }

    return 0;
}
