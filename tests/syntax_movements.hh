#include <array>
#include <iostream>
#include <librubik/cube.hh>
#include <librubik/matrix3D.hh>
#include <librubik/move.hh>
#include <librubik/piece.hh>
#include <librubik/vector3D.hh>

#include "gtest/gtest.h"

namespace rubik
{
    // FIXME: Uncomment each test once the corresponding step is implemented

    /*

    TEST(syntax_movements, matrix3D_class)
    {
        std::array<std::array<int, 3>, 3> values = {
            { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } }
        };
        auto matrix = Matrix3D<int>{ values };
        matrix.at(0, 2);

        auto res = matrix * Vector3D<int>{ 1, 2, 3 };
        (void)(res);
        matrix.transpose();
    }

    TEST(syntax_movements, move_piece)
    {
        Axis all_axes[] = { Axis::X, Axis::Y, Axis::Z };
        Direction all_dirs[] = { Direction::CLOCKWISE,
                                 Direction::ANTI_CLOCKWISE };
        Face all_faces[] = { Face::UP,    Face::DOWN,  Face::LEFT,
                             Face::RIGHT, Face::FRONT, Face::BACK };

        auto piece =
            Piece{ { 1, -1, 0 }, { Color::GREEN, Color::ORANGE, Color::NONE } };
        piece.do_move(all_faces[0], all_dirs[0]);
        piece.do_move(all_axes[0], all_dirs[1]);
    }

    TEST(syntax_movements, move_face)
    {
        auto move = Move{ Face::RIGHT, Direction::CLOCKWISE, false };
        (move.mvt);
        (move.dir);
        (move.is_double);

        Move{ Face::UP, Direction::CLOCKWISE, false };
        Move{ Axis::X, Direction::CLOCKWISE, false };
        Move{ Face::LEFT };
        Move{ Face::FRONT, Direction::ANTI_CLOCKWISE };

        Cube cube;
        cube.do_move(move);
        cube.undo_move(move);
        cube.do_moves({ move });
        cube.undo_moves({ move });

        parse_moves("U' R2 F x");
    }

    */

} // namespace rubik
