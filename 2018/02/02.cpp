#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::fstream input_file;
    std::vector<std::string> input;
    
    input_file.open("input", std::ios::in);
    for (std::string line; std::getline(input_file, line);)
    {
        input.push_back(line);
    }
    input_file.close();
    
    for (auto it1 = input.begin(); it1 != input.end(); it1++) {
        for (auto it2 = it1+1; it2 != input.end(); it2++) {
            int diff = -1;
            for (int i = 0; i<it1->size(); i++) {
                
                if (it1->at(i) != it2->at(i)) {
                    if (diff >= 0) {
                        diff = -1;
                        break;
                    }
                    diff = i;
                }
            }
            if (diff >=0) {
                std::cout << it1->erase(diff,1) << std::endl;
                exit(0);
            }
        }
    }
    
    return 0;
}