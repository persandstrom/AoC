#include "gtest/gtest.h"
#include "01.h"
#include "../common/file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_02_01 : public ::testing::Test {};

TEST_F(Fixture_02_01, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "abcdef",
        "bababc",
        "abbcde",
        "abcccd",
        "aabcdd",
        "abcdee",
        "ababab"
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_02_part_01::run(reader), "12");


}
