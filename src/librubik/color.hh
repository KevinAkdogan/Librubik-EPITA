#pragma once
#include <ostream>
#include <vector>

using namespace std;

namespace rubik
{
    // FIXME
    enum class Color : char
    {
        WHITE = 'W',
        GREEN = 'G',
        ORANGE = 'O',
        BLUE = 'B',
        YELLOW = 'Y',
        RED = 'R',
        NONE = 'X',
    };

    inline ostream& operator<<(ostream& os, Color color)
    {
        return os << static_cast<char>(color);
    }

} // namespace rubik
