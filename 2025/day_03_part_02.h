#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>

namespace day_03_part_02 {

std::string run(FileReader& reader) {
    long res = 0;
    reader.for_each_line([&res](const std::string& line){
        std::string joltage = "000000000000";
        int start = 0;
        for (int i = 0; i<12; i++){
            for (int j = start; j < line.length() - 11 + i; j++) {
                if (joltage[i] < line[j]){
                    joltage[i] = line[j];
                    start = j+1;
                }
            }
        }
        res += std::stol(joltage);
    });
    return std::to_string(res);
}

}
