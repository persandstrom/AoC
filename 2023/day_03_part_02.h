#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include "file_reader.h"
#include "aoc_util.h"

using namespace std;

namespace day_03_part_02 {

inline std::string coord_to_id(const int x, const int y) {
    return std::to_string(x) + "," + std::to_string(y);
}

std::string run(FileReader& reader) {
    
    auto input = reader.to_vector();   

    std::unordered_map<std::string, std::vector<int>> gears;

    for (int y=0; y<input.size(); y++) {
        bool nr_found = false;
        std::unordered_set<std::string> adjacent_gears;
        int nr_start=0;
        for (int x=0; x<input[0].length(); x++) {
            if (!nr_found && input[y][x] >= '0' && input[y][x] <= '9') {
                nr_found = true;
                nr_start = x;
                adjacent_gears.clear();
            } else if (nr_found && (input[y][x] < '0' || input[y][x] > '9')) {
                nr_found = false;
                for (const auto& gear : adjacent_gears) {
                    gears[gear].push_back(stoi(input[y].substr(nr_start, x-nr_start)));
                }
            }
            if (nr_found) {
                aoc::check_adjecent(input, x, y, [&adjacent_gears](const int nx, const int ny, const char c) {
                    if (c=='*') {
                        adjacent_gears.insert(coord_to_id(nx,ny));
                    }
                });
            }
        }
        if (nr_found) {
            for (const auto& gear : adjacent_gears) {
                gears[gear].push_back(stoi(input[y].substr(nr_start, input[0].length()-nr_start)));
            }
        }
    }
    
    int sum = 0;
    for (auto& gear : gears) {
        if (gear.second.size() == 2) {
            sum += gear.second.at(0) * gear.second.at(1);
        }
    }
    return std::to_string(sum);
}

}
