#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include <unordered_map>

using namespace std;

namespace day_08_part_01 {

std::string run(FileReader& reader) {
    unordered_map<string, pair<string, string>> nodes;
    auto input = reader.to_vector();
    string directions = input.at(0);
    for (int i = 2; i<input.size(); i++) {
        nodes[input[i].substr(0, 3)] = pair<string, string>(input[i].substr(7, 3), input[i].substr(12, 3));
    }
    int direction_count = directions.size();
    string current_node = "AAA";
    int steps = 0;
    while(current_node != "ZZZ") {
        current_node = 'L' == directions[steps%direction_count]
            ? nodes.at(current_node).first
            : nodes.at(current_node).second;
        steps++;
    }
    return std::to_string(steps);
}
}
