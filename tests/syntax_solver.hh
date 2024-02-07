#include <algorithm>
#include <iostream>
#include <librubik/cube.hh>
#include <librubik/solver/f2l.hh>
#include <librubik/solver/oll.hh>
#include <librubik/solver/pll.hh>
#include <memory>

#include "gtest/gtest.h"

namespace rubik
{
    // FIXME: Uncomment each test once the corresponding step is implemented

    /*

    using namespace rubik::solver;

    TEST(syntax_solver, F2L)
    {
        Cube cube;
        // Example of a cube scramble
        cube.do_moves(parse_moves("F R L2 L' R' B' D L2 U2 L x F' z2 F U2 U y'"
            "B' D2 B2"));

        F2L f2l{
        "patterns/layer1_white_edges.csv",
        "patterns/layer1_white_corners.csv",
        "patterns/layer2_edges.csv",
        };

        f2l.load_patterns();
        f2l.setup(cube);
        std::vector<Move> solver_moves = f2l.solve(cube);
    }

    // BONUS STEP
    TEST(syntax_solver, OLL)
    {
        Cube cube;
        // Example of a cube scramble
        cube.do_moves(parse_moves("F R L2 L' R' B' D L2 U2 L x F' z2 F U2 U y'"
            "B' D2 B2"));

        auto f2l = std::make_shared<F2L>(std::initializer_list<std::string>{
            "patterns/layer1_white_edges.csv",
            "patterns/layer1_white_corners.csv",
            "patterns/layer2_edges.csv"
        });

        auto oll = std::make_shared<OLL>(
            "patterns/layer3_oll.csv"
        );

        std::vector<std::shared_ptr<Solver>> solvers = {
            f2l,
            oll
        };

        for (auto solver : solvers)
        {
            solver->load_patterns();
            solver->setup(cube);
            std::vector<Move> solver_moves = solver->solve(cube);
            cube.do_moves(solver_moves);
        }
    }

    // BONUS STEP
    TEST(syntax_solver, PLL)
    {
        Cube cube;
        // Example of a cube scramble
        cube.do_moves(parse_moves("F R L2 L' R' B' D L2 U2 L x F' z2 F U2 U y'"
    "B' D2 B2"));

        auto f2l = std::make_shared<F2L>(std::initializer_list<std::string>{
            "patterns/layer1_white_edges.csv",
            "patterns/layer1_white_corners.csv",
            "patterns/layer2_edges.csv"
        });

        auto oll = std::make_shared<OLL>(
            "patterns/layer3_oll.csv"
        );

        auto pll = std::make_shared<PLL>(
            "patterns/layer3_pll.csv"
        );

        std::vector<std::shared_ptr<Solver>> solvers = {
            f2l,
            oll,
            pll
        };

        for (auto solver : solvers)
        {
            solver->load_patterns();
            solver->setup(cube);
            std::vector<Move> solver_moves = solver->solve(cube);
            cube.do_moves(solver_moves);
        }
    }

    */

} // namespace rubik
