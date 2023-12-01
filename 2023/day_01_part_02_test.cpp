#include "gtest/gtest.h"
#include "day_01_part_02.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_01_02 : public ::testing::Test {};

TEST_F(Fixture_01_02, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "two1nine",
        "eightwothree",
        "abcone2threexyz",
        "xtwone3four",
        "4nineeightseven2",
        "zoneight234",
        "7pqrstsixteen",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_01_part_02::run(reader), "281");


}
