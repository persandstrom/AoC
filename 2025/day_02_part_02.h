#pragma once

#include <string>
#include "file_reader.h"
#include <stdio.h>

namespace day_02_part_02 {

std::string run(FileReader& reader) {
    std::string data;
    reader.read_line(data);

    long res = 0;

    std::string::size_type pos = 0;
    while (true) {
        auto pos1 = data.find('-', pos);        
        auto pos2 = data.find(',', pos1);

        auto r_start = stol(data.substr(pos, pos1-pos));
        auto r_end = stol(data.substr(pos1+1, pos2-pos1));
        
        for (auto i = r_start; i <= r_end; i++){
            std::string istr = std::to_string(i);
            bool silly = false;
            for (int div = 1; div<=istr.length()/2; div++) {
                if (istr.length() % div != 0)
                    continue;
                bool all_equal = true;
                auto val1 = istr.substr(0, div);
                for (int j = div; j<istr.length(); j=j+div) {
                    all_equal = all_equal && (val1 == istr.substr(j, div));
                }
                silly = silly || all_equal;

            }
            if (silly)
                res += i;
        }
        
        if (pos2 == std::string::npos) break;
        pos = pos2+1; 
        
    }

    return std::to_string(res);
}

}
