#include "gtest/gtest.h"
#include "day_11_part_01.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_11_01 : public ::testing::Test {};

TEST_F(Fixture_11_01, test_input_1) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "...#......",
        ".......#..",
        "#.........",
        "..........",
        "......#...",
        ".#........",
        ".........#",
        "..........",
        ".......#..",
        "#...#.....",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_11_part_01::run(reader), "374");
}