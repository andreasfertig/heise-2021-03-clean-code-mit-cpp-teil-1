// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


struct Point
{
    int x;
    int y;

    constexpr bool operator==(const Point& rhs) const noexcept
    {
        return (x == rhs.x) && (y == rhs.y);
    }

    constexpr bool operator<(const Point& rhs) const noexcept
    {
        return (x < rhs.x) && (x < rhs.y);
    }

    constexpr bool operator>(const Point& rhs) const noexcept
    {
        return not(*this < rhs);
    }
    constexpr bool operator<=(const Point& rhs) const noexcept
    {
        return (*this == rhs) || (*this < rhs);
    }
    constexpr bool operator>=(const Point& rhs) const noexcept
    {
        return (*this == rhs) || (*this > rhs);
    }
};

constexpr Point a{2, 3};
constexpr Point b{2, 3};
constexpr Point c{3, 3};

static_assert(a == b);
static_assert(not(a == c));

static_assert(a < c);
static_assert(c > a);

static_assert(a <= c);
static_assert(c >= a);

static_assert(a <= b);
static_assert(a >= b);

int main() {}