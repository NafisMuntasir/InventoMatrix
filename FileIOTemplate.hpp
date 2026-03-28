#pragma once

#include <fstream>
#include <optional> 
#include <string>

namespace FileIO {

inline bool writeTextFile(const std::string& path, const std::string& content) {
    std::ofstream out(path, std::ios::out | std::ios::trunc);
    if (!out.is_open()) {
        return false;
    }
    out << content;
    return !out.fail();
}

inline std::optional<std::string> readTextFile(const std::string& path) {  // Useful for file reading because reading may fail
    std::ifstream in(path, std::ios::in);
    if (!in.is_open()) {
        return std::nullopt;
    }

    std::string data;
    std::string line;

    while (std::getline(in, line)) {
        data += line + "\n";
    }

    if (in.fail() && !in.eof()) {
        return std::nullopt;
    }

    return data;
}

// Customizable serializer save-load interface (specialize in concrete class modules)
template <typename T>        // Function Template
struct Serializer {          // Generic pattern for saving/loading of specific classes later
    static bool save(const T& object, const std::string& filepath) {
        static_assert(sizeof(T) == 0, "Serializer<T> is not specialized for this type");     // Compile time check
        return false;        // condition will always be false for a real type
    }

    static std::optional<T> load(const std::string& filepath) {
        static_assert(sizeof(T) == 0, "Serializer<T> is not specialized for this type");
        return std::nullopt;
    }
};

} // namespace FileIO : Scope managing mechanism (Grouping related names)

//Here are common text file helper functions, and here is a generic save/load framework that concrete classes can plug into later.