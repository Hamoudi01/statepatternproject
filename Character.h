#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <memory>

// Forward declaration
class Character;

class State {
public:
    virtual void handle(Character& character) = 0;
    virtual std::string getName() = 0;
    virtual ~State() {}
};

class Character {
private:
    std::unique_ptr<State> currentState;
public:
    Character(std::unique_ptr<State> state) : currentState(std::move(state)) {}
    void setState(std::unique_ptr<State> state) { currentState = std::move(state); }
    void applyState() { currentState->handle(*this); }
    std::string getStateName() { return currentState->getName(); }
};

#endif
