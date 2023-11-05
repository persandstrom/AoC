#ifndef FABRICPIECE_H
#define FABRICPIECE_H

#include <string>
#include <iostream>

#include <cstdlib>

class FabricPiece {

    private:
    FabricPiece(const int id, const int x, const int y, const int w, const int h)
        : id(id), start_x(x), start_y(y), end_x(x+w), end_y(y+h) {}

    public:
    const int id, start_x, start_y, end_x, end_y;
    
    [[nodiscard]] static FabricPiece FromString(const std::string& line) {
        auto const p1 = line.find('@');
        auto const p2 = line.find(',', p1+1);
        auto const p3 = line.find(':', p2+1);
        auto const p4 = line.find('x', p3+1);

        if ( p1 == std::string::npos ||
             p2 == std::string::npos ||
             p3 == std::string::npos || 
             p4 == std::string::npos) {
            std::cerr << "Malformed input: '" << line << "'" << std::endl;
            return FabricPiece(0, 0, 0, 0, 0);
        }

        try {
            return FabricPiece(
                stoi(line.substr(1, p1)),
                stoi(line.substr(p1+1, p2-(p1+1))),
                stoi(line.substr(p2+1, p3-(p2+1))),
                stoi(line.substr(p3+1, p4-(p3+1))),
                stoi(line.substr(p4+1)));
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument: " << e.what() << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Out of range: " << e.what() << std::endl;
        }
        return FabricPiece(0, 0, 0, 0, 0);
    }
    
    [[nodiscard]] const bool is_valid() const {
        return 
            (id > 0) ||
            (start_x > 0) ||
            (start_y > 0) ||
            (end_x > 0) ||
            (end_y > 0);
    }
};

#endif // FABRICPIECE_H