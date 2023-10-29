#pragma once

#include <string>
#include <array>
#include <numeric>
#include <algorithm> 
#include <unordered_set>

#include "../common/file_reader.h"
#include "fabric_piece.h"

namespace day_03_part_02 {

constexpr int overlapping_claim = -1;
constexpr int unclaimed = 0;

std::string run(FileReader& reader) {
    constexpr int fabric_size = 1000;
    std::array<std::array<int,fabric_size>,fabric_size> fabric{};
    std::unordered_set<int> overlapping_pieces;

    reader.for_each_line([&fabric, &overlapping_pieces](const std::string& line) {
        FabricPiece piece = FabricPiece::FromString(line);
        if (piece.is_valid()) {
            for (int current_x=piece.start_x; current_x<piece.end_x; current_x++) {
                for (int current_y=piece.start_y; current_y<piece.end_y; current_y++) {
                    auto claim = fabric.at(current_x).at(current_y);
                    if (claim == unclaimed) {
                        fabric.at(current_x).at(current_y) = piece.id;
                    } else {
                        overlapping_pieces.insert(claim);
                        overlapping_pieces.insert(piece.id);
                    }
                }
            }
        } else {
            std::stringstream error_message_stream;
            error_message_stream << "Fabric piece with ID " << piece.id << " is invalid.";
            throw std::runtime_error(error_message_stream.str());
        }
    });
    
    auto non_overlapping = std::find_if(fabric.front().begin(), fabric.back().end(), [&overlapping_pieces](auto& claim){
        return claim != unclaimed && overlapping_pieces.find(claim) == overlapping_pieces.end();
    });

    return std::to_string(*non_overlapping);
}

} // END NAMESPACE
