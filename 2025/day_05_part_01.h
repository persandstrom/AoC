#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>
#include "aoc_util.h"

#include <iostream>
#include <sstream>
#include <vector>

namespace day_05_part_01 {


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

    struct range {
        long start=0;
        long end=0;
    };
    std::vector<range> ranges;
    int res = 0;
    auto input = reader.to_vector();

    bool in_ranges = true;
    for(const auto& row : input) {
        if (row == "") {
            in_ranges = false;
            continue;
        }
        if (in_ranges) {

            auto s = split(row, '-');
            range r {std::stol(s[0]), std::stol(s[1])};
            ranges.push_back(r);
        } else {
            long ingredient = std::stol(row);
            bool fresh = false;
            for (const range& r : ranges) {
                if (ingredient >= r.start && ingredient <= r.end) {
                    fresh = true;
                
                }
            }
            if (fresh) res++;
        }
    }
    return std::to_string(res);
}

}
