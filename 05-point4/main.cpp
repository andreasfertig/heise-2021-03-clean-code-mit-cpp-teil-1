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
    constexpr bool operator!=(const Point& rhs) const noexcept
    {
        return not(*this == rhs);
    }
};

// fake of QPoint to drop the dependency
struct QPoint
{
    int mX;
    int mY;

    constexpr auto x() const { return mX; }
    constexpr auto y() const { return mY; }
};

constexpr bool operator==(const QPoint& lhs, const Point& rhs) noexcept
{
    return (lhs.x() == rhs.x) && (lhs.y() == rhs.y);
}

constexpr Point a{2, 3};
constexpr Point b{2, 3};
constexpr Point c{3, 3};

static_assert(a == b);
static_assert(not(a != b));
static_assert(not(a == c));
static_assert(a != c);

constexpr QPoint op{2, 3};

static_assert(a == op);
static_assert(op == a);

static_assert(not(a != op));
static_assert(not(op != a));

int main() {}