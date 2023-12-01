#include "gtest/gtest.h"
#include "day_01_part_01.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_01_01 : public ::testing::Test {};

TEST_F(Fixture_01_01, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "1abc2",
        "pqr3stu8vwx",
        "a1b2c3d4e5f",
        "treb7uchet",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_01_part_01::run(reader), "142");


}
