#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>
#include <vector>
#include <cmath>
#include <deque>
#include <set>

namespace day_10_part_01 {


std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

struct press_state {
    int presses;
    std::string lights;
    int next_button;
};

std::string run(FileReader& reader) {

    auto input = reader.to_vector();
    long button_presses = 0;


    for (const auto& line :input) {

        std::vector<std::vector<int>> buttons;
        std::set<std::string> visited;
        auto s1 = split(line, ']');
        auto match = s1[0].substr(1);
        auto s2 = split(s1[1], ' ');
        for (int i = 1; i<s2.size()-1; i++) {
            auto button_wiring = split(s2[i].substr(1, s2[i].size()-1), ',');
            std::vector<int> button;
            for (const auto& w : button_wiring) {
                button.push_back(std::stoi(w));
            }
            buttons.push_back(button);
        }

        std::deque<press_state> press_list;
        for (int i = 0; i<buttons.size(); i++) {
            std::string all_off;
            all_off.resize(match.size(), '.');
            press_state ps{0, all_off, i};
            press_list.push_back(ps);
        }

        int presses = 0;
        while(true) {
            auto ps = press_list.front();
            press_list.pop_front();
            presses = ps.presses+1;
            auto lights = ps.lights;
            auto next_button = ps.next_button;
            
            for (const auto& w : buttons[next_button]) {
                lights[w] = lights[w]=='#' ? '.' : '#';
            }
            if (visited.contains(lights)) continue;
            visited.insert(lights);

            //std::cout << ps.lights << " -> " << lights << " button: " << next_button << " presses " << presses << std::endl;
            if (lights == match)
                break;
            for (int i = 0; i<buttons.size(); i++) {
                press_state ps{presses, lights, i};
                press_list.push_back(ps);
            }
        }
        std::cout << presses << std::endl;
        std::cout << std::endl;
        button_presses += presses;

    }
 
    return std::to_string(button_presses);
}

}
