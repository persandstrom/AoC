#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

namespace day_08_part_02 {

std::string run(FileReader& reader) {
    unordered_map<string, pair<string, string>> nodes;
    vector<string> current_nodes;
    auto input = reader.to_vector();
    string directions = input.at(0);
    for (int i = 2; i<input.size(); i++) {
        nodes[input[i].substr(0, 3)] = pair<string, string>(input[i].substr(7, 3), input[i].substr(12, 3));
        if (input[i][2] == 'A') {
            current_nodes.push_back(input[i].substr(0,3));
        }
    }
    int direction_count = directions.size();
    vector<int> first_z(current_nodes.size(), 0);

    for (int i=0; i<current_nodes.size(); i++) {
        int step = 0;
        while (first_z[i] == 0)
        {
            current_nodes[i] = 'L' == directions[step%direction_count]
                ? nodes.at(current_nodes[i]).first
                : nodes.at(current_nodes[i]).second;
            step++;
            if(current_nodes[i][2] == 'Z') {
                first_z[i] = step;
            }

        }        
    }
    int64_t steps = first_z[0];
    for (int i = 1; i<first_z.size(); i++) {
        steps = std::lcm(steps, first_z[i]);
    }
    return std::to_string(steps);
}
}
