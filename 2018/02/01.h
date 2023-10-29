#pragma once

#include <string>
#include "../common/file_reader.h"

namespace day_02_part_01 {

std::string run(FileReader& reader) {
    int twos = 0;
    int threes = 0;
    reader.for_each_line([&twos, &threes](const std::string& line){
        int vals[27]{0};
        for (auto& c : line) {
            vals[c - 'a']++;
        }
        if (std::find(std::begin(vals), std::end(vals), 2) != std::end(vals)) {
            twos++;
        }
        if (std::find(std::begin(vals), std::end(vals), 3) != std::end(vals)) {
            threes++;
        }
    });

    return std::to_string(twos*threes);
    
}

}