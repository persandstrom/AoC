#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include "unordered_map"
#include <queue>

using namespace std;

namespace day_18_part_01 {



std::string run(FileReader& reader) {
    auto input = reader.to_vector();
    int prev_x = 0;
    int prev_y = 0;
    int sum = 0;
    int tot_len=0;
    for(int i=0; i<input.size(); i++) {
        char d = input[i][0];
        int l = stoi(input[i].substr(1, input[0].find(2, ' ')));
        tot_len+=l;
        int new_x = prev_x;
        int new_y = prev_y;
        if(d == 'R') {
            new_x+=l;
        }
        if(d == 'L') {
            new_x-=l;
        }
        if(d == 'U') {
            new_y+=l;
        }
        if(d == 'D') {
            new_y-=l;
        }
        sum += prev_x*new_y-prev_y*new_x;
        
        prev_x = new_x;
        prev_y = new_y;
    }
     
    return std::to_string(abs(sum/2) + tot_len/2 +1);
}
}
