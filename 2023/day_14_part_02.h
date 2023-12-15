#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include <set>
#include <functional>
#include <sstream>
#include <iterator>

using namespace std;

namespace day_14_part_02 {

void move_north(vector<string>& dish, int i, int j) {
    if (i==0) {
        return;
    }
    if (dish[i-1][j] != '.') {
        return;
    }
    else {
        dish[i-1][j] = 'O';
        dish[i][j] = '.';
        move_north(dish, i-1, j); 
    }
}

void move_west(vector<string>& dish, int i, int j) {
    if (j==0) {
        return;
    }
    if (dish[i][j-1] != '.') {
        return;
    }
    else {
        dish[i][j-1] = 'O';
        dish[i][j] = '.';
        move_west(dish, i, j-1); 
    }
}

void move_south(vector<string>& dish, int i, int j) {
    if (i==dish.size()-1) {
        return;
    }
    if (dish[i+1][j] != '.') {
        return;
    }
    else {
        dish[i+1][j] = 'O';
        dish[i][j] = '.';
        move_south(dish, i+1, j); 
    }
}

void move_east(vector<string>& dish, int i, int j) {
    if (j==dish[0].size()-1) {
        return;
    }
    if (dish[i][j+1] != '.') {
        return;
    }
    else {
        dish[i][j+1] = 'O';
        dish[i][j] = '.';
        move_east(dish, i, j+1); 
    }
}

int calculate_wight(vector<string>& dish) {
    int weight=0;
    for (int i=0; i<dish.size(); i++) {
        for (int j=0; j<dish[0].size(); j++) {
            if (dish[i][j] == 'O') {
                weight += dish.size() - i;
            }
        }
    }
    return weight;
}


std::string run(FileReader& reader) {
    int total=0;
    auto dish = reader.to_vector();
    vector<size_t> hashes;
    auto among_hashes = [&hashes](const vector<string>& v)->int{
        std::ostringstream imploded;
        std::copy(v.begin(), v.end(), ostream_iterator<string>(imploded));
        auto v_hash = std::hash<string>{}(imploded.str());
        auto hashes_it = std::find(hashes.begin(), hashes.end(), v_hash);
        if (hashes_it != hashes.end()) {
            return hashes.end() - hashes_it;
        } else {
            hashes.push_back(v_hash);
            return 0;
        }
    };

    for (int tilt = 0; tilt<1000000000; tilt++) {
        for (int i=0; i<dish.size(); i++) {
            for (int j=0; j<dish[0].size(); j++) {
                if (dish[i][j] == 'O') {
                    move_north(dish, i, j);
                }
            }
        }
        for (int i=0; i<dish.size(); i++) {
            for (int j=0; j<dish[0].size(); j++) {
                if (dish[i][j] == 'O') {
                    move_west(dish, i, j);
                }
            }
        }
        for (int i=dish.size()-1; i>=0; i--) {
            for (int j=0; j<dish[0].size(); j++) {
                if (dish[i][j] == 'O') {
                    move_south(dish, i, j);
                }
            }
        }
        for (int i=0; i<dish.size(); i++) {
            for (int j=dish[0].size()-1; j>=0; j--) {
                if (dish[i][j] == 'O') {
                    move_east(dish, i, j);
                }
            }
        }
        if (int prev = among_hashes(dish); prev != 0) {
            tilt = 1000000000 - (1000000000-tilt)%prev;
            hashes.clear();
        }
    }
    return std::to_string(calculate_wight(dish));
}
}
