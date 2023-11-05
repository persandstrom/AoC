#include "gtest/gtest.h"
#include "day_01_part_01.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_01_01 : public ::testing::Test {};

TEST_F(Fixture_01_01, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "+1", "-2", "+3", "+1"
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_01_part_01::run(reader), "3");


}
