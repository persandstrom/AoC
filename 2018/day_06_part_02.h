#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <climits> 
#include <unordered_set>
#include <stdio.h>

#include "file_reader.h"
#include "day_06_common.h"

namespace day_06_part_02 {

int MAX_TOTAL_DISTANCE = 10000;


std::string run(FileReader& reader) {
    std::vector<day_06::Coordinate> safe_coordinates;
    day_06::Extremes extremes;
    
    reader.for_each_line([&safe_coordinates, &extremes](const std::string & line){
        auto comma_pos = line.find(',');
        int x = std::stoi(line.substr(0, comma_pos));
        int y = std::stoi(line.substr(comma_pos+2));
        extremes.calibrate(x, y);
        safe_coordinates.push_back(day_06::Coordinate(x, y));
    });

    int safe_region_count = 0;

    for (int y=extremes.y_min; y<=extremes.y_max; y++) {
        for (int x=extremes.x_min; x<=extremes.x_max; x++) {
            int sum_distance = 0;
            for (int i=0; i<safe_coordinates.size(); i++) {
                sum_distance += safe_coordinates[i].manhattan_distance(x, y);
            }
            if (sum_distance < MAX_TOTAL_DISTANCE) {
                safe_region_count++;
            }
        }
    }

    return std::to_string(safe_region_count);
}

} // END NAMESPACE
