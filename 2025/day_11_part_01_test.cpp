#include "gtest/gtest.h"
#include "day_11_part_01.h"
#include "file_reader_test_double.h"

#include <string>

class Fixture_11_01 : public ::testing::Test {};

TEST_F(Fixture_11_01, test_input) {
    const std::vector<std::string> test_input = {
        "aaa: you hhh",
        "you: bbb ccc",
        "bbb: ddd eee",
        "ccc: ddd eee fff",
        "ddd: ggg", 
        "eee: out",
        "fff: out",
        "ggg: out",
        "hhh: ccc fff iii",
        "iii: out"
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_11_part_01::run(reader), "5");
}
