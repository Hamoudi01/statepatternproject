# State Pattern – Game Character Demo

## Overview
This project demonstrates the **State Design Pattern** using a console-based
game character simulation written in C++.

The application shows how a game character’s behavior changes dynamically
at runtime based on its current state, without using large conditional logic.

## Design Pattern Used
**State Pattern**

The State Pattern allows an object to alter its behavior when its internal
state changes. The object appears to change its class at runtime.

---

## Implemented States
- IdleState
- RunningState
- JumpingState
- CrouchingState
- ProneState
- AttackState
- DeadState

## Pattern Role Mapping

| Pattern Role | Class |
|-------------|------|
| Context | GameCharacter |
| State Interface | CharacterState |
| Concrete States | IdleState, RunningState, JumpingState, CrouchingState, ProneState, AttackState, DeadState |
| Client | main() |

## File Structure

├── Character.h
├── main.cpp
└── .devcontainer/
├── Dockerfile
└── devcontainer.json

## Build & Run Instructions

This project was developed and tested inside a **Dev Container / GitHub Codespace**
using a Linux environment with `g++`.

### Environment Used
- Ubuntu 22.04 (Dev Container)
- g++ (GNU Compiler Collection)
- Visual Studio Code

---

### Step 1: Open the Project in a Dev Container
- Open the repository in Visual Studio Code
- Reopen the folder in a Dev Container **or**
- Open the repository using GitHub Codespaces

---

### Step 2: Navigate to the Project Directory
cd /workspaces/statepatternproject

### Step 3: Compile the Program
g++ main.cpp Character.cpp -o StatePatternDemo

### Step 4: Run the Program
./StatePatternDemo

### Expected Output
The program will print messages showing the character transitioning through different states. Each output line represents a different state handling the
same request() call.

## Git Commands Used
```bash
git status
git add .
git commit -m "Update State Pattern demo and documentation"
git push

## Delete Old Compiled Program
rm StatePatternDemo