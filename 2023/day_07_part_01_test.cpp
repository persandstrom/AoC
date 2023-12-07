#include "gtest/gtest.h"
#include "day_07_part_01.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_07_01 : public ::testing::Test {};

TEST_F(Fixture_07_01, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "32T3K 765",
        "T55J5 684",
        "KK677 28",
        "KTJJT 220",
        "QQQJA 483",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_07_part_01::run(reader), "6440");
}
