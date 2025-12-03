#include "gtest/gtest.h"
#include "day_02_part_01.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_02_01 : public ::testing::Test {};

TEST_F(Fixture_02_01, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124"
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_02_part_01::run(reader), "1227775554");
}
