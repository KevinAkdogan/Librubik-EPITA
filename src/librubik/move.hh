#pragma once

#include <sstream>
#include <string>
#include <variant>
#include <vector>

namespace rubik
{
    // FIXME
    enum class Direction
    {
        CLOCKWISE = 'C',
        ANTI_CLOCKWISE = '\''
    };

    enum class Face
    {
        UP = 'U',
        DOWN = 'D',
        LEFT = 'L',
        RIGHT = 'R',
        FRONT = 'F',
        BACK = 'B',
    };

    enum class Axis
    {
        X = 'x',
        Y = 'y',
        Z = 'z'
    };

    class Move
    {
    public:
        std::variant<Face, Axis> mvt;
        Direction dir = Direction::CLOCKWISE;
        bool is_double = false;
    };

    void add_moves(std::vector<Move>& mv, char token);
    std::vector<Move> parse_moves(std::string input);
} // namespace rubik
