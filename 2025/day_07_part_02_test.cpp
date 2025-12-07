#include "gtest/gtest.h"
#include "day_07_part_02.h"
#include "file_reader_test_double.h"

#include <string>

class Fixture_07_02 : public ::testing::Test {};

TEST_F(Fixture_07_02, test_input) {
    const std::vector<std::string> test_input = {
        ".......S.......",
        "...............",
        ".......^.......",
        "...............",
        "......^.^......",
        "...............",
        ".....^.^.^.....",
        "...............",
        "....^.^...^....",
        "...............",
        "...^.^...^.^...",
        "...............",
        "..^...^.....^..",
        "...............",
        ".^.^.^.^.^...^.",
        "..............."
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_07_part_02::run(reader), "40");
}
