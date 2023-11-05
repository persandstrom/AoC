#include "gtest/gtest.h"
#include "day_07_part_01.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_07_01 : public ::testing::Test {};

TEST_F(Fixture_07_01, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "Step C must be finished before step A can begin.",
        "Step C must be finished before step F can begin.",
        "Step A must be finished before step B can begin.",
        "Step A must be finished before step D can begin.",
        "Step B must be finished before step E can begin.",
        "Step D must be finished before step E can begin.",
        "Step F must be finished before step E can begin."
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_07_part_01::run(reader), "CABDFE");
}
