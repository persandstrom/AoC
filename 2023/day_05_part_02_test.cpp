#include "gtest/gtest.h"
#include "day_05_part_02.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_05_02 : public ::testing::Test {};

TEST_F(Fixture_05_02, test_input) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "seeds: 79 14 55 13",
        "",
        "seed-to-soil map:",
        "50 98 2",
        "52 50 48",
        "",
        "soil-to-fertilizer map:",
        "0 15 37",
        "37 52 2",
        "39 0 15",
        "",
        "fertilizer-to-water map:",
        "49 53 8",
        "0 11 42",
        "42 0 7",
        "57 7 4",
        "",
        "water-to-light map:",
        "88 18 7",
        "18 25 70",
        "",
        "light-to-temperature map:",
        "45 77 23",
        "81 45 19",
        "68 64 13",
        "",
        "temperature-to-humidity map:",
        "0 69 1",
        "1 0 69",
        "",
        "humidity-to-location map:",
        "60 56 37",
        "56 93 4",
        "",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_05_part_02::run(reader), "46");
}
