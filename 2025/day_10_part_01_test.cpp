#include "gtest/gtest.h"
#include "day_10_part_01.h"
#include "file_reader_test_double.h"

#include <string>

class Fixture_10_01 : public ::testing::Test {};

TEST_F(Fixture_10_01, test_input) {
    const std::vector<std::string> test_input = {
        "[.##.] (3) (1,3) (2) (2,3) (0,2) (0,1) {3,5,4,7}",
        "[...#.] (0,2,3,4) (2,3) (0,4) (0,1,2) (1,2,3,4) {7,5,12,7,2}",
        "[.###.#] (0,1,2,3,4) (0,3,4) (0,1,2,4,5) (1,2) {10,11,11,5,10,5}"
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_10_part_01::run(reader), "7");
}
