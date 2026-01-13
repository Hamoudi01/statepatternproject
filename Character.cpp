/*#include "Character.h"
#include <iostream>
#include <memory>

// IdleState
class IdleState : public State {
public:
    void handle(Character& character) override {
        std::cout << "Character is now idle." << std::endl;
        character.setState(std::make_unique<RunningState>());
    }
};

// RunningState
class RunningState : public State {
public:
    void handle(Character& character) override {
        std::cout << "Character is now running." << std::endl;
        character.setState(std::make_unique<JumpingState>());
    }
};

// JumpingState
class JumpingState : public State {
public:
    void handle(Character& character) override {
        std::cout << "Character is now jumping." << std::endl;
        character.setState(std::make_unique<IdleState>());
    }
};
*/