#include "FileIOPlayerCharacter.hpp"
#include "StatBlock.hpp"
#include <sstream>

namespace FileIO {

static int parseInt(const std::string& text, int defaultValue = 0) {
    try {
        return std::stoi(text);
    } catch (...) {
        return defaultValue;
    }
}

bool savePlayerCharacter(const PlayerCharacter& pc, const std::string& filepath) {
    const StatBlock& stats = pc.getBaseStats();
    std::ostringstream out;

    out << "name=" << pc.getName() << "\n";
    out << "level=" << pc.getLevel() << "\n";
    out << "hp=" << pc.getHP() << "\n";
    out << "maxHP=" << pc.getMaxHP() << "\n";
    out << "mana=" << pc.getMana() << "\n";
    out << "weight=" << pc.getWeight() << "\n";
    out << "maxWeight=" << pc.getMaxWeight() << "\n";
    out << "attack=" << stats.getAttack() << "\n";
    out << "defense=" << stats.getDefense() << "\n";
    out << "speed=" << stats.getSpeed() << "\n";
    out << "accuracy=" << stats.getAccuracy() << "\n";
    out << "evasion=" << stats.getEvasion() << "\n";
    out << "crit=" << stats.getCrit() << "\n";
    out << "defending=" << (pc.isDefending() ? 1 : 0) << "\n";

    return FileIO::writeTextFile(filepath, out.str());
}

std::optional<PlayerCharacterData> loadPlayerCharacterData(const std::string& filepath) {
    auto source = FileIO::readTextFile(filepath);
    if (!source) {
        return std::nullopt;
    }

    PlayerCharacterData data;
    std::istringstream stream(*source);
    std::string line;

    while (std::getline(stream, line)) {
        if (line.empty()) continue;

        const auto delimiterPos = line.find('=');
        if (delimiterPos == std::string::npos) continue;

        std::string key = line.substr(0, delimiterPos);
        std::string value = line.substr(delimiterPos + 1);

        if (key == "name") {
            data.name = value;
        } else if (key == "level") {
            data.level = parseInt(value, data.level);
        } else if (key == "hp") {
            data.hp = parseInt(value, data.hp);
        } else if (key == "maxHP") {
            data.maxHP = parseInt(value, data.maxHP);
        } else if (key == "mana") {
            data.mana = parseInt(value, data.mana);
        } else if (key == "weight") {
            data.weight = parseInt(value, data.weight);
        } else if (key == "maxWeight") {
            data.maxWeight = parseInt(value, data.maxWeight);
        } else if (key == "attack") {
            data.attack = parseInt(value, data.attack);
        } else if (key == "defense") {
            data.defense = parseInt(value, data.defense);
        } else if (key == "speed") {
            data.speed = parseInt(value, data.speed);
        } else if (key == "accuracy") {
            data.accuracy = parseInt(value, data.accuracy);
        } else if (key == "evasion") {
            data.evasion = parseInt(value, data.evasion);
        } else if (key == "crit") {
            data.crit = parseInt(value, data.crit);
        } else if (key == "defending") {
            data.defending = parseInt(value, 0) != 0;
        }
    }

    if (data.name.empty()) {
        return std::nullopt;
    }
    if (data.maxHP <= 0) {
        data.maxHP = data.hp > 0 ? data.hp : 1;
    }

    return data;
}

std::optional<std::shared_ptr<PlayerCharacter>> loadPlayerCharacter(const std::string& filepath) {
    auto dataOpt = loadPlayerCharacterData(filepath);
    if (!dataOpt) {
        return std::nullopt;
    }

    const auto& d = *dataOpt;
    StatBlock stats(d.maxHP, d.attack, d.defense, d.speed, d.accuracy, d.evasion, d.crit);
    auto pc = std::make_shared<PlayerCharacter>(d.name, d.level, stats, d.weight, d.maxWeight);

    // Set HP to serialized value (may be below max).
    if (d.hp < pc->getHP()) {
        pc->takeDamage(pc->getHP() - d.hp);
    } else {
        pc->heal(d.hp - pc->getHP());
    }

    // Set mana as best effort, using restore mana from default 0
    if (d.mana > pc->getMana()) {
        pc->restoreMana(d.mana - pc->getMana());
    }

    pc->setDefending(d.defending);

    return pc;
}

} // namespace FileIO
