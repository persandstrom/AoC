#include "gtest/gtest.h"
#include "02.h"
#include "../common/file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_06_02 : public ::testing::Test {};

TEST_F(Fixture_06_02, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "1, 1",
        "1, 6",
        "8, 3",
        "3, 4",
        "5, 5",
        "8, 9",
    };
    FileReaderTestDouble reader(test_input);
    day_06_part_02::MAX_TOTAL_DISTANCE = 32;
    EXPECT_EQ(day_06_part_02::run(reader), "16");
}
