#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include <set>

using namespace std;

namespace day_14_part_01 {

int move(vector<string>& dish, int i, int j) {
    if (i==0) {
        return dish.size();
    }
    if (dish[i-1][j] != '.') {
        return dish.size() - i;
    }
    else {
        dish[i-1][j] = 'O';
        dish[i][j] = '.';
        return move(dish, i-1, j); 
    }
}

std::string run(FileReader& reader) {
    int total=0;
    auto dish = reader.to_vector();
    for (int i=0; i<dish.size(); i++) {
        for (int j=0; j<dish[0].size(); j++) {
            if (dish[i][j] == 'O') {
                total += move(dish, i, j);
            }
        }
    }
    return std::to_string(total);
}
}
