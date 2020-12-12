#include <string>
#include <iostream>
#include <vector>

typedef std::vector<bool> seat_map;


seat_map calc_new_occupation(
         const seat_map& seat_layout,
         const seat_map& previous,
         int width) {

    seat_map new_map = previous;

    for (int i = 0; i<previous.size(); i++) {
        int w = (i%width - 1 >= 0) ? i-1 : -1;
        int e = (i%width + 1 < width) ? i+1 : -1;
        int n = i - width;
        int s = i + width;
        int nw = w > -1 ? w - width : -1;
        int ne = e > -1 ? e - width : -1;
        int sw = w > -1 ? w + width : -1;
        int se = e > -1 ? e + width : -1;
        int adjecent =
             (nw >= 0 && (nw < previous.size() & previous[nw]) ? 1 : 0) +
             (n >= 0 && (n < previous.size() & previous[n]) ? 1 : 0) +
             (ne >= 0 && (ne < previous.size() & previous[ne]) ? 1 : 0) +
             (w >= 0 && (w < previous.size() & previous[w]) ? 1 : 0) +
             (e >= 0 && (e < previous.size() & previous[e]) ? 1 : 0) +
             (sw >= 0 && (sw < previous.size() & previous[sw]) ? 1 : 0) +
             (s >= 0 && (s < previous.size() & previous[s]) ? 1 : 0) +
             (se >= 0 && (se < previous.size() & previous[se]) ? 1 : 0);
        if (seat_layout[i]) {
            if (previous[i] && (adjecent > 3)) {
                new_map[i] = false;
            }
            else if (!previous[i] && (adjecent == 0)) {
                new_map[i] = true;
            }
        }
    }
    return new_map;
}


int main() {

    seat_map seat_layout;
    int row_width;

    for (std::string line; std::getline(std::cin, line);) {
        row_width = line.size();
        for (char& c : line) {
            if (c == 'L') {
                seat_layout.push_back(true);
            }
            else if (c == '.') {
                seat_layout.push_back(false);
            }
        }
    }
 
    seat_map occupied = seat_layout;
    seat_map new_occupied;

    while (true) {
        new_occupied = calc_new_occupation(seat_layout, occupied, row_width);
        if (new_occupied == occupied) {
            break;
        }
        else {
            occupied = new_occupied;
        }
    }
 
    int count = 0;
    for (bool b : occupied) {
        count += b;
    }

    std::cout << count << std::endl;
}
