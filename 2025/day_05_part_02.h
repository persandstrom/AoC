#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>
#include "aoc_util.h"

#include <iostream>
#include <sstream>
#include <vector>

namespace day_05_part_02 {

struct range {
    long start=0;
    long end=0;
};

bool comp(range a, range b)
{
    return a.start < b.start;
}

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


    std::vector<range> ranges;
    long res = 0;
    auto input = reader.to_vector();


    for(const auto& row : input) {
        if (row == "") {
            break;
        }
        auto s = split(row, '-');
        range r {std::stol(s[0]), std::stol(s[1])};
        ranges.push_back(r);
    }

    std::sort(ranges.begin(), ranges.end(), comp);

    std::vector<range> joined_ranges;

    range r1 = ranges[0];
    for (const auto& r2 : ranges) {
        if (r1.end >= r2.start) {
            
            r1.end = std::max(r1.end, r2.end); 
        }
        else {
            joined_ranges.push_back(r1);
            r1 = r2;
        }
    }
    joined_ranges.push_back(r1);

    for (const range& r : joined_ranges) {
        res += r.end - r.start +1;
    }

    return std::to_string(res);
}

}
