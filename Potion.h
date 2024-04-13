#include <iostream>
#include <string>
#include <array>


#ifndef POTION
#define POTION

namespace Potion {
    using namespace std::literals;

    enum Type {
        heal,
        mana,
        speed,
        invisibility,
        max_size,
    };

    constexpr size_t len{ max_size };
    constexpr std::array types{ heal, mana, speed, invisibility };

    constexpr std::array<int, len> prices{ 20, 30, 12, 50 };
    constexpr std::array<std::string_view, len> names{ "healing"sv, "mana"sv, "speed"sv, "invisibility"sv };

    static_assert(std::size(types) == len);  // ensure 'all' contains the correct number of enumerators
    static_assert(std::size(prices) == len);
    static_assert(std::size(names) == len);
}


#endif // !POTION
