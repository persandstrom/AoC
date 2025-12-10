#include "gtest/gtest.h"
#include "day_09_part_01.h"
#include "file_reader_test_double.h"

#include <string>

class Fixture_09_01 : public ::testing::Test {};

TEST_F(Fixture_09_01, test_input) {
    const std::vector<std::string> test_input = {
        "7,1",
        "11,1",
        "11,7",
        "9,7",
        "9,5",
        "2,5",
        "2,3",
        "7,3"
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_09_part_01::run(reader, 10), "50");
}
