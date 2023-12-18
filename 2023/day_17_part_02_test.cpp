#include "gtest/gtest.h"
#include "day_17_part_02.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_17_02 : public ::testing::Test {};

TEST_F(Fixture_17_02, test_input_1) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "2413432311323",
        "3215453535623",
        "3255245654254",
        "3446585845452",
        "4546657867536",
        "1438598798454",
        "4457876987766",
        "3637877979653",
        "4654967986887",
        "4564679986453",
        "1224686865563",
        "2546548887735",
        "4322674655533",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_17_part_02::run(reader), "94");
}