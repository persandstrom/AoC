#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>
#include "aoc_util.h"

namespace day_04_part_02 {

std::string run(FileReader& reader) {
    int res = 0;

    auto matrix = reader.to_vector();

    bool any_removed = true;

    while (any_removed) {
        any_removed = false;
        for (int y = 0; y<matrix.size(); y++) {
            for (int x = 0; x< matrix[y].length(); x++) {
                if (matrix[y][x] == '.' ) continue;
                int adjecent_papers = 0;
                aoc::check_adjecent(matrix, x, y, [&adjecent_papers](char c){
                        adjecent_papers += (c == '@' || c == 'x') ? 1 : 0;});
                if (adjecent_papers < 4) {
                    res++;
                    matrix[y][x] = 'x';
                    any_removed  = true;
                }
            }
        }
        for (int y = 0; y<matrix.size(); y++) {
            for (int x = 0; x< matrix[y].length(); x++) {
                if (matrix[y][x] == 'x')
                    matrix[y][x] = '.';
            }
        }
    }


    return std::to_string(res);

    
}

}
