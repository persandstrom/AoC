#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>
#include <vector>
#include <algorithm>

namespace day_12_part_01 {

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

std::string run(FileReader& reader) {
    
    auto input = reader.to_vector();
    bool reading_shapes = true;
    

    int fits = 0;

    for (int i=6*5; i<input.size(); i++) {
        auto s = split(input[i], ':');
        auto r = split(s[0], 'x');
        int n = std::stoi(r[0]);
        int m = std::stoi(r[1]);

        std::vector<int> shape_nrs;
        for (const auto& a : split(s[1], ' ')) {
            if (a != "")
                shape_nrs.push_back(std::stoi(a));
        }
        
        int tot_area = n * m;
        int npresents = 0;
        for (int j=0; j<shape_nrs.size(); j++) {
            npresents += shape_nrs[j]*9;
        }
        if (npresents <= tot_area)
            fits++;
    }

    return std::to_string(fits);
}

}
