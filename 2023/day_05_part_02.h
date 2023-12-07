#pragma once

#include <string>
#include <sstream>
#include "file_reader.h"
#include <map>
#include <vector>
#include "aoc_util.h"
#include <climits>
#include <cstdint>

using namespace std;

namespace day_05_part_02 {

class Range {
    public:
    Range() {
    }

    Range(const int64_t start, const int64_t end) {
        this->start = start;
        this->end = end;
    }

    void set_range(const int64_t start, const int64_t length) {
        this->start = start;
        this->end = start+length-1;
    }

    int64_t start = 0;
    int64_t end = 0;
};

class RangeTransform {
    public:
    RangeTransform(const std::vector<int64_t>& values) {
        source.set_range(values.at(1), values.at(2));
        destination.set_range(values.at(0), values.at(2));
    }

    const int64_t get_destination(const int64_t source) const {
        int64_t a = source - this->source.start;
        return this->destination.start + a;
    }

    Range source;
    Range destination;
};

using transform = std::vector<RangeTransform>;

std::string run(FileReader& reader) {

    std::vector<Range> current_range;
    std::vector<transform> transforms;

    for(const auto& line : reader.to_vector()) {
        if (line.size()==0) {
            continue;
        } else if (current_range.size() == 0) {
            auto values = aoc::csv_to_vector<int64_t>(line.substr(line.find(":")+1));
            for (int i=0; i<values.size(); i+=2) {
                current_range.push_back(Range(values[i], values[i] + values[i+1]));
            }
        } else if (line.at(line.size()-1) == ':') {
            transforms.push_back(transform());
        } else {
            transforms.back().push_back(RangeTransform(aoc::csv_to_vector<int64_t>(line)));
        }
    }
    
    std::vector<Range> new_range;
    for (const auto & t : transforms) {
        new_range.clear();
        for (int i = 0; i<current_range.size(); i++) {
            const auto & cr = current_range[i];
            
            bool handled = false;
            for (const auto & tr : t) {
                if (cr.start >= tr.source.start && cr.start <= tr.source.end) {
                    new_range.push_back(Range(tr.get_destination(cr.start), tr.get_destination(min(cr.end, tr.source.end))));
                    if(cr.end > tr.source.end) {
                        current_range.push_back(Range(tr.source.end+1, cr.end));
                    }
                    
                } else if (cr.end >= tr.source.start && cr.end <= tr.source.end) {
                    new_range.push_back(Range(tr.get_destination(max(cr.start, tr.source.start)), tr.get_destination(cr.end)));
                    if(cr.start < tr.source.start) {
                        current_range.push_back(Range(cr.start, tr.source.start -1));
                    }
                } else if (cr.start < tr.source.start && cr.end > tr.source.end) {
                    new_range.push_back(Range(tr.get_destination(tr.source.start), tr.get_destination(tr.source.end)));
                    current_range.push_back(Range(cr.start, tr.source.start-1));
                    current_range.push_back(Range(tr.source.end+1, cr.end));
                } else {
                    continue;
                }
                handled=true;
                break;
            }
            if (!handled) {
                new_range.push_back(Range(cr.start, cr.end));
            }

        }
        current_range = new_range;
    }
    

    int64_t minval = INT64_MAX;

    for (const auto & r : current_range) {
        minval = min(r.start, minval);
    }

    return std::to_string(minval);
}
}
