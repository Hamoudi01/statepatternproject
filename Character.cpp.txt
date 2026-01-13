#include "Character.h"

// Concrete States
class IdleState : public State {
public:
    void handle(Character& character) override {
        std::cout << "Character is now idle.\n";
        character.setState(std::make_unique<RunningState>());
    }
    std::string getName() override { return "Idle"; }
};

class RunningState : public State {
public:
    void handle(Character& character) override {
        std::cout << "Character is now running.\n";
        character.setState(std::make_unique<JumpingState>());
    }
    std::string getName() override { return "Running"; }
};

class JumpingState : public State {
public:
    void handle(Character& character) override {
        std::cout << "Character is now jumping.\n";
        character.setState(std::make_unique<IdleState>());
    }
    std::string getName() override { return "Jumping"; }
};
