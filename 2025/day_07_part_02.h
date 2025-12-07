#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>

#include <vector>

namespace day_07_part_02 {


std::string run(FileReader& reader) {

    auto input = reader.to_vector();
    int w = input[0].size();
    int h = input.size();
    std::vector<long> timelines(w,0);

    
    for (int x=0; x<w; x++) {
        if (input[0][x] == 'S') {
            input[1][x] = '|';
            timelines[x]=1;
        }
    }

    for (int y=1; y<h-1; y++) {
        std::vector<long> new_timelines(w,0);
        for (int x=0; x<w; x++) {
            if (input[y][x] == '|') {
                if (input[y+1][x] != '^') {
                    new_timelines[x] += timelines[x];
                }
                if (input[y+1][x] == '.') {
                    input[y+1][x] = '|';               
                } else if (input[y+1][x] == '^') {
                    input[y+1][x-1] = '|';
                    new_timelines[x-1] += timelines[x]; 
                    input[y+1][x+1] = '|';
                    new_timelines[x+1] += timelines[x];
                }
            }
        }
        timelines = new_timelines;
    }

    long sum = 0;
    for (const auto& i : timelines) sum += i;

    return std::to_string(sum);
}

}
