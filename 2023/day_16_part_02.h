#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"

using namespace std;

namespace day_16_part_02 {


int energize(const vector<string>& cave, int sy, int sx, char direction) {

    int height = cave.size();
    int width = cave.at(0).size();
    auto w_beams = vector<string>(height, string(width, ' '));
    auto e_beams = vector<string>(height, string(width, ' '));
    auto n_beams = vector<string>(height, string(width, ' '));
    auto s_beams = vector<string>(height, string(width, ' '));

    if (direction=='w') {
        w_beams[sy][sx] = '!';
    }
    if (direction=='e') {
        e_beams[sy][sx] = '!';
    }
    if (direction=='n') {
        n_beams[sy][sx] = '!';
    }
    if (direction=='s') {
        s_beams[sy][sx] = '!';
    }

    bool added=true;
    while(added)
    {
        added=false;
        for(int y=0; y<height; y++) {
            for(int x=0; x<width; x++) {
                // EAST
                if(e_beams[y][x]=='!') {
                    added = true;
                    e_beams[y][x] = '#';
                    if((cave[y][x]=='.' || cave[y][x]=='-') && x+1<width && e_beams[y][x+1] == ' ') {
                        e_beams[y][x+1] = '!';
                    }
                    if((cave[y][x]=='/' || cave[y][x]=='|') && y>0 && n_beams[y-1][x] == ' ') {
                        n_beams[y-1][x] = '!';
                    }
                    if((cave[y][x]=='\\' || cave[y][x]=='|') && y+1<height && s_beams[y+1][x] == ' ') {
                        s_beams[y+1][x] = '!';
                    }
                }
                // WEST
                if(w_beams[y][x]=='!') {
                    added = true;
                    w_beams[y][x] = '#';
                    if((cave[y][x]=='.' || cave[y][x]=='-') && x>0 && w_beams[y][x-1] == ' ') {
                        w_beams[y][x-1] = '!';
                    }
                    if((cave[y][x]=='/' || cave[y][x]=='|') && y+1<height && s_beams[y+1][x] == ' ') {
                        s_beams[y+1][x] = '!';
                    }
                    if((cave[y][x]=='\\' || cave[y][x]=='|') && y>0 && n_beams[y-1][x] == ' ') {
                        n_beams[y-1][x] = '!';
                    }
                }
                
                // NORTH
                if(n_beams[y][x]=='!') {
                    added=true;
                    n_beams[y][x]='#';
                    if((cave[y][x]=='.' || cave[y][x]=='|') && y>0 && n_beams[y-1][x] == ' ') {
                        n_beams[y-1][x] = '!';
                    }
                    if((cave[y][x]=='/' || cave[y][x]=='-') && x+1<width && e_beams[y][x+1] == ' ') {
                        e_beams[y][x+1] = '!';
                    }
                    if((cave[y][x]=='\\' || cave[y][x]=='-') && x>0 && w_beams[y][x-1] == ' ') {
                        w_beams[y][x-1] = '!';
                    }
                }
                
                // SOUTH
                if(s_beams[y][x]=='!') {
                    added=true;
                    s_beams[y][x]='#';
                    if((cave[y][x]=='.'||cave[y][x]=='|') && y+1<height && s_beams[y+1][x] == ' ') {
                        s_beams[y+1][x] = '!';
                    }
                    if((cave[y][x]=='/' || cave[y][x]=='-') && x>0 && w_beams[y][x-1] == ' ') {
                        w_beams[y][x-1] = '!';
                    }
                    if((cave[y][x]=='\\' || cave[y][x]=='-') && x+1<width && e_beams[y][x+1] == ' ') {
                        e_beams[y][x+1] = '!';
                    }
                }
            }       
        }
    }

    int energized=0;
    for (int y=0;y<height;y++) {
        for (int x=0;x<width;x++) {
            if (e_beams[y][x]=='#' || w_beams[y][x]=='#' || n_beams[y][x]=='#' || s_beams[y][x]=='#') energized++;
        }
    }
    return energized;
}

std::string run(FileReader& reader) {
    auto cave = reader.to_vector();

    int max_energized=0;
    for (int i=0; i<cave.size();i++) {
        max_energized = max(max_energized, energize(cave, 0, i, 's'));
        max_energized = max(max_energized, energize(cave, cave.size()-1, i, 'n'));
    }
    for (int i=0; i<cave.at(0).size();i++) {
        max_energized = max(max_energized, energize(cave, i, 0, 'e'));
        max_energized = max(max_energized, energize(cave, i, cave.at(0).size(), 'w'));
    }


    
    return std::to_string(max_energized);
}
}
