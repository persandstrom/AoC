#pragma once

#include <string>
#include "file_reader.h"
#include <vector>
#include "aoc_util.h"
#include <unordered_map>
#include <algorithm>

using namespace std;

namespace day_07_part_01 {

class Hand {
    public:
    Hand(const std::string& hand_str, const std::string& val_str ) {
        for (int i=0; i<5; i++) {
            int card = get_card_val(hand_str[i]);
            cards[i] = card;
            card_count[card]++;
        }
        if(card_count.size() == 1) {
            hand_type = 7;
        } else if (card_count.size() == 2) {
            for (auto const& [key, val] : card_count) {
                if (val == 4 || val == 1) {
                    hand_type = 6;
                    break;
                }
                if (val == 3 || val == 2) {
                    hand_type = 5;
                    break;
                }
            }
        } else if (card_count.size() == 3) {
            for (auto const& [key, val] : card_count) {
                if (val == 3) {
                    hand_type = 4;
                    break;
                }
                if (val == 2) {
                    hand_type = 3;
                    break;
                }
            }
        } else if (card_count.size() == 4) {
            hand_type = 2;
        } else {
            hand_type = 1;
        }

        value = stoi(val_str);
    }

    bool operator<(const Hand& other)
    {
        if (hand_type < other.hand_type) {
            return true;
        } else if (hand_type > other.hand_type) {
            return false;
        }
        for (int i=0;i<5;i++) {
            if (cards[i] < other.cards[i]) {
                return true;
            }
            if (cards[i] > other.cards[i]) {
                return false;
            }
        }
        return false;
    }

    int get_card_val(const char c) {
        if (c == 'A') return 14;
        if (c == 'K') return 13;
        if (c == 'Q') return 12;
        if (c == 'J') return 11;
        if (c == 'T') return 10;
        return c - '0';
    }

    std::array<int,5> cards;
    std::unordered_map<int,int> card_count;
    int hand_type=0;
    int value = 0;
};

std::string run(FileReader& reader) {

    std::vector<Hand> hands;
    auto input = reader.to_vector();
    for (const auto & row : input) {
        hands.push_back(
            Hand(
                row.substr(0,row.find(' ')),
                row.substr(row.find(' ')+1)));
    }

    std::sort(hands.begin(), hands.end());

    int winnings = 0;
    for (int i=0; i<hands.size(); i++) {
        winnings+= (i+1)*hands[i].value;
    }

    return std::to_string(winnings);
}
}
