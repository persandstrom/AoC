#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include "aoc_util.h"

namespace day_11_part_02 {


std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

struct visit_result {
    long ways_out;
    long paths_through_dac;
    long paths_through_fft;
    long paths_through_both;
};


std::unordered_map<std::string, std::vector<std::string>> device_map;
std::unordered_map<std::string, visit_result> paths;


visit_result visit(std::string device) {
    long ways_out = 0;
    long paths_through_dac = 0;
    long paths_through_fft = 0;
    long paths_through_both = 0;

    for (const auto& to : device_map[device]) {
        if (const auto search = paths.find(to); search != paths.end()) {
            ways_out+=search->second.ways_out;
            paths_through_dac+=search->second.paths_through_dac;
            paths_through_fft+=search->second.paths_through_fft;
            paths_through_both+=search->second.paths_through_both;
        } else {
            if (to == "out") {
                ways_out++;
            } else {
                auto res = visit(to);
                ways_out += res.ways_out;
                paths_through_dac += res.paths_through_dac;
                paths_through_fft += res.paths_through_fft;
                paths_through_both += res.paths_through_both;
            }
        }
    }
  
    if (device == "dac") {
        paths_through_dac = ways_out;
        if (paths_through_fft > 0) {
            paths_through_both = paths_through_fft;
        }
    }
    if (device == "fft") {
        paths_through_fft = ways_out;
        if (paths_through_dac > 0) {
            paths_through_both = paths_through_dac;
        }
    }

    visit_result vr{ways_out, paths_through_dac, paths_through_fft, paths_through_both};
    paths[device] = vr;
    return vr;
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
    
    auto res = visit("svr");

    return std::to_string(res.paths_through_both);
}

}
