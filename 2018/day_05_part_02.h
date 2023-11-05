#pragma once

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <cmath>
#include <ranges>

#include "file_reader.h"

namespace day_05_part_02 {


int collapse_polymer(std::string & input, const char ut1) {
    constexpr char remove = 0x01;
    auto lpos = input.begin();
    auto rpos = lpos + 1;
    char ut2 = ut1 + 0x20;

    while (rpos < input.end())
    {
        if (*lpos == ut1 || *lpos == ut2){
            *lpos = remove; lpos --;
        }
        if (*rpos == ut1 || *rpos == ut2){
            *rpos = remove; rpos ++;
        
        } if (std::abs(*lpos - *rpos) == 0x20) {
            *lpos = remove; lpos --;
            *rpos = remove; rpos ++;
        } else if (*lpos != remove && *rpos != remove) {
            rpos++;
            lpos = rpos - 1;
        } else {
            if (*rpos == remove) {
                rpos++;
            }
            if (*lpos == remove) {
                lpos--;
            }
        }
    }
    return std::ranges::count_if(input.begin(), input.end(), [](const char& a){return a != remove;});
}


std::string run(FileReader& reader) {
    auto letters = std::ranges::views::iota('A', 'Z'+1);
    std::string input;
    reader.read_line(input);
    int shortest = input.size();
    for (char c = 'A'; c<='Z'; c++) {
        auto input_copy = input;
        auto length = collapse_polymer(input_copy, c);
        shortest = std::min(length, shortest);
    }
    return std::to_string(shortest);
}

} // END NAMESPACE
