// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <compare>

struct Point
{
    float x;
    int   y;

    constexpr bool operator==(const Point&) const noexcept      = default;
    constexpr auto operator<=>(const Point& rhs) const noexcept = default;
};

constexpr Point a{2, 3};
constexpr Point b{2, 3};
constexpr Point c{3, 3};

static_assert(a == b);
static_assert(not(a != b));
static_assert(not(a == c));
static_assert(a != c);

static_assert(a < c);
static_assert(c > a);

static_assert(a <= c);
static_assert(c >= a);

static_assert(a <= b);
static_assert(a >= b);

int main() {}