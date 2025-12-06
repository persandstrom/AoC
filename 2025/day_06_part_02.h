#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>
#include "aoc_util.h"
#include <vector>

namespace day_06_part_02 {


std::string run(FileReader& reader) {

    long res = 0;
    auto input = reader.to_vector(); 

    int h = input.size();
    int w = input[0].length();

    std::vector<std::string> nums;

    for (int x = w-1; x>=0; x--) {
        char op = input.back()[x];
        std::string num = "";
        for (int y = 0; y<h-1; y++) {
            if (input[y][x] != ' ')
                num = num + input[y][x];
        }
        if (num != "")
            nums.push_back(num);
        if (op != ' ') {
            long sum = std::stol(nums[0]);
            if (op == '+') {
                for (int i = 1; i<nums.size(); i++) {
                    sum += std::stol(nums[i]);
                }
            }
            if (op == '*') {
                for (int i = 1; i<nums.size(); i++) {
                    sum *= std::stol(nums[i]);
                }
            }
            res += sum;
            nums.clear();
        }
    }

    return std::to_string(res);
}

}
