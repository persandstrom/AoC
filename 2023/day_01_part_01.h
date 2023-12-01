#pragma once

#include <string>
#include "file_reader.h"

namespace day_01_part_01 {

std::string run(FileReader& reader) {
    
    int sum = 0;
    reader.for_each_line([&sum](const std::string& line){
        char first = 0; char last = 0;
        for (const char& c : line) {
            if (c < '0' || c > '9') continue;
            if (!first) {
                first = c;
                last = c;
            } else {
                last = c;
            }

        }
        sum += stoi(std::string{first, last});
        });
    return std::to_string(sum);
}

}
