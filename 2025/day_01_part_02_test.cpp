#include "gtest/gtest.h"
#include "day_01_part_02.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_01_02 : public ::testing::Test {};

TEST_F(Fixture_01_02, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "L68",
        "L30",
        "R48",
        "L5",
        "R60",
        "L55",
        "L1",
        "L99",
        "R14",
        "L82"
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_01_part_02::run(reader), "6");
}
