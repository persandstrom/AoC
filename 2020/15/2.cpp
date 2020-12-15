#include <string>
#include <iostream>
#include <map>
#include <stdint.h>

int main() {
    std::map<uint64_t,uint64_t> memory;
    uint64_t offset = 0;
    uint64_t last_number;
    for (std::string number; std::getline(std::cin, number, ',');) {
        memory[last_number] = offset++;
        last_number = std::stoi(number);
    }

    while (offset < 30000000) {
        auto it = memory.find(last_number);
        if (it == memory.end()) {
            memory[last_number] = offset++;
            last_number = 0;
        }
        else {
            uint64_t diff = offset - it->second;
            it->second = offset++;
            last_number = diff;
        }
    }
    std::cout << last_number << std::endl;
}
