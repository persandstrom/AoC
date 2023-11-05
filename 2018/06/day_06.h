#pragma once

#include <climits> 
#include <cmath>

namespace day_06 {

class Coordinate {
public:
    Coordinate(const int x, const int y) : x(x), y(y) {}

    [[nodiscard]] const int manhattan_distance(const int other_x, const int other_y) const {
        return abs(x - other_x) + abs(y - other_y);
    }

    const int x;
    const int y;
};

struct Extremes {
    int x_min = INT_MAX;
    int x_max = 0;
    int y_min = INT_MAX;
    int y_max = 0;
    
    void calibrate(int x, int y) {
        x_min = std::min(x_min, x);
        x_max = std::max(x_max, x);
        y_min = std::min(y_min, y);
        y_max = std::max(y_max, y);
    }
};

}