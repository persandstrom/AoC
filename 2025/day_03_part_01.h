#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>

namespace day_03_part_01 {

std::string run(FileReader& reader) {
    int res = 0;
    reader.for_each_line([&res](const std::string& line){
        char pos_1 = 0;
        
        for (int i = 1; i<line.length()-1; i++) {
            if (line[i] > line[pos_1])
                pos_1 = i; 
        }
        char pos_2 = pos_1 + 1;
        for (int i = pos_2+1; i<line.length(); i++) {
            if (line[i] > line[pos_2])
                pos_2 = i; 
        }
        std::string number {line[pos_1], line[pos_2]};
        res += std::stoi(number);
    });
    return std::to_string(res);
}

}
