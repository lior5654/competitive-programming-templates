#pragma once

#include "../general.hpp"

namespace CompetitiveProgramming
{

namespace Math
{

inline ll gcd(ll a, ll b) 
{
    return (b == 0) ? a : gcd(b, a % b);
}

inline ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

struct EGCDResult
{
    ll x;
    ll y;
    ll d; 
};

EGCDResult extended_gcd(ll a, ll b) // theorem: there exist x, y such that x*a + y*b == gcd(a, b)
{
    if(b == 0) return EGCDResult{ .x = 1, .y = 0, .d = a };
    EGCDResult next_stage = extended_gcd(b, a % b);
    return EGCDResult{ .x = next_stage.y, .y = next_stage.x - a / b * next_stage.y, .d = next_stage.d };
}

}

}

using namespace Math;