#pragma once

#include <string>
#include <array>
#include <numeric>
#include <algorithm> 

#include "file_reader.h"
#include "day_03_fabric_piece.h"

namespace day_03_part_01 {

std::string run(FileReader& reader) {
    constexpr int fabric_size = 1000;
    std::array<std::array<int,fabric_size>,fabric_size> fabric{};

    reader.for_each_line([&fabric](const std::string& line) {
        FabricPiece piece = FabricPiece::FromString(line);
        if (piece.is_valid()) {
            for (int current_x=piece.start_x; current_x<piece.end_x; current_x++) {
                for (int current_y=piece.start_y; current_y<piece.end_y; current_y++) {
                    fabric.at(current_x).at(current_y)++;
                }
            }
        } else {
            std::stringstream error_message_stream;
            error_message_stream << "Fabric piece with ID " << piece.id << " is invalid.";
            throw std::runtime_error(error_message_stream.str());
        }
    });

    int overlaps = std::accumulate(fabric.begin(), fabric.end(), 0, [](int total, const auto& row) {
        return total + std::count_if(row.begin(), row.end(), [](int value) {
            return value > 1;
        });
    });

    return std::to_string(overlaps);
}

} // END NAMESPACE
