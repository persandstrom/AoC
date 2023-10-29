#include "common/file_reader.h"
#include "forward_declared_functions.h"

#include <iostream>
#include <fstream>
#include <functional>
#include <stdexcept>
#include <map>
#include <chrono>

auto execute = [](const std::string input_file, std::function<std::string(FileReader&)> run_day){
    FileReader reader(input_file);
    auto begin = std::chrono::steady_clock::now();
    auto result = run_day(reader);
    auto end = std::chrono::steady_clock::now();
    std::cout << "result: "
              << result 
              << " execution time = "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
              << " µs"
              << std::endl;
};

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <day_number> <part_number>" << std::endl;
        return 1;
    }

    try {
        int day = std::stoi(argv[1]);
        int part = std::stoi(argv[2]);

        // Ensure day is in the range 1-31 and part is either 1 or 2
        if (day < 1 || day > 31 || (part != 1 && part != 2)) {
            std::cerr << "Invalid day or part number." << std::endl;
            return 1;
        }

        // Based on day and part, execute the appropriate function
        auto input_file = "input_" + std::string((day < 10 ? "0" : "") + std::to_string(day));
        
        execute(input_file, day_function.find({day,part})->second);
        
        

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}