#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"

using namespace std;

namespace day_06_part_01 {


std::string run(FileReader& reader) {
    auto input = reader.to_vector();
    auto times = aoc::csv_to_vector<int>(input[0].substr(input[0].find(':')+1));
    auto records = aoc::csv_to_vector<int>(input[1].substr(input[1].find(':')+1));

    int sum = 1;

    for (int i=0; i<times.size(); i++) {
        int wins = 0;
        for (int press = 0; press<times[i]; press++) {
            if ((times[i]-press)*press > records[i]) {
                wins++;
            }
        }
        sum*=wins;
    }

    return std::to_string(sum);
}
}
