#pragma once

#include <memory>
#include <optional>
#include <string>

#include "FileIOTemplate.hpp"
#include "PlayerCharacter.hpp"

namespace FileIO {

struct PlayerCharacterData {
    std::string name;
    int level = 1;
    int hp = 0;
    int maxHP = 0;
    int mana = 0;
    int weight = 0;
    int maxWeight = 100;
    int attack = 0;
    int defense = 0;
    int speed = 0;
    int accuracy = 0;
    int evasion = 0;
    int crit = 0;
    bool defending = false;
};

bool savePlayerCharacter(const PlayerCharacter& pc, const std::string& filepath);
std::optional<PlayerCharacterData> loadPlayerCharacterData(const std::string& filepath);
std::optional<std::shared_ptr<PlayerCharacter>> loadPlayerCharacter(const std::string& filepath);

} // namespace FileIO
