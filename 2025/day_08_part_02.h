#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>
#include <vector>
#include <cmath>
#include <unordered_map>

namespace day_08_part_02 {


struct pair {
    std::string a = "";
    std::string b = "";
    long d;
};

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

long calculate_distance(std::string a, std::string b) {
    auto a_split = split(a,',');
    auto b_split = split(b,',');
    long d = 0;

    return  std::pow(std::stol(a_split[0])-std::stol(b_split[0]), 2) +
            std::pow(std::stol(a_split[1])-std::stol(b_split[1]), 2) +
            std::pow(std::stol(a_split[2])-std::stol(b_split[2]), 2);
}

std::string run(FileReader& reader, int connections=1000) {

    auto input = reader.to_vector();
    long res = 0;
    std::vector<pair> distances;
    std::vector<std::vector<std::string>> circuits;
    circuits.reserve(1000); 

    for (int i = 0; i<input.size()-1; i++) {
        circuits.push_back(std::vector{input[i]});
        auto a = input[i];
        for (int j=i+1; j<input.size(); j++) {
            auto b = input[j];
            pair p(a,b,calculate_distance(a,b));
            distances.push_back(p);
        }
    }
    circuits.push_back(std::vector{input[input.size()-1]});

    std::sort(
        distances.begin(), distances.end(), 
        [](const pair& a, const pair& b){return a.d < b.d;});


    for (int i=0; i<distances.size(); i++) {
        int c_a = -1;
        int c_b = -1;
        for (int j=0; j<circuits.size();j++) {
            for (int k=0; k<circuits[j].size(); k++) {
                if (distances[i].a == circuits[j][k])
                {
                    c_a = j;
                }
                if (distances[i].b == circuits[j][k])
                {
                    c_b = j;
                }
            }
        }

        if (c_a != c_b) {
            circuits[c_a].insert(circuits[c_a].end(), circuits[c_b].begin(), circuits[c_b].end());
            circuits.erase(circuits.begin() + c_b);
        }

        if (circuits.size() == 1)
        {
            std::vector<std::string> a_v = split(distances[i].a, ',');
            std::vector<std::string> b_v = split(distances[i].b, ',');
            return std::to_string(std::stol(a_v[0]) * std::stol(b_v[0]));
        }
    }
    

    return "-1";
}

}
