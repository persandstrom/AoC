#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include <set>

using namespace std;

namespace day_12_part_01 {

bool is_allowed(const string & str, const string & templ) {
    for (int i=0; i<str.size(); i++) {
        if(templ[i] != '?' && templ[i]!=str[i]) {
            return false;
        }
    }
    return true;
}

void get_variants(const int size, const vector<int>& format, const int format_pos, string so_far, vector<string>& variants, const string & templ) {

    for (int i = 0; i<size; i++) {
        if(format_pos>0 || i > 0) {
            so_far+=".";
        }
        string new_str = so_far + string(format[format_pos], '#');
        if(new_str.size() > size || !is_allowed(new_str, templ)) {
            continue;
        }
        if (format_pos==format.size()-1) {
            new_str.insert(new_str.end(), size - new_str.size(), '.');
            if(is_allowed(new_str, templ)) {
                variants.push_back(new_str);
            }
        } else {
            get_variants(size, format, format_pos+1, new_str, variants, templ);
        }
    }

}

std::string run(FileReader& reader) {
    int arrangements = 0;
    reader.for_each_line([&arrangements](const string & line){
        string format1 = line.substr(0, line.find(' '));
        vector<int> format2 = aoc::csv_to_vector<int>(line.substr(line.find(' ')), ',');

        vector<string> variants;
        get_variants(format1.size(), format2, 0, "", variants, format1);
        arrangements+=variants.size();

    });

    return std::to_string(arrangements);
}
}
