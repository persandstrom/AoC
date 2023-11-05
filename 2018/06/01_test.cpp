#include "gtest/gtest.h"
#include "01.h"
#include "../common/file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_06_01 : public ::testing::Test {};

TEST_F(Fixture_06_01, test_input) {
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

    EXPECT_EQ(day_06_part_01::run(reader), "17");
}
