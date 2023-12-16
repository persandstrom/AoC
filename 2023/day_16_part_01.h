#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"

using namespace std;



namespace day_16_part_01 {

std::string run(FileReader& reader) {
    auto cave = reader.to_vector();
    int height = cave.size();
    int width = cave.at(0).size();
    auto w_beams = vector<string>(height, string(width, ' '));
    auto e_beams = vector<string>(height, string(width, ' '));
    auto n_beams = vector<string>(height, string(width, ' '));
    auto s_beams = vector<string>(height, string(width, ' '));

    e_beams[0][0]='!';


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
    
    return std::to_string(energized);
}
}
