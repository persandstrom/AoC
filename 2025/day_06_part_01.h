#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>
#include "aoc_util.h"

#include <iostream>
#include <sstream>
#include <vector>

namespace day_06_part_01 {


std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        if (item != "") result.push_back (item);
    }

    return result;
}


std::string run(FileReader& reader) {

    long res = 0;
    auto input = reader.to_vector();
    std::vector<std::vector<std::string>> matrix; 

    for (int i=0; i<input.size(); i++) {
        matrix.push_back(split(input[i], ' '));
    }

    int h = matrix.size();
    int w = matrix[0].size();

    for (int x = 0; x<w; x++) {
        std::string op = matrix.back()[x];
        long val = std::stol(matrix[0][x]);
        for (int y = 1; y<h-1; y++) {
            if (op == "+") {
                val += std::stol(matrix[y][x]);
            } else {
                val *= std::stol(matrix[y][x]);
            }
        }
        res += val;
    }


    return std::to_string(res);
}

}
