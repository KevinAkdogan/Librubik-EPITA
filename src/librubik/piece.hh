#pragma once

#include <cmath>

#include "color.hh"
#include "move.hh"
#include "vector3D.hh"

namespace rubik
{
    // FIXME
    class Piece
    {
    public:
        Vector3D<int> coords;
        Vector3D<Color> colors;

        Piece(Vector3D<int> coord, Vector3D<Color> color)
            : coords(coord)
            , colors(color)
        {}

        enum Type
        {
            CORNER,
            EDGE,
            CENTER,
            NONE
        };

        Type get_type();

        inline bool operator==(Piece& piece)
        {
            return (coords == piece.coords && colors == piece.colors);
        }

        inline bool operator!=(Piece& piece)
        {
            return (coords != piece.coords || colors != piece.colors);
        }

        inline bool operator<(Piece& piece)
        {
            if (coords.x > piece.coords.x || coords.x < piece.coords.x)
            {
                return (coords.x < piece.coords.x);
            }
            if (coords.y > piece.coords.y || coords.y < piece.coords.y)
            {
                return (coords.y < piece.coords.y);
            }
            return (coords.z < piece.coords.z);
        }

        inline bool operator>(Piece& piece)
        {
            if (coords.x > piece.coords.x || coords.x < piece.coords.x)
            {
                return (coords.x > piece.coords.x);
            }
            if (coords.y > piece.coords.y || coords.y < piece.coords.y)
            {
                return (coords.y > piece.coords.y);
            }
            return (coords.z > piece.coords.z);
        }

        inline bool operator>=(Piece& piece)
        {
            return ((coords == piece.coords && colors == piece.colors)
                || *this > piece);
        }

        inline bool operator<=(Piece& piece)
        {
            return ((coords == piece.coords && colors == piece.colors)
                || *this < piece);
        }

        void do_move(Face face, Direction dir);
        void do_move(Axis axis, Direction dir);
    };

    inline std::ostream& operator<<(std::ostream& os, Piece::Type& type)
    {
        std::vector<std::string> vect = { "CORNER", "CENTER", "EDGE", "NONE" };
        os << vect[type];
        return os;
    }

    inline std::ostream& operator<<(std::ostream& os, Piece piece)
    {
        return (os << piece.coords << ' ' << piece.colors);
    }

} // namespace rubik
