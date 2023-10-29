#pragma once

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <ranges>

#include "../common/file_reader.h"

namespace day_04_part_02 {

std::string run(FileReader& reader) {
    auto entries = reader.to_vector();
    std::sort(entries.begin(), entries.end());

    std::map<std::string, std::array<int, 60>> guard_minutes;

    std::string current_guard = "";
    int sleep_time = 0;
    int start_minute = 0;
    for (auto const & entry : entries) {
        char command = entry.at(19);
        if (command == 'G') { // New Guard
            auto endpos = entry.find(' ', 26);
            current_guard = entry.substr(26, endpos-26);
            sleep_time = 0;
            if (0 == guard_minutes.count(current_guard)) {
                 guard_minutes.insert({current_guard, {}});
            }
        }
        else if (command == 'f') { // falls asleep
            start_minute = stoi(entry.substr(15,2));
        }
        else if (command == 'w') { // wakes up
            int end_minute = stoi(entry.substr(15,2));
            int sleep_time = end_minute - start_minute;
            for (int i = start_minute; i < end_minute; i++) {
                guard_minutes.at(current_guard).at(i)++;
            }
        }
    }

    std::string sleepiest_guard = "";
    const int* max_minute = nullptr;
    for (const auto & [guard, minutes] : guard_minutes) {
        auto guard_max_minute = std::ranges::max_element(minutes.begin(), minutes.end());
        if (max_minute == nullptr) {
            sleepiest_guard = guard;
            max_minute = guard_max_minute;
        }
        if (*guard_max_minute > *max_minute) {
            sleepiest_guard = guard;
            max_minute = guard_max_minute;
        }
    }

    int result = stoi(sleepiest_guard) * (max_minute - guard_minutes.at(sleepiest_guard).begin());

    return std::to_string(result);
}

} // END NAMESPACE
