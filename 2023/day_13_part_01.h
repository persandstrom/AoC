#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include <set>

using namespace std;

namespace day_13_part_01 {

bool is_mirror(const vector<string>& v, int i) {
    i--;
    int j=i+3;
    while (i>=0 && j<v.size())
    {
        
        if (v[i]!=v[j]) {
            return false;
        }
        i--; j++;
    }
    return true;
    
}

int calculate(const vector<string>& v) {
    for(int i=1; i<v.size(); i++) {
        if (v[i-1] == v[i] && is_mirror(v, i-1)) {
            return i;
        }
    }
    return 0;
};

vector<string> transform(vector<string> v) {
    vector<string> t(v[0].size(), "");
    for (int i = v.size()-1; i>=0; i--) {
        for (int j=0; j<v[0].size(); j++) {
            t[j]+=v[i][j];
        }
    }
    return t;
}

std::string run(FileReader& reader) {
    int total=0;

    vector<string> v1;
    vector<string> v2;
    vector<string> input = reader.to_vector();
    for (int i=0; i<=input.size(); i++) {
        if(input[i] == "" || i == input.size()) {
            v2=transform(v1);
            total+=100*calculate(v1);
            total+=calculate(v2);
            v1.clear();
            v2.clear();
        } else {
            v1.push_back(input[i]);
        }
    };
    return std::to_string(total);
}
}
