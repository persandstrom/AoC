#include "gtest/gtest.h"
#include "file_reader.h"

// Test suite for the FileReader class
class FileReaderTest : public ::testing::Test {
protected:
    FileReaderTest() {
        // Create a temporary test file with content
        std::ofstream testFile("test_input.txt");
        testFile << "Line 1" << std::endl;
        testFile << "Line 2" << std::endl;
        testFile.close();
    }
};

TEST_F(FileReaderTest, ReadLine) {
    FileReader reader("test_input.txt");

    std::string line;
    ASSERT_TRUE(reader.read_line(line));
    EXPECT_EQ(line, "Line 1");

    ASSERT_TRUE(reader.read_line(line));
    EXPECT_EQ(line, "Line 2");

    ASSERT_FALSE(reader.read_line(line)); // EOF, should return false
}

TEST_F(FileReaderTest, ForEachLine) {
    FileReader reader("test_input.txt");

    std::vector<std::string> lines;
    reader.for_each_line([&lines](const std::string& line) {
        lines.push_back(line);
        return true; // Continue processing
    });

    ASSERT_EQ(lines.size(), 2);
    EXPECT_EQ(lines.at(0), "Line 1");
    EXPECT_EQ(lines.at(1), "Line 2");
}

TEST_F(FileReaderTest, ToVector) {
    FileReader reader("test_input.txt");
    auto lines = reader.to_vector();
    ASSERT_EQ(lines.size(), 2);
    EXPECT_EQ(lines.at(0), "Line 1");
    EXPECT_EQ(lines.at(1), "Line 2");
}
