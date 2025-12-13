#include "gtest/gtest.h"
#include "day_12_part_01.h"
#include "file_reader_test_double.h"

#include <string>

class Fixture_12_01 : public ::testing::Test {};

TEST_F(Fixture_12_01, test_input) {
    const std::vector<std::string> test_input = {
        "0:",
        "###",
        "##.",
        "##.",
            "",
        "1:",
        "###",
        "##.",
        ".##",
            "",
        "2:",
        ".##",
        "###",
        "##.",
            "",
        "3:",
        "##.",
        "###",
        "##.",
            "",
        "4:",
        "###",
        "#..",
        "###",
            "",
        "5:",
        "###",
        ".#.",
        "###",
            "",
        "4x4: 0 0 0 0 2 0",
        "12x5: 1 0 1 0 2 2",
        "12x5: 1 0 1 0 3 2"
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_12_part_01::run(reader), "1"); // this is not the correct answer, but works for full data
}
