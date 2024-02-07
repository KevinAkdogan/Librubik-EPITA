#pragma once

#include <vector>

#include "../cube.hh"

// FIXME: forward declaration to make the solver code compile, you can remove it
// once you have implemented the core features.
namespace rubik
{
    class Move;
    class Cube;
}

namespace rubik::solver
{
    class Solver
    {
    public:
        virtual void load_patterns() = 0;
        virtual void setup(Cube& cube) = 0;
        virtual std::vector<Move> solve(Cube cube) = 0;
    };

} // namespace rubik::solver
