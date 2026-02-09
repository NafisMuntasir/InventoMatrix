# InventoMatrix
### Custom OOP Turn-Based Combat System (C++)

InventoMatrix is a **C++ Object-Oriented Programming (OOP)** project that implements a **party vs party turn-based combat system**. The design emphasizes clean OOP architecture using **encapsulation, inheritance, polymorphism, and abstraction**, with systems for **buffs/nerfs (status effects)** and a **weight-based inventory** that influences combat performance.

---

## Key Features

- **Party vs Party Turn-Based Combat**
  - Multiple characters per party
  - Turn order management
  - Action resolution (attack/defend/skills/items)

- **Buff & Nerf System**
  - Duration-based effects
  - Stackable / non-stackable effects (depending on design)
  - Stat modification through polymorphic effects

- **Weight-Based Inventory**
  - Items with weights
  - Capacity constraints
  - Overweight penalties affecting combat stats/actions

---

## OOP Principles Used (C++)

### Encapsulation
- Class fields are kept `private` / `protected`
- State changes occur through controlled public methods
- Example: `Character::takeDamage()`, `Inventory::addItem()`

### Abstraction
- Abstract base classes or interfaces via **pure virtual functions**
- High-level systems depend on base types, not implementations
- Example: `class StatusEffect { virtual void apply(Character&) = 0; }`

### Inheritance
- Common logic shared through base classes
- Derived classes extend behavior without duplicating code
- Example: `Buff` and `Nerf` inherit from `StatusEffect`

### Polymorphism
- Runtime dispatch through `virtual` functions
- Enables flexible effects/actions without `if/else` chains
- Example: `effect->apply(character);` behaves differently per derived effect type

---

## Build & Run (g++)

### Linux / macOS / WSL
```bash
g++ -std=c++20 -Iinclude src/main.cpp src/combat/*.cpp src/entities/*.cpp src/effects/*.cpp src/inventory/*.cpp -o inventomatrix
./inventomatrix

## Changelog

### 2026-02-09
- Added Character class
- Added Skill class
- Added CompositeSkill class
- Added StatusEffect base class
- Added PoisonStatus class
- Added StunStatus class
- Added OverencumberedStatus class


## Authors
Nafis Muntasir
Sadia Afrin Aurthy
Hasan bin Mohammad
Noorea Taj Ayshi
