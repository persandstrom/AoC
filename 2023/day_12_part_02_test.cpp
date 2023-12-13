#include "gtest/gtest.h"
#include "day_12_part_02.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_12_02 : public ::testing::Test {};

TEST_F(Fixture_12_02, test_input_1) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "???.### 1,1,3",
        ".??..??...?##. 1,1,3",
        "?#?#?#?#?#?#?#? 1,3,1,6",
        "????.#...#... 4,1,1",
        "????.######..#####. 1,6,5",
        "?###???????? 3,2,1",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_12_part_02::run(reader), "525152");
}