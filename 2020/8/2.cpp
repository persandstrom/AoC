#include <string>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> orgInstructions;
    for (std::string line; std::getline(std::cin, line);) {
        orgInstructions.push_back(line);           
    }
    orgInstructions.push_back("end +000");

    int acc=0;
    int pos=0;
    
    for (int i=0; i <orgInstructions.size(); i++) {
        auto instructions = orgInstructions;
        std::string candidate = instructions[i].substr(0,3);
        if (candidate != "nop" && candidate != "jmp") {
            continue;
        }
        instructions[i].replace(0, 3, candidate == "nop" ? "jmp" : "nop");
        acc = 0;
        pos = 0;
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
        if (pos == instructions.size()) {
            break;
        }
    }
    std::cout << acc << std::endl;
}

