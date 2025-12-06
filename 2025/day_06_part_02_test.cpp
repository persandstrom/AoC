#include "gtest/gtest.h"
#include "day_06_part_02.h"
#include "file_reader_test_double.h"

#include <string>

class Fixture_06_02 : public ::testing::Test {};

TEST_F(Fixture_06_02, test_input) {
    const std::vector<std::string> test_input = {
        "123 328  51 64 ",
        " 45 64  387 23 ",
        "  6 98  215 314",
        "*   +   *   +  "
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_06_part_02::run(reader), "3263827");
}
