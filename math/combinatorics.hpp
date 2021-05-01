#pragma once

#include "modint.hpp"

namespace CompetitiveProgramming
{

namespace Math
{

template<uint32_t world_size> class Combinatorics
{
private:
    Mint factorial_cache[world_size+1];
    Mint inverse_factorial_cache[world_size+1];
public:
    Combinatorics()
    {
        factorial_cache[0] = 1;
        factorial_cache[1] = 1;
        for(int i = 2; i <= world_size; ++i)
        {
            factorial_cache[i] = factorial_cache[i-1] * i;
        }
        inverse_factorial_cache[world_size] = 1 / factorial_cache[world_size];
        for(int i = world_size - 1; i >= 0; --i)
        {
            inverse_factorial_cache[i] = (i+1) * inverse_factorial_cache[i+1];
        }
    }

    inline Mint fact(int x)
    {
        return factorial_cache[x];
    }

    inline Mint ifact(int x)
    {
        return inverse_factorial_cache[x];
    }

    inline Mint permute(int n, int k)
    {
        if(k > n) return (Mint)0;
        return fact[n] * ifact(n-k);
    }
    inline Mint choose(int n, int k)
    {
        if(k > n) return (Mint)0;
        return fact(n) * ifact(k) * ifact(n-k);
    }
};

}

}

using namespace Math;