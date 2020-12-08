#include <string>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> instructions;
    for (std::string line; std::getline(std::cin, line);) {
        instructions.push_back(line);           
    }

    int acc=0;
    int pos=0;

    while(true) {
        std::string operation = instructions[pos].substr(0,3);
        int value = std::stoi(instructions[pos].substr(4));
        instructions[pos] = "end +000";
        pos++;
        if (operation == "acc") {
            acc += value;
        }
        else if (operation == "jmp") {
            pos += value - 1;
        }
        else if (operation == "end") {
            break;
        }
    }
    std::cout << acc << std::endl;
}

