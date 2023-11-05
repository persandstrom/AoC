#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>

#include "day_06_common.h"
#include "file_reader.h"

namespace day_06_part_01 {


std::string run(FileReader& reader) {
    std::vector<day_06::Coordinate> dangerous_coordinates;
    std::unordered_set<int> infinites;
    day_06::Extremes extremes;
    
    reader.for_each_line([&dangerous_coordinates, &extremes](const std::string & line){
        auto comma_pos = line.find(',');
        int x = std::stoi(line.substr(0, comma_pos));
        int y = std::stoi(line.substr(comma_pos+2));
        extremes.calibrate(x, y);
        dangerous_coordinates.push_back(day_06::Coordinate(x, y));
    });

    std::vector<int> closest_counts(dangerous_coordinates.size());

    for (int x=extremes.x_min; x<=extremes.x_max; x++) {
        for (int y=extremes.y_min; y<=extremes.y_max; y++) {
            int min_distance = INT_MAX;
            int closest = 0;
            for (int i=0; i<dangerous_coordinates.size(); i++) {
                auto distance = dangerous_coordinates[i].manhattan_distance(x, y);
                if (distance == min_distance) {
                    closest = INT_MAX;
                } else if (distance < min_distance) {
                    min_distance = distance;
                    closest = i;
                }
            }
            if (x==extremes.x_min || x == extremes.x_max || y == extremes.y_min || y == extremes.y_max) {
                infinites.insert(closest);
            }
            if (closest != INT_MAX)
                closest_counts[closest]++;
        }
    }
    int max_count = 0;
    for (int i=0; i<closest_counts.size(); i++) {
        if (!infinites.contains(i))
            max_count = std::max(max_count, closest_counts[i]);
    }

    return std::to_string(max_count);
}

} // END NAMESPACE
