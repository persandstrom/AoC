#pragma once

#include <string>
#include "file_reader.h"

namespace day_01_part_01 {

std::string run(FileReader& reader) {
    
    int frequency = 0;
    reader.for_each_line([&frequency](const std::string& line){ frequency += stoi(line); });
    return std::to_string(frequency);
}

}
