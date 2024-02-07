#pragma once

#include <string>
#include <vector>

namespace rubik::solver
{
    std::vector<std::vector<std::string>> parse_csv(const std::string& f);

} // namespace rubik::solver
