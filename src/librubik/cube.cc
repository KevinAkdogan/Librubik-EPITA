#include "cube.hh"

#include <algorithm>
#include <istream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <variant>

#include "vector3D.hh"

using namespace std;

namespace rubik
{
    // FIXME
    Cube::Cube()
    {
        auto colorX = [](int position) {
            if (position == -1)
                return Color::BLUE;
            else if (position == 0)
                return Color::NONE;
            else
                return Color::GREEN;
        };

        auto colorY = [](int position) {
            if (position == -1)
                return Color::ORANGE;
            else if (position == 0)
                return Color::NONE;
            else
                return Color::RED;
        };

        auto colorZ = [](int position) {
            if (position == -1)
                return Color::YELLOW;
            else if (position == 0)
                return Color::NONE;
            else
                return Color::WHITE;
        };

        for (int x = -1; x <= 1; x++)
        {
            for (int y = -1; y <= 1; y++)
            {
                for (int z = -1; z <= 1; z++)
                {
                    Vector3D<int> coord{ x, y, z };
                    Color xc = colorX(x);
                    Color yc = colorY(y);
                    Color zc = colorZ(z);

                    auto idx = Piece(coord, { xc, yc, zc });
                    pieces_.insert(pieces_.begin(), idx);
                }
            }
        }
    }

    int funcTokenCoords(std::string token)
    {
        int tmp;
        stringstream ss(token);
        ss >> tmp;

        if (!ss.eof())
        {
            throw std::invalid_argument("Parse error");
        }
        return tmp;
    }

    Vector3D<int> vectCoords(std::string str)
    {
        if (str[0] != '(' || str.back() != ')')
        {
            throw std::invalid_argument("Miss bracket");
        }

        str = str.substr(1, str.length() - 2);
        size_t end = 0;
        std::vector<int> ctoken;

        while ((end = str.find(',')) != std::string::npos)
        {
            std::string token = str.substr(0, end);
            ctoken.push_back(funcTokenCoords(token));
            str = str.substr(end + 1);
        }
        ctoken.push_back(funcTokenCoords(str));

        if (ctoken.size() != 3)
        {
            throw std::invalid_argument("Invalid coordinates");
        }

        Vector3D<int> fin{ ctoken[0], ctoken[1], ctoken[2] };
        return fin;
    }

    Color funcTokenColor(std::string token)
    {
        if (token.length() > 1)
        {
            throw std::invalid_argument("Wrong color");
        }
        std::string st = "YWROBGX";
        if (st.find(token) == std::string::npos)
        {
            throw std::invalid_argument("Wrong color");
        }
        Color color = static_cast<Color>(token[0]);
        return color;
    }

    Vector3D<Color> vectColor(std::string str)
    {
        if (str[0] != '(' || str.back() != ')')
        {
            throw std::invalid_argument("Miss bracket");
        }

        str = str.substr(1, str.length() - 2);
        size_t end = 0;
        std::vector<Color> ctoken;

        while ((end = str.find(',')) != std::string::npos)
        {
            std::string token = str.substr(0, end);
            ctoken.push_back(funcTokenColor(token));
            str = str.substr(end + 1);
        }

        ctoken.push_back(funcTokenColor(str));

        if (ctoken.size() > 3)
            throw std::invalid_argument("Too much argument for color");

        Vector3D<Color> fin{ ctoken[0], ctoken[1], ctoken[2] };
        return fin;
    }

    static Piece obtPiece(std::string str)
    {
        string str_coord;
        string str_color;
        stringstream sstr(str);

        if (!(sstr >> str_coord))
        {
            throw invalid_argument("Not enougth args");
        }
        if (!(sstr >> str_color))
        {
            throw invalid_argument("Not enougth args");
        }
        if (!sstr.eof())
        {
            throw invalid_argument("Too much args");
        }

        auto x = vectCoords(str_coord);
        auto y = vectColor(str_color);
        return Piece(x, y);
    }

    Cube Cube::from_stream(std::istream& file)
    {
        vector<Piece> pieces;
        string str;

        while (getline(file, str))
        {
            auto idx = obtPiece(str);
            pieces.push_back(idx);
        }

        if (pieces.size() != 27)
        {
            throw invalid_argument("Wrong number");
        }
        return Cube(pieces);
    }

    void Cube::do_move(Move move)
    {
        if (move.mvt.index() == 1)
        {
            for (auto& idx : pieces_)
            {
                idx.do_move(get<Axis>(move.mvt), move.dir);
            }
        }
        else
        {
            switch (get<Face>(move.mvt))
            {
            case Face::UP:
                for (auto& idx : pieces_)
                {
                    if (idx.coords.z == 1)
                    {
                        idx.do_move(get<Face>(move.mvt), move.dir);
                    }
                }
                break;

            case Face::DOWN:
                for (auto& idx : pieces_)
                {
                    if (idx.coords.z == -1)
                    {
                        idx.do_move(get<Face>(move.mvt), move.dir);
                    }
                }
                break;

            case Face::LEFT:
                for (auto& idx : pieces_)
                {
                    if (idx.coords.y == -1)
                    {
                        idx.do_move(get<Face>(move.mvt), move.dir);
                    }
                }
                break;

            case Face::RIGHT:
                for (auto& idx : pieces_)
                {
                    if (idx.coords.y == 1)
                    {
                        idx.do_move(get<Face>(move.mvt), move.dir);
                    }
                }
                break;

            case Face::FRONT:
                for (auto& idx : pieces_)
                {
                    if (idx.coords.x == 1)
                    {
                        idx.do_move(get<Face>(move.mvt), move.dir);
                    }
                }
                break;

            case Face::BACK:
                for (auto& idx : pieces_)
                {
                    if (idx.coords.x == -1)
                    {
                        idx.do_move(get<Face>(move.mvt), move.dir);
                    }
                }
                break;
            }
        }
        if (move.is_double)
        {
            move.is_double = false;
            do_move(move);
        }
    }

    void Cube::do_moves(std::vector<Move> moves)
    {
        for (auto& idx : moves)
        {
            do_move(idx);
        }
    }

    void Cube::undo_move(Move move)
    {
        move.dir = (move.dir == Direction::CLOCKWISE)
            ? Direction::ANTI_CLOCKWISE
            : Direction::CLOCKWISE;
        do_move(move);
    }

    void Cube::undo_moves(std::vector<Move> moves)
    {
        for (auto& idx : moves)
        {
            undo_move(idx);
        }
    }
} // namespace rubik
