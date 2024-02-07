// FIXME: You can include various files from the librubik library
// #include <librubik/cube.hh>
#include <iostream>

#include "librubik/color.hh"
#include "librubik/cube.hh"
#include "librubik/matrix3D.hh"
#include "librubik/move.hh"
#include "librubik/piece.hh"
#include "librubik/vector3D.hh"

using namespace std;
using namespace rubik;

int main()
{
    // FIXME: This is where you should play around with librubik.
    // Do not forget to use the 'rubik' namespace prefix (rubik::Cube,
    // rubik::Move, ...)
    auto c1 = Color::YELLOW;
    auto c2 = Color::BLUE;
    auto c3 = Color::ORANGE;
    cout << c1 << ' ' << c2 << ' ' << c3 << '\n';
    cout << Color::NONE << '\n';
    // Must print: Y B O
    // Must print: X

    auto coords = Vector3D<int>{ 0, 1, 1 };
    auto colors = Vector3D<Color>{ Color::NONE, Color::RED, Color::WHITE };
    cout << coords << ' ' << colors << '\n';
    // Must print: (0,1,1) (X,R,W)

    auto front_left_edge =
        Piece{ { 1, -1, 0 }, { Color::GREEN, Color::ORANGE, Color::NONE } };
    cout << front_left_edge << '\n';
    // Must print: (1,-1,0) (G,O,X)

    Cube cube;
    auto red_center = cube.find_piece({ 0, 1, 0 });
    cout << red_center << '\n';
    // Must print: (0,1,0) (X,R,X)

    // A constructor accepting a 3×3 array
    array<std::array<int, 3>, 3> values = { { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } }};
    auto matrix = Matrix3D<int>{ values };
    // A getter to access individual elements
    cout << matrix.at(1, 1) << '\n'; 
    // Must print: 5

    matrix.transpose();
    cout << matrix.at(1, 1) << ' ' << matrix.at(0, 1) << ' ' << matrix.at(0, 2) << '\n';
    // Must print: 5 4 7
    auto res = matrix * Vector3D<int>{ 1, 2, 3 };
    cout << res << '\n';
    // Must print: (30,36,42)

    Cube cube2;
    cube2.do_moves(parse_moves("F' D' R2 x L' U B R F U2 F2 L2 L y2 F' B2 U2 D B' z'"));
    cout << cube2 << '\n';

    return 0;
}
