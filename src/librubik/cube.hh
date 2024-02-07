#pragma once

#include <algorithm>
#include <istream>
#include <iterator>
#include <ostream>
#include <vector>

#include "piece.hh"
#include "vector3D.hh"

namespace rubik
{
    // FIXME
    class Cube
    {
    public:
        Cube();
        Cube(std::vector<Piece> pieces)
            : pieces_(pieces)
        {}

        std::vector<Piece>::iterator begin()
        {
            return pieces_.begin();
        }

        std::vector<Piece>::iterator end()
        {
            return pieces_.end();
        }

        std::vector<Piece>::const_iterator begin() const
        {
            return pieces_.cbegin();
        }

        std::vector<Piece>::const_iterator end() const
        {
            return pieces_.cend();
        }

        Piece find_piece(Vector3D<int> coords) const
        {
            for (auto idx : *this)
            {
                if (idx.coords == coords)
                    return idx;
            }
            throw std::invalid_argument("Not find piece");
        }

        Piece find_piece(Vector3D<Color> colors) const
        {
            std::vector<Color> color = { colors.x, colors.y, colors.z };
            std::sort(color.begin(), color.end());

            for (auto idx : pieces_)
            {
                std::vector<Color> actual = { idx.colors.x, idx.colors.y,
                                              idx.colors.z };
                std::sort(actual.begin(), actual.end());
                if (actual == color)
                {
                    return idx;
                }
            }
            throw std::invalid_argument("Not find piece");
        }

        static Cube from_stream(std::istream& file);

        friend std::ostream& operator<<(std::ostream& os, Cube& cube)
        {
            for (auto& idx : cube.pieces_)
            {
                os << idx << '\n';
            }
            return os;
        }

        void do_move(Move move);
        void do_moves(std::vector<Move> moves);
        void undo_move(Move move);
        void undo_moves(std::vector<Move> moves);

    private:
        std::vector<Piece> pieces_;
    };

} // namespace rubik
