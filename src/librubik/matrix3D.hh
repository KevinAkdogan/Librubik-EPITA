#pragma once

#include <array>
#include <vector>

#include "vector3D.hh"

using namespace std;

namespace rubik
{
    // FIXME
    template <typename T>
    class Matrix3D
    {
    public:
        Matrix3D(array<array<T, 3>, 3> val)
            : matrix_(val)
        {}

        T at(int x, int y)
        {
            return matrix_[x][y];
        }

        Vector3D<T> operator*(const Vector3D<T>& v) const
        {
            Vector3D<T> vector{ 0, 0, 0 };
            for (int idx = 0; idx < 3; idx++)
            {
                std::vector<T> vect = { v.x, v.y, v.z };
                vector.x += matrix_[0][idx] * vect[idx];
                vector.y += matrix_[1][idx] * vect[idx];
                vector.z += matrix_[2][idx] * vect[idx];
            }
            return vector;
        }

        void transpose()
        {
            array<array<T, 3>, 3> mat;
            for (int idx = 0; idx < 3; idx++)
            {
                for (int jdx = 0; jdx < 3; jdx++)
                {
                    mat[jdx][idx] = matrix_[idx][jdx];
                }
            }
            matrix_ = mat;
        }

    private:
        array<array<T, 3>, 3> matrix_;
    };

} // namespace rubik
