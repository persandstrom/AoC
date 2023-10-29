#pragma once

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <ranges>

#include "../common/file_reader.h"

namespace day_04_part_01 {

std::string run(FileReader& reader) {
    auto entries = reader.to_vector();
    std::sort(entries.begin(), entries.end());

    std::map<std::string, int> guard_sleep;
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
            if (0 == guard_sleep.count(current_guard)) {
                 guard_sleep.insert({current_guard, sleep_time});
                 guard_minutes.insert({current_guard, {}});
            }
        }
        else if (command == 'f') { // falls asleep
            start_minute = stoi(entry.substr(15,2));
        }
        else if (command == 'w') { // wakes up
            int end_minute = stoi(entry.substr(15,2));
            int sleep_time = end_minute - start_minute;
            guard_sleep.at(current_guard) += sleep_time;
            for (int i = start_minute; i < end_minute; i++) {
                guard_minutes.at(current_guard).at(i)++;
            }
        }
    }

    auto element = std::ranges::max_element(
        guard_sleep,
        [](std::pair<std::string, int> a, std::pair<std::string, int> b) { return a.second < b.second; });
    auto sleepiest_guard = (*element).first;
    auto max_minute = std::ranges::max_element(guard_minutes.at(sleepiest_guard).begin(), guard_minutes.at(sleepiest_guard).end());

    int result = stoi((*element).first) * (max_minute - guard_minutes.at(sleepiest_guard).begin());

    return std::to_string(result);
}

} // END NAMESPACE
