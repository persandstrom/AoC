#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include "unordered_map"
#include <queue>

using namespace std;

namespace day_17_part_01 {


struct Crucible {
    int x;
    int y;
    char direction;
    int steps;
    int heatloss;
};

struct Intersection {
    array<int, 3> north{INT32_MAX, INT32_MAX, INT32_MAX};
    array<int, 3> east{INT32_MAX, INT32_MAX, INT32_MAX};
    array<int, 3> south{INT32_MAX, INT32_MAX, INT32_MAX};
    array<int, 3> west{INT32_MAX, INT32_MAX, INT32_MAX};
};

using Intersections = unordered_map<string, Intersection>;

auto cmp = [](const Crucible & c1, const Crucible & c2){return c1.heatloss > c2.heatloss;};
using Crucibles = priority_queue<Crucible, vector<Crucible>, decltype(cmp)>; 

void push_crucible(Intersections & intersections, Crucibles & crucibles, const Crucible & crucible ) {
    auto id = aoc::coord_to_string(crucible.x, crucible.y);
    if (intersections.count(id) == 0) {
        intersections[id] = Intersection();
    }
    if(crucible.direction=='n' && crucible.heatloss < intersections.at(id).north[crucible.steps-1]) {
        intersections.at(id).north[crucible.steps-1] = crucible.heatloss;
        crucibles.push(crucible);
    }
    if(crucible.direction=='w' && crucible.heatloss < intersections.at(id).west[crucible.steps-1]) {
        intersections.at(id).west[crucible.steps-1] = crucible.heatloss;
        crucibles.push(crucible);
    }
    if(crucible.direction=='s' && crucible.heatloss < intersections.at(id).south[crucible.steps-1]) {
        intersections.at(id).south[crucible.steps-1] = crucible.heatloss;
        crucibles.push(crucible);
    }
    if(crucible.direction=='e' && crucible.heatloss < intersections.at(id).east[crucible.steps-1]) {
        intersections.at(id).east[crucible.steps-1] = crucible.heatloss;
        crucibles.push(crucible);
    }
};

std::string run(FileReader& reader) {
    auto map = reader.to_vector();
    int height = map.size();
    int width = map.at(0).size();
    Intersections intersections;

    Crucibles crucibles(cmp); 
    crucibles.push(Crucible{0,1,'s',1,0});
    crucibles.push(Crucible{1,0,'e',1,0});
        
    int best = 6*(width+height);

    while (!crucibles.empty())
    {
        Crucible crucible = crucibles.top();
        crucibles.pop();
        crucible.heatloss += map[crucible.y][crucible.x] - '0';
        if(crucible.heatloss >= best) continue;

        if(crucible.x == width-1 && crucible.y== height-1 && crucible.heatloss < best) {
            best = crucible.heatloss;
        }

        if(crucible.direction == 's') {
            if(crucible.x>0) {
                push_crucible(intersections, crucibles, Crucible{crucible.x-1, crucible.y, 'w', 1, crucible.heatloss});
            }
            if(crucible.x<width-1) {
                push_crucible(intersections, crucibles, Crucible{crucible.x+1, crucible.y, 'e', 1, crucible.heatloss});
            }
            if(crucible.steps<3 && crucible.y<height-1) {
                push_crucible(intersections, crucibles, Crucible{crucible.x, crucible.y+1, 's', crucible.steps+1, crucible.heatloss});
            }
        }
        if(crucible.direction == 'n') {
            if(crucible.steps<3 && crucible.y>0) {
                push_crucible(intersections, crucibles, Crucible{crucible.x, crucible.y-1, 'n', crucible.steps+1, crucible.heatloss});
            }
            if(crucible.x>0) {
                push_crucible(intersections, crucibles, Crucible{crucible.x-1, crucible.y, 'w', 1, crucible.heatloss});
            }
            if(crucible.x<width-1) {
                push_crucible(intersections, crucibles, Crucible{crucible.x+1, crucible.y, 'e', 1, crucible.heatloss});
            }
        }
        if(crucible.direction == 'e') {
            if(crucible.y>0) {
                push_crucible(intersections, crucibles, Crucible{crucible.x, crucible.y-1, 'n', 1, crucible.heatloss});
            }
            if(crucible.y<height-1) {
                push_crucible(intersections, crucibles, Crucible{crucible.x, crucible.y+1, 's', 1, crucible.heatloss});
            }
            if(crucible.steps<3 && crucible.x<width-1) {
                push_crucible(intersections, crucibles, Crucible{crucible.x+1, crucible.y, 'e', crucible.steps+1, crucible.heatloss});
            }
        }
        if(crucible.direction == 'w') {
            if(crucible.steps<3 && crucible.x>0) {
                push_crucible(intersections, crucibles, Crucible{crucible.x-1, crucible.y, 'w', crucible.steps+1, crucible.heatloss});
            }
            if(crucible.y>0) {
                push_crucible(intersections, crucibles, Crucible{crucible.x, crucible.y-1, 'n', 1, crucible.heatloss});
            }
            if(crucible.y<height-1) {
                push_crucible(intersections, crucibles, Crucible{crucible.x, crucible.y+1, 's', 1, crucible.heatloss});
            }
        } 
    }
    

    
        
    return std::to_string(best);
}
}
