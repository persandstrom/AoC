#include "gtest/gtest.h"
#include "day_08_part_02.h"
#include "file_reader_test_double.h"

#include <string>

class Fixture_08_02 : public ::testing::Test {};

TEST_F(Fixture_08_02, test_input) {
    const std::vector<std::string> test_input = {
        "162,817,812",
        "57,618,57",
        "906,360,560",
        "592,479,940",
        "352,342,300",
        "466,668,158",
        "542,29,236",
        "431,825,988",
        "739,650,466",
        "52,470,668",
        "216,146,977",
        "819,987,18",
        "117,168,530",
        "805,96,715",
        "346,949,466",
        "970,615,88",
        "941,993,340",
        "862,61,35",
        "984,92,344",
        "425,690,689"
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_08_part_02::run(reader, 10), "25272");
}
