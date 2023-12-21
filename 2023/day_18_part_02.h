#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include "unordered_map"
#include <queue>

using namespace std;

namespace day_18_part_02 {


uint64_t hexstr_to_int(const string & str) {
    uint64_t x;   
    std::stringstream ss;
    ss << std::hex << str;
    ss >> x;
    return x;
}

std::string run(FileReader& reader) {
    auto input = reader.to_vector();
    int64_t prev_x = 0;
    int64_t prev_y = 0;
    int64_t sum = 0;
    uint64_t tot_len=0;
    for(int i=0; i<input.size(); i++) {
        char d = input[i][input[i].find(')')-1];
        int l = hexstr_to_int(input[i].substr(input[i].find('#')+1,5));
        tot_len+=l;
        int64_t new_x = prev_x;
        int64_t new_y = prev_y;
        if(d == '0') {
            new_x+=l;
        }
        if(d == '2') {
            new_x-=l;
        }
        if(d == '3') {
            new_y+=l;
        }
        if(d == '1') {
            new_y-=l;
        }
        sum += prev_x*new_y-prev_y*new_x;
        
        prev_x = new_x;
        prev_y = new_y;
    }
     
    return std::to_string(abs(sum/2) + tot_len/2 + 1);
}
}
