#include "gtest/gtest.h"
#include "day_03_part_01.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_03_01 : public ::testing::Test {};

TEST_F(Fixture_03_01, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "467..114..",
        "...*......",
        "..35..633.",
        "......#...",
        "617*......",
        ".....+.58.",
        "..592.....",
        "......755.",
        "...$.*....",
        ".664.598..",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_03_part_01::run(reader), "4361");


}
