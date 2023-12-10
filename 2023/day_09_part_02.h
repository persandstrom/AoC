#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include <unordered_map>
#include <cmath>

using namespace std;

namespace day_09_part_02 {

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

        for(int64_t i=sequences.size()-2; i>=0; i--) {
            sequences.at(i).insert(sequences.at(i).begin(), sequences.at(i).front() - sequences.at(i+1).front());
        }

        sum+=sequences.at(0).front();
    });
    return std::to_string(sum);
}
}
