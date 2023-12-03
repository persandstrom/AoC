#include "aoc_util.h"

namespace aoc {
    void check_adjecent(
            const std::vector<std::string>& input,
            const int x,
            const int y,
            std::function<void(const char)> func) {
        const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < input[0].size() && ny >= 0 && ny < input.size()) {
                func(input[ny][nx]);
            }
        }
    }

    void check_adjecent(
            const std::vector<std::string>& input,
            const int x,
            const int y,
            std::function<void(const int,const int,const char)> func) {
        const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < input[0].size() && ny >= 0 && ny < input.size()) {
                func(nx, ny, input[ny][nx]);
            }
        }
    }
}