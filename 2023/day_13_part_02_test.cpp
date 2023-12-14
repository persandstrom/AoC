#include "gtest/gtest.h"
#include "day_13_part_02.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_13_02 : public ::testing::Test {};

TEST_F(Fixture_13_02, test_input_1) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "#.##..##.",
        "..#.##.#.",
        "##......#",
        "##......#",
        "..#.##.#.",
        "..##..##.",
        "#.#.##.#.",
        "",
        "#...##..#",
        "#....#..#",
        "..##..###",
        "#####.##.",
        "#####.##.",
        "..##..###",
        "#....#..#",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_13_part_02::run(reader), "400");
}