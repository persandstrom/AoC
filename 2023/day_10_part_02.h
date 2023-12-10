#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include <unordered_set>

using namespace std;

namespace day_10_part_02 {

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
    

    unordered_set<string> loop_elements{aoc::coord_to_string(sx,sy)};
    while (cx != sx || cy != sy)
    {
        char n = cy-1 >= 0 && ly != cy-1 ? input[cy-1][cx] : '.';
        char w = cx-1 >= 0 && lx != cx-1  ? input[cy][cx-1] : '.';
        char s = cy+1 < input.size()  && ly != cy+1 ? input[cy+1][cx] : '.';
        char e = cx+1 < input[0].size() && lx != cx+1 ? input[cy][cx+1] : '.';
        char c = input[cy][cx]; 
        lx = cx; ly = cy;
        loop_elements.insert(aoc::coord_to_string(cx, cy));
        if (connects_north(c)&&connects_south(n)) { cy-=1;  }
        else if (connects_west(c)&&connects_east(w)) { cx-=1; }
        else if (connects_south(c)&&connects_north(s)) { cy+=1; }
        else if (connects_east(c)&&connects_west(e)) { cx+=1; }

    }
    
    int count=0;
    for (int y=0; y<input.size(); y++) {
        char corner = '.';
        bool inside=false;
        for (int x=0; x<input[0].size(); x++) {
            char c = input[y][x];
            if (loop_elements.find(aoc::coord_to_string(x,y)) == loop_elements.end()){
                if(inside) {
                    count++;
                }
            } else {
                if (c=='|') {
                    inside = !inside;
                }
                if (c == 'J' && corner == 'F') {
                    inside = !inside;
                }
                if (c == '7' && corner == 'L') {
                    inside = !inside;
                }
                if (c == 'L' || c == 'F') {
                    corner = c;
                }
            }
        }
    }



    return std::to_string(count);
}
}
