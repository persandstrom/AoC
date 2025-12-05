#include "gtest/gtest.h"
#include "day_04_part_01.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_04_01 : public ::testing::Test {};

TEST_F(Fixture_04_01, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "..@@.@@@@.",
        "@@@.@.@.@@",
        "@@@@@.@.@@",
        "@.@@@@..@.",
        "@@.@@@@.@@",
        ".@@@@@@@.@",
        ".@.@.@.@@@",
        "@.@@@.@@@@",
        ".@@@@@@@@.",
        "@.@.@@@.@."
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_04_part_01::run(reader), "13");
}
