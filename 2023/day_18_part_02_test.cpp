#include "gtest/gtest.h"
#include "day_18_part_02.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_18_02 : public ::testing::Test {};

TEST_F(Fixture_18_02, test_input_1) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "R 6 (#70c710)",
        "D 5 (#0dc571)",
        "L 2 (#5713f0)",
        "D 2 (#d2c081)",
        "R 2 (#59c680)",
        "D 2 (#411b91)",
        "L 5 (#8ceee2)",
        "U 2 (#caa173)",
        "L 1 (#1b58a2)",
        "U 2 (#caa171)",
        "R 2 (#7807d2)",
        "U 3 (#a77fa3)",
        "L 2 (#015232)",
        "U 2 (#7a21e3)",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_18_part_02::run(reader), "952408144115");
}