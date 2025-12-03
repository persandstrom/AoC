#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>

namespace day_01_part_01 {

std::string run(FileReader& reader) {
    struct {
        const int dail_numbers = 100;
        int dail_position = 50;
        int zeroes = 0;
    } state;
    
    reader.for_each_line([&state](const std::string& line){
        const int direction = (line[0] == 'R') ? 1 : -1;
        const int times = stoi(line.substr(1));
        state.dail_position = (state.dail_position + direction*times)%state.dail_numbers; 
        state.zeroes += (state.dail_position == 0) ? 1 : 0;
    });
    return std::to_string(state.zeroes);
}

}
