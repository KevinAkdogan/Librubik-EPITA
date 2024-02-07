#include <algorithm>
#include <fstream>
#include <iostream>
#include <librubik/color.hh>
#include <librubik/cube.hh>
#include <librubik/piece.hh>
#include <librubik/vector3D.hh>

#include "gtest/gtest.h"

namespace rubik
{
    // FIXME: Uncomment each test once the corresponding step is implemented

    TEST(syntax_core, color_enum)
    {
        auto all_colors = { Color::WHITE, Color::YELLOW, Color::GREEN,
                            Color::BLUE,  Color::RED,    Color::ORANGE,
                            Color::NONE };

        for (const auto &c : all_colors)
            std::cout << c;
        std::cout << '\n';
    }

    /*

    TEST(syntax_core, vector3D_class)
    {
        auto my_coords = Vector3D<int>{ 0, 1, -1 };
        auto my_colors =
            Vector3D<Color>{ Color::NONE, Color::RED, Color::YELLOW };

        (my_coords.x);
        (my_coords.y);
        (my_coords.z);

        std::cout << my_coords << ' ' << my_colors << '\n';

        (my_coords == my_coords);
        (my_colors != my_colors);
    }

    TEST(syntax_core, piece_class)
    {
        auto piece =
            Piece{ { 1, -1, 0 }, { Color::GREEN, Color::ORANGE, Color::NONE } };
        (piece.coords);
        (piece.colors);

        std::cout << piece << '\n';

        auto type = piece.get_type();
        (type == Piece::Type::CENTER);
        (type == Piece::Type::EDGE);
        (type == Piece::Type::CORNER);

        (piece == piece);
        (piece < piece);

        (piece != piece);
        (piece > piece);
        (piece <= piece);
        (piece >= piece);
    }

    TEST(syntax_core, cube_class)
    {
        Cube cube;
        std::cout << cube << '\n';

        std::ifstream file("tests/cube_state_example.txt");
        auto example_cube = Cube::from_stream(file);

        for (auto piece : cube)
            piece.get_type();
        std::sort(cube.begin(), cube.end());

        cube.find_piece({ 0, 1, 0 });
        cube.find_piece({ Color::GREEN, Color::RED, Color::WHITE });
    }

    */

} // namespace rubik
