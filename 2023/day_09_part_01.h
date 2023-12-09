#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include <unordered_map>
#include <ranges>
#include <cmath>

using namespace std;

namespace day_09_part_01 {

std::string run(FileReader& reader) {
    int64_t sum = 0;
    vector<vector<int64_t>> sequences;
    reader.for_each_line([&sum, &sequences](const string & line){
        sequences.clear();
        sequences.push_back(aoc::csv_to_vector<int64_t>(line));
        while(!all_of(sequences.back().begin(), sequences.back().end(), [](const int64_t & a){return a==0;}) && sequences.back().size() > 1) {
            vector<int64_t> sequence;
            for (int i=1; i<sequences.back().size(); i++) {
                sequence.push_back(sequences.back().at(i) - sequences.back().at(i-1));
            }
            sequences.push_back(sequence);
        }

        //sequences.back().push_back(0);
        for(int64_t i=sequences.size()-2; i>=0; i--) {
            sequences.at(i).push_back(sequences.at(i).back() + sequences.at(i+1).back());
        }

        sum+=sequences.at(0).back();
    });
    return std::to_string(sum);
}
}
