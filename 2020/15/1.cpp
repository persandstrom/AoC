#include <string>
#include <iostream>
#include <map>

int main() {
    std::map<int,int> memory;
    int offset = 0;
    int last_number;

    for (std::string number; std::getline(std::cin, number, ',');) {
        memory[last_number] = offset++;
        last_number = std::stoi(number);
    }

    while (offset < 2020) {
        auto it = memory.find(last_number);
        if (it == memory.end()) {
            memory[last_number] = offset++;
            last_number = 0;
        }
        else {
            int diff = offset - it->second;
            it->second = offset++;
            last_number = diff;
        }
    }
    std::cout << last_number << std::endl;
}
