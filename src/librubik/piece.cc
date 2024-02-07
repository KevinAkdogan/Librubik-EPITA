#include "piece.hh"

#include "matrix3D.hh"

using namespace std;

namespace rubik
{
    // FIXME
    Piece::Type Piece::get_type()
    {
        if (abs(coords.x) == 1 && abs(coords.y) == 1 && abs(coords.z) == 1)
            return Type::CORNER;

        if (abs(coords.x) + abs(coords.y) + abs(coords.z) == 1)
            return Type::CENTER;

        if (abs(coords.x) + abs(coords.y) + abs(coords.z) == 2)
            return Type::EDGE;

        return Type::NONE;
    }

    void Piece::do_move(Face face, Direction dir)
    {
        int test = dir == Direction::CLOCKWISE ? 1 : -1;

        array<array<int, 3>, 3> mx = {
            { { 1, 0, 0 }, { 0, 0, -test }, { 0, test, 0 } }
        };
        array<array<int, 3>, 3> my = {
            { { 0, 0, test }, { 0, 1, 0 }, { -test, 0, 0 } }
        };
        array<array<int, 3>, 3> mz = {
            { { 0, -test, 0 }, { test, 0, 0 }, { 0, 0, 1 } }
        };

        Matrix3D<int> rx(mx);
        Matrix3D<int> ry(my);
        Matrix3D<int> rz(mz);

        auto swap = [](Color& x, Color& y) {
            auto tmp = x;
            x = y;
            y = tmp;
        };

        switch (face)
        {
        case Face::UP:
            rz.transpose();
            coords = rz * coords;
            swap(colors.x, colors.y);
            break;

        case Face::DOWN:
            coords = rz * coords;
            swap(colors.x, colors.y);
            break;
        
        case Face::RIGHT:
            ry.transpose();
            coords = ry * coords;
            swap(colors.x, colors.z);
            break;
        
        case Face::LEFT:
            coords = ry * coords;
            swap(colors.x, colors.z);
            break;
        
        case Face::FRONT:
            rx.transpose();
            coords = rx * coords;
            swap(colors.y, colors.z);
            break;
        
        case Face::BACK:
            coords = rx * coords;
            swap(colors.y, colors.z);
            break;
        }
    }

    void Piece::do_move(Axis axis, Direction dir)
    {
        if (axis == Axis::X)
        {
            do_move(Face::RIGHT, dir);
        }
        if (axis == Axis::Y)
        {
            do_move(Face::UP, dir);
        }
        if (axis == Axis::Z)
        {
            do_move(Face::FRONT, dir);
        }
    }
} // namespace rubik
