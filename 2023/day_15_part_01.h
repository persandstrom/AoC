#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"

using namespace std;

namespace day_15_part_01 {

std::string run(FileReader& reader) {
    auto steps = aoc::csv_to_vector<string>(reader.to_vector()[0], ',');
    int total = 0;
    for (const auto & step : steps) {
        int current = 0;
        for (const auto c : step) {
            current+=c;
            current*=17;
            current = current%256;
        }
        total+=current;
        
    }
    return std::to_string(total);
}
}
