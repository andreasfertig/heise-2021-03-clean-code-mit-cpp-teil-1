// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <compare>

// fake of QPoint to drop the dependency
struct QPoint
{
    int mX;
    int mY;

    constexpr auto x() const { return mX; }
    constexpr auto y() const { return mY; }
};

struct Point
{
    int x;
    int y;

    constexpr bool operator==(const Point&) const noexcept      = default;
    constexpr auto operator<=>(const Point& rhs) const noexcept = default;
};

constexpr bool operator==(const QPoint& lhs, const Point& rhs) noexcept
{
    return (lhs.x() == rhs.x) && (lhs.y() == rhs.y);
}

constexpr auto operator<=>(const QPoint& lhs, const Point& rhs) noexcept
{
    if(lhs == rhs) {
        return std::strong_ordering::equal;
    } else if((lhs.x() < rhs.x) && (lhs.x() < rhs.y)) {
        return std::strong_ordering::less;
    }

    return std::strong_ordering::greater;
}

constexpr Point a{2, 3};
constexpr Point b{2, 3};
constexpr Point c{3, 3};

static_assert(a == b);
static_assert(not(a != b));
static_assert(not(a == c));
static_assert(a != c);

constexpr QPoint op{2, 3};
constexpr QPoint op2{4, 3};

static_assert(a == op);
static_assert(op == a);

static_assert(not(a != op));
static_assert(not(op != a));

static_assert(a < c);
static_assert(c > a);

static_assert(a <= c);
static_assert(c >= a);

static_assert(a <= b);
static_assert(a >= b);

static_assert(a < op2);
static_assert(op2 > a);

static_assert(a <= op);
static_assert(op >= a);

static_assert(a <= op);
static_assert(a >= op);

int main() {}