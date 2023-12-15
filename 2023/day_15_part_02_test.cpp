#include "gtest/gtest.h"
#include "day_15_part_02.h"
#include "file_reader_test_double.h"

#include <string>

// Test suite for the FabricPiece class
class Fixture_15_02 : public ::testing::Test {};

TEST_F(Fixture_15_02, test_input_1) {
    // Test the FromString function with valid input
    const std::vector<std::string> test_input = {
        "rn=1,cm-,qp=3,cm=2,qp-,pc=4,ot=9,ab=5,pc-,pc=6,ot=7"
    };
    FileReaderTestDouble reader(test_input);

    EXPECT_EQ(day_15_part_02::run(reader), "145");
}