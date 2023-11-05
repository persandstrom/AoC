#include "gtest/gtest.h"
#include "day_01_part_02.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_01_02 : public ::testing::Test {};

TEST_F(Fixture_01_02, test_input_1) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "+1", "-1"
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_01_part_02::run(reader), "0");
}

TEST_F(Fixture_01_02, test_input_2) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "+3", "+3", "+4", "-2", "-4"
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_01_part_02::run(reader), "10");
}

TEST_F(Fixture_01_02, test_input_3) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "-6", "+3", "+8", "+5", "-6"
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_01_part_02::run(reader), "5");
}

TEST_F(Fixture_01_02, test_input_4) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "+7", "+7", "-2", "-7", "-4"
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_01_part_02::run(reader), "14");
}