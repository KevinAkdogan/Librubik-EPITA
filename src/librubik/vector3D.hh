#pragma once

#include "ostream"

using namespace std;

namespace rubik
{
    // FIXME
    template <typename Temp>
    class Vector3D
    {
    public:
        Temp x;
        Temp y;
        Temp z;

        friend std::ostream& operator<<(ostream& os, Vector3D<Temp> vect)
        {
            os << '(' << vect.x << ',' << vect.y << ',' << vect.z << ')';
            return os;
        }

        inline bool operator==(Vector3D<Temp>& vect)
        {
            return (vect.x == x && vect.y == y && vect.z == z);
        }

        inline bool operator!=(Vector3D<Temp>& vect)
        {
            return (vect.x != x || vect.y != y || vect.z != z);
        }
    };

} // namespace rubik
