#include <string>
#include <iostream>
#include <array>

int main() {
    const int psize = 25;
    const int sumsize = psize*psize;
    std::array<long, psize> preamble;
    std::array<long, psize*psize> sums;
    int counter = 0;
    for (std::string line; std::getline(std::cin, line); counter++) {
        long newVal = std::stol(line);
        preamble[counter%psize] = newVal;
        for (int i=0; i<psize; i++) {
            sums[(counter*psize)%sumsize + i] = preamble[i] + newVal;
        }
        if (counter < psize)
            continue;
        bool found = false;
        for (int i=0; i<sumsize && !found; i++) {
            if (sums[i] == newVal) {
                found = true;
            }
        }
        if (!found) {
            std::cout << newVal << std::endl;
            exit(0);
        }

    }
    std::cout << "not found" << std::endl;
}
