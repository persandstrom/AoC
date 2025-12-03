#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>

namespace day_01_part_02 {

std::string run(FileReader& reader) {
    struct {
        const int dail_numbers = 100;
        int dail_position = 50;
        int zeroes = 0;
        int divs = 0;
    } state;
    
    reader.for_each_line([&state](const std::string& line){
        const int direction = (line[0] == 'R') ? 1 : -1;
        const int times = stoi(line.substr(1));
        const int rotations = times / (state.dail_numbers);
        const int remainder = times % state.dail_numbers;
        int new_position = (state.dail_position + direction*remainder)%state.dail_numbers;
        new_position = new_position < 0 ? state.dail_numbers + new_position : new_position;
        if (new_position == 0)
            state.zeroes++;
        else if (state.dail_position != 0) {
            state.zeroes += (direction == 1 && new_position < state.dail_position ) ? 1  : 0;
            state.zeroes += (direction == -1 && new_position > state.dail_position ) ? 1 : 0;
        }
        state.zeroes += rotations;
        state.dail_position = new_position;

    });
    return std::to_string(state.zeroes);
}

}
