#pragma once

#include <functional>
#include <string>
#include <vector>

namespace aoc {
    void check_adjecent(
            const std::vector<std::string>& input,
            const int x,
            const int y,
            std::function<void(const char)> func);

    void check_adjecent(
            const std::vector<std::string>& input,
            const int x,
            const int y,
            std::function<void(const int,const int,const char)> func);

    template<typename T>
    std::vector<T> csv_to_vector(const std::string& line) {
        std::stringstream csv(line);
        std::vector<T> result;
        T tmp;
        while(csv >> tmp) {
            result.push_back(tmp);
        }
        return result;
    }
}