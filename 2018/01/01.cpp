#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::fstream input_file;
	input_file.open("input", std::ios::in);

    int frequency = 0;
    for (std::string line; std::getline(input_file, line);)
    {
        frequency += stoi(line);
    }

    std::cout << frequency << std::endl;    
    return 0;
}