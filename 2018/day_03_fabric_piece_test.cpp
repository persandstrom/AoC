#include "gtest/gtest.h"
#include "day_03_fabric_piece.h"

// Test suite for the FabricPiece class
class FabricPieceTest : public ::testing::Test {};

TEST_F(FabricPieceTest, FromString_ValidInput) {
    // Test the FromString function with valid input
    const std::string validInput = "#123 @ 2,3: 4x5";
    FabricPiece piece = FabricPiece::FromString(validInput);

    EXPECT_EQ(piece.id, 123);
    EXPECT_EQ(piece.start_x, 2);
    EXPECT_EQ(piece.start_y, 3);
    EXPECT_EQ(piece.end_x, 6); // (2 + 4)
    EXPECT_EQ(piece.end_y, 8); // (3 + 5)
    EXPECT_TRUE(piece.is_valid());
}

TEST_F(FabricPieceTest, FromString_InvalidInput) {
    // Test the FromString function with invalid input
    const std::string invalid_input = "invalid input";
    FabricPiece piece = FabricPiece::FromString(invalid_input);
    std::cout << piece.start_x << piece.start_y << piece.id << piece.end_x << piece.end_y << std::endl;

    // Ensure the piece is invalid
    EXPECT_FALSE(piece.is_valid());
}