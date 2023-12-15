#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"

using namespace std;

namespace day_15_part_02 {


std::string run(FileReader& reader) {
    auto steps = aoc::csv_to_vector<string>(reader.to_vector()[0], ',');
    vector<vector<string>> boxes(256, vector<string>());

    for (const auto & step : steps) {
        int h = 0;
        auto op = find_if(step.begin(), step.end(), [](const auto & c){return c=='-' || c=='=';});
        for (auto it = step.begin(); it != op; ++it) {
            h+=*it;
            h*=17;
            h = h%256;
        }
        auto it = find_if(boxes[h].begin(), boxes[h].end(), [&step, &op](const auto & s){
            int i=0;
            for(; i<op-step.begin(); i++) {
                if (s[i] != step[i]){
                    return false;
                }
            }
            return s[i] == '-' || s[i] == '=';
        });
        if (*op=='=') {
            if(it!=boxes[h].end()) {
                *it = step;
            } else {
                boxes[h].push_back(step);
            }
        } else if (it!=boxes[h].end()) {
            boxes[h].erase(it);
        }
    }
    int total = 0;
    for (int i=0; i<boxes.size(); i++) {
        for (int j=0; j<boxes[i].size(); j++) {
            total+=(i+1)*(j+1)*(boxes[i][j].back()-'0');
        }
    }
    return std::to_string(total);
}
}
