#include "gtest/gtest.h"
#include "day_11_part_02.h"
#include "file_reader_test_double.h"

#include <string>

class Fixture_11_02 : public ::testing::Test {};

TEST_F(Fixture_11_02, test_input) {
    const std::vector<std::string> test_input = {
        "svr: aaa bbb",
        "aaa: fft",
        "fft: ccc",
        "bbb: tty",
        "tty: ccc",
        "ccc: ddd eee",
        "ddd: hub",
        "hub: fff",
        "eee: dac",
        "dac: fff",
        "fff: ggg hhh",
        "ggg: out",
        "hhh: out"
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_11_part_02::run(reader), "2");
}
