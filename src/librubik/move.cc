#include "move.hh"

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace rubik
{
    // FIXME
    void add_moves(std::vector<Move>& moves, char token)
    {
        std::string face = "UDLRFB";
        std::string axis = "xyz";

        if (face.find(token) != std::string::npos)
        {
            auto move = Move{ Face(token), Direction::CLOCKWISE };
            moves.push_back(move);
        }
        else if (axis.find(token) != std::string::npos)
        {
            auto move = Move{ Axis(token), Direction::CLOCKWISE };
            moves.push_back(move);
        }
        else
            throw std::invalid_argument("Invalid move");
    }

    std::vector<Move> parse_moves(std::string input)
    {
        input.erase(remove_if(input.begin(), input.end(), isspace),
                    input.end());
        std::string rsx = "'2";
        std::vector<Move> moves;
        size_t end = 0;

        while ((end = input.find_first_of(rsx)) != std::string::npos)
        {
            std::string token = input.substr(0, end);
            for (size_t idx = 0; idx < token.length(); idx++)
            {
                add_moves(moves, token[idx]);
            }
            if (input[end] == '\'')
            {
                moves.back().dir = (moves.back().dir == Direction::CLOCKWISE)
                    ? Direction::ANTI_CLOCKWISE
                    : Direction::CLOCKWISE;
            }
            else if (input[end] == '2')
            {
                moves.push_back(moves.back());
            }
            input = input.substr(end + 1);
        }

        for (size_t idx = 0; idx < input.length(); idx++)
        {
            add_moves(moves, input[idx]);
        }
        return moves;
    }
} // namespace rubik
