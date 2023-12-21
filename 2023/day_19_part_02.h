#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include "unordered_map"
#include <queue>
#include <functional>

using namespace std;


namespace day_19_part_02 {

struct Range {
    string next;
    uint64_t x_min; uint64_t x_max;
    uint64_t m_min; uint64_t m_max;
    uint64_t a_min; uint64_t a_max;
    uint64_t s_min; uint64_t s_max;
};

using Rule = function<void(Range &, vector<Range>&)>;

std::string run(FileReader& reader) {
    unordered_map<string, vector<Rule>> operations;
    uint64_t accepted = 0;

    bool reading_operations = true;
    reader.for_each_line([&reading_operations, &operations, &accepted](const string & line) {
        if (line.empty()) {
            reading_operations = false;
        } else if (reading_operations) {
            string operation_name = line.substr(0, line.find('{'));
            for(auto rule_str : aoc::csv_to_vector<string>(line.substr(line.find('{')+1, line.find('}') - line.find('{')-1), ',')) {
                char comparitor = ' ';
                char variable = ' ';
                int value = 0;
                string next = "";
                if (rule_str.find('<') != rule_str.npos || rule_str.find('>') != rule_str.npos) {
                    variable = rule_str[0];
                    comparitor = rule_str[1];
                    uint64_t value = stoi(rule_str.substr(2, rule_str.find(':')-2));
                    next = rule_str.substr(rule_str.find(':')+1);
                    operations[operation_name].push_back([variable, comparitor, value, next](Range & range, vector<Range>& ranges){
                        uint64_t x_min = range.x_min; uint64_t x_max = range.x_max;
                        uint64_t m_min = range.m_min; uint64_t m_max = range.m_max;
                        uint64_t a_min = range.a_min; uint64_t a_max = range.a_max;
                        uint64_t s_min = range.s_min; uint64_t s_max = range.s_max;

                        if (comparitor == '>' && variable == 'x' && x_max > value) {
                            ranges.push_back(Range{next, max(value+1, x_min), x_max, m_min, m_max, a_min, a_max, s_min, s_max});
                            range.x_max = min(value, x_max);
                        }
                        if (comparitor == '<' && variable == 'x' && x_min < value) {
                            ranges.push_back(Range{next, x_min, min(value-1, x_max), m_min, m_max, a_min, a_max, s_min, s_max});
                            range.x_min = max(value, x_min);
                        }
                        if (comparitor == '>' && variable == 'm' && m_max > value) {
                            ranges.push_back(Range{next, x_min, x_max, max(value+1, m_min), m_max, a_min, a_max, s_min, s_max});
                            range.m_max = min(value, m_max);
                        }
                        if (comparitor == '<' && variable == 'm' && m_min < value) {
                            ranges.push_back(Range{next, x_min, x_max, m_min, min(value-1, m_max), a_min, a_max, s_min, s_max});
                            range.m_min = max(value, m_min);
                        }
                        if (comparitor == '>' && variable == 'a' && a_max > value) {
                            ranges.push_back(Range{next, x_min, x_max, m_min, m_max, max(value+1, a_min), a_max, s_min, s_max});
                            range.a_max = min(value, a_max);
                        }
                        if (comparitor == '<' && variable == 'a' && a_min < value) {
                            ranges.push_back(Range{next, x_min, x_max, m_min, m_max, a_min, min(value-1, a_max), s_min, s_max});
                            range.a_min = max(value, a_min);
                        }
                        if (comparitor == '>' && variable == 's' && s_max > value) {
                            ranges.push_back(Range{next, x_min, x_max, m_min, m_max, a_min, a_max, max(value+1, s_min), s_max});
                            range.s_max = min(value, s_max);
                        }
                        if (comparitor == '<' && variable == 's' && s_min < value) {
                            ranges.push_back(Range{next, x_min, x_max, m_min, m_max, a_min, a_max, s_min, min(value-1, s_max)});
                            range.s_min = max(value, s_min);
                        }
                    });
                } else {
                    next = rule_str;
                    operations[operation_name].push_back([next](Range & range, vector<Range>& ranges) {
                        range.next = next;
                        ranges.push_back(range);
                    });
                }
            } 
        } else {
            auto rating = aoc::csv_to_vector<string>(line.substr(1, line.size()-2),',');
            
        }

    });

    vector<Range> ranges;
    ranges.push_back(Range{"in",1,4000,1,4000,1,4000,1,4000});

    while(!ranges.empty()) {
        auto range = ranges.back();
        ranges.pop_back();
        if (range.next == "R") {
            continue;
        }
        if (range.next == "A") {
            accepted += (1 + range.x_max-range.x_min)*(1 + range.m_max-range.m_min)*(1 + range.a_max-range.a_min)*(1 + range.s_max-range.s_min);
            continue;
        }
        for (auto rule : operations[range.next]) {
            rule(range, ranges);
        }
    }
    return std::to_string(accepted);
}
}
