#include "gtest/gtest.h"
#include "day_10_part_01.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_10_01 : public ::testing::Test {};

TEST_F(Fixture_10_01, test_input_1) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        ".....",
        ".S-7.",
        ".|.|.",
        ".L-J.",
        ".....",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_10_part_01::run(reader), "4");
}

TEST_F(Fixture_10_01, test_input_2) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "..F7.",
        ".FJ|.",
        "SJ.L7",
        "|F--J",
        "LJ...",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_10_part_01::run(reader), "8");
}