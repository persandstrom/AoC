#pragma once

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <cmath>
#include <ranges>

#include "file_reader.h"

namespace day_05_part_01 {


std::string run(FileReader& reader) {
    constexpr char remove = 0x01; 
    std::string input;
    reader.read_line(input);
    
    auto lpos = input.begin();
    auto rpos = lpos + 1;

    while (rpos < input.end())
    {
        if (std::abs(*lpos - *rpos) == 0x20) {
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
    auto result = std::ranges::count_if(input.begin(), input.end(), [](const char& a){return a != remove;});
    return std::to_string(result);
}

} // END NAMESPACE
