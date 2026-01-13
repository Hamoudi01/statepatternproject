#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <memory>

// Forward declaration
class GameCharacter;

// Base State class
class CharacterState {
public:
    virtual ~CharacterState() = default;
    virtual void handle(GameCharacter& character) = 0;
};

// Context class
class GameCharacter {
private:
    std::unique_ptr<CharacterState> state;
public:
    GameCharacter(std::unique_ptr<CharacterState> initialState)
        : state(std::move(initialState)) {}

    void setState(std::unique_ptr<CharacterState> newState) {
        state = std::move(newState);
    }

    void request() {
        state->handle(*this);
    }
};

// Concrete States
class IdleState : public CharacterState {
public:
    void handle(GameCharacter& character) override;
};

class AttackState : public CharacterState {
public:
    void handle(GameCharacter& character) override;
};

class DefendState : public CharacterState {
public:
    void handle(GameCharacter& character) override;
};

class DeadState : public CharacterState {
public:
    void handle(GameCharacter& character) override;
};

// Implementations
inline void IdleState::handle(GameCharacter& character) {
    std::cout << "Character is idle" << std::endl;
    character.setState(std::make_unique<AttackState>());
}

inline void AttackState::handle(GameCharacter& character) {
    std::cout << "Character attacks" << std::endl;
    character.setState(std::make_unique<DefendState>());
}

inline void DefendState::handle(GameCharacter& character) {
    std::cout << "Character defends" << std::endl;
    character.setState(std::make_unique<DeadState>());
}

inline void DeadState::handle(GameCharacter& character) {
    std::cout << "Character is dead" << std::endl;
    character.setState(std::make_unique<IdleState>());
}

#endif
