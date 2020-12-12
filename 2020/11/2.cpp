#include <string>
#include <iostream>
#include <vector>

typedef std::vector<bool> seat_map;


int can_see(
        const seat_map& seat_layout,
        const seat_map& previous,
        int width,
        int start,
        int right,
        int down) {
    
    int prev_pos = start;
    while (true) {
        int new_right = prev_pos%width + right;
        if (new_right < 0 || new_right >= width) {
            return 0;
        }
        int new_down = prev_pos + (down * width);
        if (new_down < 0 || new_down >= seat_layout.size()) {
            return 0;
        }
        int new_pos = prev_pos + right + down * width;
        if (seat_layout[new_pos]) {
            return previous[new_pos] ? 1 : 0;
        }
        prev_pos = new_pos;
    }
}

seat_map calc_new_occupation(
        const seat_map& seat_layout,
        const seat_map& previous,
        int width) {

    seat_map new_map = previous;

    for (int i = 0; i<previous.size(); i++) {
        if (!seat_layout[i]) {
            continue;
        }
        int adjecent =
            can_see(seat_layout, previous, width, i, -1, -1) +
            can_see(seat_layout, previous, width, i, +0, -1) +
            can_see(seat_layout, previous, width, i, +1, -1) +
            can_see(seat_layout, previous, width, i, -1, +0) +
            can_see(seat_layout, previous, width, i, +1, +0) +
            can_see(seat_layout, previous, width, i, -1, +1) +
            can_see(seat_layout, previous, width, i, +0, +1) +
            can_see(seat_layout, previous, width, i, +1, +1);
        if (seat_layout[i]) {
            if (previous[i] && (adjecent > 4)) {
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
