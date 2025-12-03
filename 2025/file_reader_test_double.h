#pragma once

#include "file_reader.h"

class FileReaderTestDouble : public FileReader {
public:
    FileReaderTestDouble(const std::vector<std::string>& lines)
        : lines_(lines), index_(0) {}
    
    bool read_line(std::string& line) override {
        if (index_ < lines_.size()) {
            line = lines_[index_++];
            return true;
        }
        return false;
    }

private:
    const std::vector<std::string>& lines_;
    std::size_t index_;
};
