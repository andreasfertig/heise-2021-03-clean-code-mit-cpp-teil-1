// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <compare>

struct Point
{
    int x;
    int y;

    constexpr bool operator==(const Point&) const noexcept  = default;
    constexpr auto operator<=>(const Point&) const noexcept = default;
};

constexpr Point a{2, 3};
constexpr Point b{2, 3};
constexpr Point c{3, 3};
constexpr Point d{2, 4};

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

static_assert(a <= d);
static_assert(not(a >= d));

int main() {}