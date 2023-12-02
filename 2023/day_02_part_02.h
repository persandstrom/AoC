#pragma once

#include <string>
#include "file_reader.h"
#include <unordered_map>

using namespace std;

namespace day_02_part_02 {

std::string run(FileReader& reader) {
    int sum = 0;

    reader.for_each_line([&sum](const std::string& line){
        std::unordered_map<char, int> max_color = {{'r', 0}, {'g', 0}, {'b', 0}};
        size_t pos = 0;
        size_t oldpos = line.find(" ", line.find(" ")+1);
        
        while ((pos = line.find(" ", oldpos)) != std::string::npos) {
            auto end_nr_pos = line.find(" ", pos+1);
            int number = stoi(line.substr(pos,end_nr_pos));
            char color_char = line[end_nr_pos+1];
            max_color.at(color_char) = std::max(max_color.at(color_char), number);
            oldpos = end_nr_pos+1;
        }
        
        sum += max_color.at('r') * max_color.at('g') * max_color.at('b');
        });
    return std::to_string(sum);
}

}
