#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"

using namespace std;

namespace day_10_part_01 {


std::string run(FileReader& reader) {
    auto input = reader.to_vector();

    int sx=0; int sy=0;
    for (int y=0; y<input.size(); y++) {
        for (int x=0; x<input[y].size(); x++) {
            if (input[y][x] == 'S') {
                sx = x;
                sy = y;
            }
        }
    }
    
    int cy = sy;
    int cx = sx;
    int lx = cx;
    int ly = cy;
    int steps = 1;

    auto connects_south = [](char c) -> bool{ return (c == '|' || c == '7' || c == 'F');};
    auto connects_north = [](char c) -> bool{ return (c == '|' || c == 'L' || c == 'J');};
    auto connects_west = [](char c) -> bool{ return (c == '-' || c == '7' || c == 'J');};
    auto connects_east = [](char c) -> bool{ return (c == '-' || c == 'F' || c == 'L');};

    char n = cy-1 >= 0 ? input[cy-1][cx] : '.';
    char w = cx-1 >= 0 ? input[cy][cx-1] : '.';
    char s = cy+1 < input.size() ? input[cy+1][cx] : '.';
    char e = cx+1 < input[0].size() ? input[cy][cx+1] : '.';
    
    if (connects_south(n)) { cy-=1; }
    else if (connects_east(w)) { cx-=1; }
    else if (connects_north(s)) { cy+=1; }
    else if (connects_west(e)) { cx+=1; }

    if (connects_south(n) && connects_east(w)) { input[sy][sx]='J'; }
    if (connects_south(n) && connects_north(s)) { input[sy][sx]='|'; }
    if (connects_south(n) && connects_west(e)) { input[sy][sx]='L'; }
    if (connects_east(w) && connects_north(s)) { input[sy][sx]='7'; }
    if (connects_east(w) && connects_west(e)) { input[sy][sx]='-'; }
    if (connects_north(s) && connects_west(e)) { input[sy][sx]='F'; }

    while (cx != sx || cy != sy)
    {
        steps++;
        char n = cy-1 >= 0 && ly != cy-1 ? input[cy-1][cx] : '.';
        char w = cx-1 >= 0 && lx != cx-1  ? input[cy][cx-1] : '.';
        char s = cy+1 < input.size()  && ly != cy+1 ? input[cy+1][cx] : '.';
        char e = cx+1 < input[0].size() && lx != cx+1 ? input[cy][cx+1] : '.';
        char c = input[cy][cx]; 
        lx = cx; ly = cy;
        if (connects_north(c)&&connects_south(n)) { cy-=1;  }
        else if (connects_west(c)&&connects_east(w)) { cx-=1; }
        else if (connects_south(c)&&connects_north(s)) { cy+=1; }
        else if (connects_east(c)&&connects_west(e)) { cx+=1; }

    }
    
    return std::to_string(steps/2);
}
}
