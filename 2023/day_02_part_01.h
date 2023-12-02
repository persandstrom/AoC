#pragma once

#include <string>
#include "file_reader.h"
#include <unordered_map>

using namespace std;

namespace day_02_part_01 {

std::string run(FileReader& reader) {
    int sum = 0; int game = 0;
    const std::unordered_map<char, int> max_color = {{'r', 12}, {'g', 13}, {'b', 14}};
    
    reader.for_each_line([&sum, &game, max_color](const std::string& line){
        game++;
        size_t pos = 0;
        size_t oldpos = line.find(" ", line.find(" ")+1);
        
        while ((pos = line.find(" ", oldpos)) != std::string::npos) {
            auto end_nr_pos = line.find(" ", pos+1);
            int number = stoi(line.substr(pos,end_nr_pos));
            char color_char = line[end_nr_pos+1];
            if (number > max_color.at(color_char)) {
                return;
            }

            oldpos = end_nr_pos+1;
        }
        
        sum += game;
        });
    return std::to_string(sum);
}

}
