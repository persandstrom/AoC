#include "gtest/gtest.h"
#include "day_10_part_02.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_10_02 : public ::testing::Test {};

TEST_F(Fixture_10_02, test_input_1) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "...........",
        ".S-------7.",
        ".|F-----7|.",
        ".||.....||.",
        ".||.....||.",
        ".|L-7.F-J|.",
        ".|..|.|..|.",
        ".L--J.L--J.",
        "...........",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_10_part_02::run(reader), "4");
}

TEST_F(Fixture_10_02, test_input_2) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        ".F----7F7F7F7F-7....",
        ".|F--7||||||||FJ....",
        ".||.FJ||||||||L7....",
        "FJL7L7LJLJ||LJ.L-7..",
        "L--J.L7...LJS7F-7L7.",
        "....F-J..F7FJ|L7L7L7",
        "....L7.F7||L7|.L7L7|",
        ".....|FJLJ|FJ|F7|.LJ",
        "....FJL-7.||.||||...",
        "....L---J.LJ.LJLJ...",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_10_part_02::run(reader), "8");
}

TEST_F(Fixture_10_02, test_input_3) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "FF7FSF7F7F7F7F7F---7",
        "L|LJ||||||||||||F--J",
        "FL-7LJLJ||||||LJL-77",
        "F--JF--7||LJLJ7F7FJ-",
        "L---JF-JLJ.||-FJLJJ7",
        "|F|F-JF---7F7-L7L|7|",
        "|FFJF7L7F-JF7|JL---7",
        "7-L-JL7||F7|L7F-7F7|",
        "L.L7LFJ|||||FJL7||LJ",
        "L7JLJL-JLJLJL--JLJ.L",
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_10_part_02::run(reader), "10");
}