#pragma once

#include <string>
#include "file_reader.h"

namespace day_02_part_02 {

std::string run(FileReader& reader) {

    std::vector<std::string> input;
    reader.for_each_line([&input](const std::string& line){
        input.push_back(line);
    });
    for (auto it1 = input.begin(); it1 != input.end(); it1++) {
        for (auto it2 = it1+1; it2 != input.end(); it2++) {
            int diff = -1;
            for (int i = 0; i<it1->size(); i++) {
                
                if (it1->at(i) != it2->at(i)) {
                    if (diff >= 0) {
                        diff = -1;
                        break;
                    }
                    diff = i;
                }
            }
            if (diff >=0) {
                return it1->erase(diff,1);
            }
        }
    }
    return "";
}

}
