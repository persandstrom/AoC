#include "gtest/gtest.h"
#include "day_07_part_01.h"
#include "file_reader_test_double.h"

#include <string>

class Fixture_07_01 : public ::testing::Test {};

TEST_F(Fixture_07_01, test_input) {
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

    EXPECT_EQ(day_07_part_01::run(reader), "21");
}
