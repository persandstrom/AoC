#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>
#include <vector>

namespace day_11_part_01 {

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}


std::unordered_map<std::string, std::vector<std::string>> device_map;
std::unordered_map<std::string, int> paths_out;

int visit(std::string device) {
    int ways_out = 0;
    for (const auto& to : device_map[device]) {
        if (auto search = paths_out.find(to); search != paths_out.end()) {
            ways_out+=search->second;
        } else {
            if (to == "out") {
                ways_out++;
            } else {
                ways_out+=visit(to);
            }
        }
    }
    paths_out[device] = ways_out;
    return ways_out;
}


std::string run(FileReader& reader) {

    auto input = reader.to_vector();

    for (const auto& line : input) {
        auto s1 = split(line, ':');
        std::string key = s1[0];
        std::vector<std::string> devices;
        for (const auto& device : split(s1[1], ' ')) {
            if (device != "") {
                devices.push_back(device);
            }
        }
        device_map.insert(std::pair<std::string, std::vector<std::string>>{key, devices});
    }
    
    visit("you");
    return std::to_string(paths_out["you"]);
}

}
