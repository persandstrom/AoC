#include "gtest/gtest.h"
#include "day_05_part_01.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_05_01 : public ::testing::Test {};

TEST_F(Fixture_05_01, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "dabAcCaCBAcCcaDA",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_05_part_01::run(reader), "10");
}
