#include "gtest/gtest.h"
#include "day_09_part_01.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_09_01 : public ::testing::Test {};

TEST_F(Fixture_09_01, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "0 3 6 9 12 15",
        "1 3 6 10 15 21",
        "10 13 16 21 30 45",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_09_part_01::run(reader), "114");
}
