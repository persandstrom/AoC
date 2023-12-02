#include "gtest/gtest.h"
#include "day_02_part_01.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_02_01 : public ::testing::Test {};

TEST_F(Fixture_02_01, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
        "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
        "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red",
        "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red",
        "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_02_part_01::run(reader), "8");


}
