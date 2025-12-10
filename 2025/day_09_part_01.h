#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>
#include <vector>
#include <cmath>

namespace day_09_part_01 {


std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

struct point {
    long x;
    long y;
};

std::string run(FileReader& reader, int connections=1000) {

    auto input = reader.to_vector();
    long max_area = 0;
    std::vector<point> points;

    for (auto const& line : input) {
       const auto s = split(line, ',');
       points.push_back(point{std::stol(s[0]), std::stol(s[1])});
    }
    std::vector<long> areas;

    for (int i = 0; i<points.size()-1; i++) {
        for (int j = i+1; j<points.size(); j++) {
            max_area = std::max(
                max_area,
                (1+std::abs(points[i].x-points[j].x))*(1+std::abs(points[i].y-points[j].y)));
        }
    }

    return std::to_string(max_area);
}

}
