#pragma once

#include <string>
#include <vector>
#include <unordered_set>

#include "../common/file_reader.h"

namespace day_01_part_02 {

std::string run(FileReader& reader) {
    std::vector<int> input;
    reader.for_each_line([&input](const std::string& line){input.push_back(stoi(line));});
    
    int current_frequency = 0;
    std::unordered_set<int> frequencies {0};

    while (true) {
        for (auto freq_mod : input)
        {
            current_frequency = current_frequency + freq_mod;
            if (frequencies.find(current_frequency) != frequencies.end()) {
                return std::to_string(current_frequency);
            }
            frequencies.insert(current_frequency);
        }
    }
}

}
