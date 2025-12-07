#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>
#include <vector>

namespace day_07_part_01 {


std::string run(FileReader& reader) {

    long splits = 0;
    auto input = reader.to_vector();
    int w = input[0].size();
    int h = input.size();

    
    for (int x=0; x<w; x++) {
        if (input[0][x] == 'S') {
            input[1][x] = '|';
        }
    }

    for (int y=1; y<h-1; y++) {
        for (int x=0; x<w; x++) {
            if (input[y][x] == '|') {
                if (input[y+1][x] == '.') {
                    input[y+1][x] = '|';
                } else if (input[y+1][x] == '^') {
                    input[y+1][x-1] = '|';
                    input[y+1][x+1] = '|';
                    splits++;
                }
            }
        }
    }

    return std::to_string(splits);
}

}
