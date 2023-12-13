#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include <map>

using namespace std;

namespace day_12_part_02 {

bool is_allowed(const string & str, const string & templ) {
    for (uint64_t i=0; i<str.size(); i++) {
        if(templ[i] != '?' && templ[i]!=str[i]) {
            return false;
        }
    }
    return true;
}

int64_t get_variants(const uint64_t size, const vector<uint64_t>& format, const uint64_t format_pos, string so_far, const string & templ, map<pair<uint64_t, uint64_t>, uint64_t>& memo) {
    uint64_t variants = 0;
    auto p = make_pair(so_far.size(),format_pos);
    if (memo.find(p) != memo.end()) {
        return memo[p];
    }
    for (uint64_t i = 0; i<size; i++) {
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
                variants++;
            }
        } else {
            variants+=get_variants(size, format, format_pos+1, new_str, templ, memo);
        }
    }
    memo[p]=variants;
    return variants;

}

std::string run(FileReader& reader) {
    uint64_t arrangements = 0;
    reader.for_each_line([&arrangements](const string & line){
        string format1 = line.substr(0, line.find(' '));
        format1 = format1+"?"+format1+"?"+format1+"?"+format1+"?"+format1;
        string part2 = line.substr(line.find(' ')+1);
        part2 = part2+","+part2+","+part2+","+part2+","+part2;
        vector<uint64_t> format2 = aoc::csv_to_vector<uint64_t>(part2,',');

        map<pair<uint64_t, uint64_t>, uint64_t> memo;
        arrangements+= get_variants(format1.size(), format2, 0, "", format1, memo);
    });

    return std::to_string(arrangements);
}
}
