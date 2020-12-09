#include <string>
#include <iostream>
#include <vector>

int main() {
    const long invalid = 530627549;
    std::vector<long> numbers;
    for (std::string line; std::getline(std::cin, line);) {
        numbers.push_back(std::stol(line));
    }

    for (int i=0; i<numbers.size(); i++) {
        long sum = numbers[i];
        long lowest = numbers[i];
        long highest = numbers[i];
        for (int j=i+1; sum<=invalid; j++) {
            sum+=numbers[j];
            lowest = numbers[j] < lowest ? numbers[j] : lowest;
            highest = numbers[j] > highest ? numbers[j] : highest;
            if (sum == invalid)
            {
                std::cout << (lowest + highest) << std::endl;
                exit(0);
            }
        }
    }
    std::cout << "not found" << std::endl;
}
