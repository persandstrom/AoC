#pragma once

#include <string>
#include "file_reader.h"

namespace day_01_part_02 {

std::string run(FileReader& reader) {
    
    int sum = 0;

    reader.for_each_line([&sum](const std::string& line){
        char first = 0; char last = 0; char val = 0;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                val = line[i];
            } else if (line.substr(i).find("zero") == 0) {
                val = '0';
            } else if (line.substr(i).find("one") == 0) {
                val = '1';
            } else if (line.substr(i).find("two") == 0) {
                val = '2';
            } else if (line.substr(i).find("three") == 0) {
                val = '3';
            } else if (line.substr(i).find("four") == 0) {
                val = '4';
            } else if (line.substr(i).find("five") == 0) {
                val = '5';
            } else if (line.substr(i).find("six") == 0) {
                val = '6';
            } else if (line.substr(i).find("seven") == 0) {
                val = '7';
            } else if (line.substr(i).find("eight") == 0) {
                val = '8';
            } else if (line.substr(i).find("nine") == 0) {
                val = '9';
            }
            if (!first) {
                first = val;
            }
            last = val;   
        }

        sum += stoi(std::string{first, last});
        });
    return std::to_string(sum);
}

}
