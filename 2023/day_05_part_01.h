#pragma once

#include <string>
#include <sstream>
#include "file_reader.h"
#include <map>
#include <vector>
#include "aoc_util.h"
#include <climits>

using namespace std;

namespace day_05_part_01 {

class RangeTransform {
    public:
    RangeTransform(const std::vector<long>& values) {
        source_start = values.at(1);
        source_end = source_start + values.at(2);
        destination_start = values.at(0);
        destination_end = destination_start + values.at(2);
    }

    const bool in_range(const long source) const {
        return (source_start <= source) && (source <= source_end);
    }

    const long get_destination(const long source) const {
        return destination_start + source - source_start;
    }

    long source_start = 0;
    long source_end = 0;
    long destination_start = 0;
    long destination_end = 0;
};

class transform : public std::vector<RangeTransform> {
    public:
    const long get_destination(const long source) const {
        for(const auto& t : *this) {
            if (t.in_range(source)) {
                return t.get_destination(source);
            }
        }
        return source;
    }
};

std::string run(FileReader& reader) {

    std::vector<long> seeds;
    transform seeds_to_soil;
    transform soil_to_fertilizer;
    transform fertilizer_to_water;
    transform water_to_light;
    transform light_to_temperature;
    transform temperature_to_humidity;
    transform humidity_to_location;

    std::string current_map = "";

    for(const auto& line : reader.to_vector()) {
        if (line.size()==0) {
            continue;
        } else if (line == "seed-to-soil map:") {
            current_map = "seed-to-soil";
        } else if (line == "soil-to-fertilizer map:") {
            current_map = "soil-to-fertilizer";
        } else if (line == "fertilizer-to-water map:") {
            current_map = "fertilizer-to-water";
        } else if (line == "water-to-light map:") {
            current_map = "water-to-light";
        } else if (line == "light-to-temperature map:") {
            current_map = "light-to-temperature";
        } else if (line == "temperature-to-humidity map:") {
            current_map = "temperature-to-humidity";
        } else if (line == "humidity-to-location map:") {
            current_map = "humidity-to-location";
        } else if (current_map == "") {
            seeds = aoc::csv_to_vector<long>(line.substr(line.find(":")+1));
        } else if (current_map == "seed-to-soil") {
            seeds_to_soil.push_back(RangeTransform(aoc::csv_to_vector<long>(line)));
        } else if (current_map == "soil-to-fertilizer") {
            soil_to_fertilizer.push_back(RangeTransform(aoc::csv_to_vector<long>(line)));
        } else if (current_map == "fertilizer-to-water") {
            fertilizer_to_water.push_back(RangeTransform(aoc::csv_to_vector<long>(line)));
        } else if (current_map == "water-to-light") {
            water_to_light.push_back(RangeTransform(aoc::csv_to_vector<long>(line)));
        } else if (current_map == "light-to-temperature") {
            light_to_temperature.push_back(RangeTransform(aoc::csv_to_vector<long>(line)));
        } else if (current_map == "temperature-to-humidity") {
            temperature_to_humidity.push_back(RangeTransform(aoc::csv_to_vector<long>(line)));
        } else if (current_map == "humidity-to-location") {
            humidity_to_location.push_back(RangeTransform(aoc::csv_to_vector<long>(line)));
        }
    }

    long closest = LONG_MAX;
    for (auto & seed : seeds) {
        auto soil = seeds_to_soil.get_destination(seed);
        auto fertilizer = soil_to_fertilizer.get_destination(soil);
        auto water = fertilizer_to_water.get_destination(fertilizer);
        auto light = water_to_light.get_destination(water);
        auto temperature = light_to_temperature.get_destination(light);
        auto humidity = temperature_to_humidity.get_destination(temperature);
        auto location = humidity_to_location.get_destination(humidity);
        closest = min(closest, location);
    }


    return std::to_string(closest);
}
}
