#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include <set>

using namespace std;

namespace day_11_part_01 {

struct coordinate {
    int x;
    int y;
};

std::string run(FileReader& reader) {
    vector<coordinate> galaxies;
    auto input = reader.to_vector();
    vector<bool> empty_rows(input.size(), true);
    vector<bool> empty_columns(input[0].size(), true);
    
    for (int y=0; y<input.size(); y++) {
        for (int x=0; x<input[y].size(); x++) {
            if (input[y][x] == '#') {
                empty_rows[y] = false;
                empty_columns[x] = false;
                galaxies.push_back(coordinate{x, y});
            }
        }
    }
    
    for (int i = empty_columns.size()-1; i>=0; i--) {
        if (empty_columns[i]) {
            for (auto & galaxy : galaxies) {
                if (galaxy.x>i) {
                    galaxy.x++;
                }
            }
        }   
    }

    for (int i = empty_rows.size()-1; i>=0; i--) {
        if (empty_rows[i]) {
            for (auto & galaxy : galaxies) {
                if (galaxy.y>i) {
                    galaxy.y++;
                }
            }
        }        
    }

    int shortest=0;
    for (int i=0; i<galaxies.size()-1; i++) {
        for (int j=i+1; j<galaxies.size(); j++) {
            shortest+= abs(galaxies[i].x - galaxies[j].x) + abs(galaxies[i].y - galaxies[j].y);
        }
    }

    return std::to_string(shortest);
}
}
