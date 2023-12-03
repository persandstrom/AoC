#pragma once

#include <string>
#include <unordered_map>
#include "file_reader.h"
#include "aoc_util.h"

using namespace std;

namespace day_03_part_01 {

std::string run(FileReader& reader) {
    
    auto input = reader.to_vector();
    int sum = 0;
    
    for (int y=0; y<input.size(); y++) {
        bool nr_found = false;
        bool adjacent_symbol = false;
        int nr_start=0;
        for (int x=0; x<input[y].size(); x++) {
            if (!nr_found && input[y][x] >= '0' && input[y][x] <= '9') {
                nr_found = true;
                nr_start = x;
                adjacent_symbol = false;
            } else if (nr_found && (input[y][x] < '0' || input[y][x] > '9')) {
                nr_found = false;
                if(adjacent_symbol) {
                    sum+=stoi(input[y].substr(nr_start, x-nr_start));
                    adjacent_symbol=false;
                }
            }
            if (nr_found) {
                aoc::check_adjecent(input, x, y, [&adjacent_symbol](char c){
                    adjacent_symbol |= (c != '.' && ( c<'0' || c>'9'));});
            }
        }
        if (nr_found && adjacent_symbol) {
            sum+=stoi(input[y].substr(nr_start, input[y].size()-nr_start));
        }
    }
    
    return std::to_string(sum);
}

}
