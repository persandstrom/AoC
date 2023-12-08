#include "gtest/gtest.h"
#include "day_08_part_02.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_08_02 : public ::testing::Test {};

TEST_F(Fixture_08_02, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "LR",
        "",
        "11A = (11B, XXX)",
        "11B = (XXX, 11Z)",
        "11Z = (11B, XXX)",
        "22A = (22B, XXX)",
        "22B = (22C, 22C)",
        "22C = (22Z, 22Z)",
        "22Z = (22B, 22B)",
        "XXX = (XXX, XXX)",

    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_08_part_02::run(reader), "6");
}
