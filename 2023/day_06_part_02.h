#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include <algorithm>

using namespace std;

namespace day_06_part_02 {


std::string run(FileReader& reader) {
    auto input = reader.to_vector();
    auto time_str = input[0].substr(input[0].find(':')+1);
    time_str.erase(std::remove(time_str.begin(), time_str.end(), ' '), time_str.end());
    auto time = stol(time_str);
    auto record_str = input[1].substr(input[1].find(':')+1);
    record_str.erase(std::remove(record_str.begin(), record_str.end(), ' '), record_str.end());
    auto record = stol(record_str);

    long wins = 0;
    for (long press = 0; press<time; press++) {
        if ((time-press)*press > record) {
            wins++;
        }
    }

    return std::to_string(wins);
}
}
