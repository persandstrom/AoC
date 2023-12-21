#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include "unordered_map"
#include <queue>
#include <functional>

using namespace std;


namespace day_19_part_01 {

using Rule = function<string(int,int,int,int)>;

std::string run(FileReader& reader) {
    unordered_map<string, vector<Rule>> operations;
    uint64_t accepted = 0;


    bool reading_operations = true;
    reader.for_each_line([&reading_operations, &operations, &accepted](const string & line){
        if (line.empty()) {
            reading_operations = false;
        } else if (reading_operations) {
            string operation_name = line.substr(0, line.find('{'));
            for(auto rule_str : aoc::csv_to_vector<string>(line.substr(line.find('{')+1, line.find('}') - line.find('{')-1), ',')) {
                char comparitor = ' ';
                char variable = ' ';
                int value = 0;
                string next = "";
                if (rule_str.find('<') != rule_str.npos || rule_str.find('>') != rule_str.npos){
                    variable = rule_str[0];
                    comparitor = rule_str[1];
                    value = stoi(rule_str.substr(2, rule_str.find(':')-2));
                    next = rule_str.substr(rule_str.find(':')+1);
                    operations[operation_name].push_back([variable, comparitor, value, next](int x, int m, int a, int s)->string{
                        if (comparitor == '<' && variable == 'x' && x < value) return next;
                        if (comparitor == '>' && variable == 'x' && x > value) return next;
                        if (comparitor == '<' && variable == 'm' && m < value) return next;
                        if (comparitor == '>' && variable == 'm' && m > value) return next;
                        if (comparitor == '<' && variable == 'a' && a < value) return next;
                        if (comparitor == '>' && variable == 'a' && a > value) return next;
                        if (comparitor == '<' && variable == 's' && s < value) return next;
                        if (comparitor == '>' && variable == 's' && s > value) return next;
                        return "";
                    });
                } else {
                    next = rule_str;
                    operations[operation_name].push_back([next](int x, int m, int a, int s)->string{
                        return next;
                    });
                }
            } 

        } else {
            auto rating = aoc::csv_to_vector<string>(line.substr(1, line.size()-2),',');
            int x = stoi(rating[0].substr(2));
            int m = stoi(rating[1].substr(2));
            int a = stoi(rating[2].substr(2));
            int s = stoi(rating[3].substr(2));

            string next = "in";
            while (next != "R" && next != "A")
            {
                string new_next = "";
                for (int i=0; i<operations[next].size(); i++) {
                    new_next = operations[next][i](x,m,a,s);
                    if(new_next != "") {
                        next = new_next;
                        break;
                    }
                }
            }
            if(next == "A") {
                accepted+=(x+m+a+s);
            }
        }

    });

    return std::to_string(accepted);
}
}
