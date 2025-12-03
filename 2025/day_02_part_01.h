#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>

namespace day_02_part_01 {

std::string run(FileReader& reader) {
    std::string data;
    reader.read_line(data);

    long res = 0;

    std::string::size_type pos = 0;
    while (true) {
        auto pos1 = data.find('-', pos);
        
        auto pos2 = data.find(',', pos1);
        auto r_start = stol(data.substr(pos, pos1-pos));
        auto r_end = stol(data.substr(pos1+1, pos2-pos1));
        
        for (auto i = r_start; i <= r_end; i++){
            std::string istr = std::to_string(i);
            if (istr.length() % 2 != 0) continue;
            if (istr.substr(0, istr.length()/2) == istr.substr(istr.length()/2)) {
                res += i; 
            }
        }
        
        if (pos2 == std::string::npos) break;
        pos = pos2+1; 
        
    }


    return std::to_string(res);
}

}
