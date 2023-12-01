#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include <functional>

class FileReader {
public:
    FileReader(const std::string& filename) : file_(filename) {
        if (!file_.is_open()) {
            std::filesystem::path p = filename;
            std::string const error_msg =
                "Failed to open the file " +
                (std::string)std::filesystem::absolute(p) + ".";

            throw std::runtime_error(error_msg);
        }
    }

    virtual ~FileReader() {
        if (file_.is_open()) {
            file_.close();
        }
    }

    virtual bool read_line(std::string& line) {
        return static_cast<bool>(std::getline(file_, line));
    }

    void for_each_line(std::function<void(const std::string&)> lambda) {
        std::string line;
        while (read_line(line)) {
            try {
                lambda(line);
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }

    [[nodiscard]] std::vector<std::string> to_vector() {
        std::vector<std::string> collection;
        this->for_each_line([&collection](const std::string& line){
            collection.push_back(line);
        });
        return collection;
    };

protected:
    FileReader() : file_(nullptr) {}

private:
    std::ifstream file_;
};