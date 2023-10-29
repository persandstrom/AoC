#include "gtest/gtest.h"
#include "02.h"
#include "../common/file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_05_02 : public ::testing::Test {};

TEST_F(Fixture_05_02, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "dabAcCaCBAcCcaDA",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_05_part_02::run(reader), "4");
}
