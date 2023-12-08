#include "gtest/gtest.h"
#include "day_08_part_01.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_08_01 : public ::testing::Test {};

TEST_F(Fixture_08_01, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "RL",
        "",
        "AAA = (BBB, CCC)",
        "BBB = (DDD, EEE)",
        "CCC = (ZZZ, GGG)",
        "DDD = (DDD, DDD)",
        "EEE = (EEE, EEE)",
        "GGG = (GGG, GGG)",
        "ZZZ = (ZZZ, ZZZ)",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_08_part_01::run(reader), "2");
}
