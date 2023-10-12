#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main() {
    std::fstream input_file;
    input_file.open("input", std::ios::in);

    int twos = 0;
    int threes = 0;
    for (std::string line; std::getline(input_file, line);)
    {
        int vals[27]{0};
        for (auto& c : line) {
            vals[c - 'a']++;
        }
        if (std::find(std::begin(vals), std::end(vals), 2) != std::end(vals)) {
            twos++;
        }
        if (std::find(std::begin(vals), std::end(vals), 3) != std::end(vals)) {
            threes++;
        }
    }
 
    std::cout << twos*threes << std::endl;

    input_file.close();
    return 0;
}