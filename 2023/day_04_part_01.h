#pragma once

#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>
#include "file_reader.h"

using namespace std;

namespace day_04_part_01 {

std::string run(FileReader& reader) {
    int sum = 0;    
    
    reader.for_each_line([&sum](const std::string& line) {
        auto start_pos = line.find(':')+1;
        std::stringstream winning_ss(line.substr(start_pos, line.find('|') - start_pos));
        std::stringstream my_number_ss(line.substr(line.find('|')+1));
        vector<int> winning_numbers;
        vector<int> my_numbers;
        char ch;
        int tmp;
        while(winning_ss >> tmp) {
            winning_numbers.push_back(tmp);
        }
        while(my_number_ss >> tmp) {
            my_numbers.push_back(tmp);
        }
        std::sort(winning_numbers.begin(), winning_numbers.end());
        std::sort(my_numbers.begin(), my_numbers.end());
        std::vector<int> wins(my_numbers.size());
        auto it = std::set_intersection(winning_numbers.begin(), winning_numbers.end(), my_numbers.begin(), my_numbers.end(), wins.begin());
        wins.resize(it-wins.begin());
        if(wins.size()==0) {
            return;
        }
        int win = 1;
        for(int i=1;i<wins.size();i++) {
            win *=2;
        }
        sum+=win;
    });

    return std::to_string(sum);
}

}
