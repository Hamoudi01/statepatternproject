#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <memory>

// Forward declaration
class GameCharacter;

/* =========================
   State Interface
   ========================= */
class CharacterState {
public:
    virtual ~CharacterState() = default;
    virtual void handle(GameCharacter& character) = 0;
};

/* =========================
   Context
   ========================= */
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

/* =========================
   Concrete States
   ========================= */
class IdleState : public CharacterState {
public:
    void handle(GameCharacter& character) override;
};

class RunningState : public CharacterState {
public:
    void handle(GameCharacter& character) override;
};

class JumpingState : public CharacterState {
public:
    void handle(GameCharacter& character) override;
};

class CrouchingState : public CharacterState {
public:
    void handle(GameCharacter& character) override;
};

class ProneState : public CharacterState {
public:
    void handle(GameCharacter& character) override;
};

class AttackState : public CharacterState {
public:
    void handle(GameCharacter& character) override;
};

class DeadState : public CharacterState {
public:
    void handle(GameCharacter& character) override;
};

/* =========================
   State Implementations
   ========================= */

inline void IdleState::handle(GameCharacter& character) {
    std::cout << "Character is idle" << std::endl;
    character.setState(std::make_unique<RunningState>());
}

inline void RunningState::handle(GameCharacter& character) {
    std::cout << "Character is running" << std::endl;
    character.setState(std::make_unique<JumpingState>());
}

inline void JumpingState::handle(GameCharacter& character) {
    std::cout << "Character jumps" << std::endl;
    character.setState(std::make_unique<CrouchingState>());
}

inline void CrouchingState::handle(GameCharacter& character) {
    std::cout << "Character crouches" << std::endl;
    character.setState(std::make_unique<AttackState>());
}

inline void AttackState::handle(GameCharacter& character) {
    std::cout << "Character attacks" << std::endl;
    character.setState(std::make_unique<ProneState>());
}

inline void ProneState::handle(GameCharacter& character) {
    std::cout << "Character goes prone" << std::endl;
    character.setState(std::make_unique<DeadState>());
}

inline void DeadState::handle(GameCharacter& character) {
    std::cout << "Character is dead" << std::endl;
    character.setState(std::make_unique<IdleState>());
}

#endif
