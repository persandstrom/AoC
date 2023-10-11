#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>




int main() {
    std::fstream input_file;
	input_file.open("input", std::ios::in);
    std::vector<int> input;

    for (std::string line; std::getline(input_file, line);)
        input.push_back(stoi(line));
    
    int current_frequency = 0;
    std::unordered_set<int> frequencies;

    while (true) {
        for (auto freq_mod : input)
        {
            current_frequency = current_frequency + freq_mod;
            if (frequencies.find(current_frequency) != frequencies.end()) {
                std::cout << current_frequency << std::endl;
                return 0;
            }
            frequencies.insert(current_frequency);
        }
    }

}