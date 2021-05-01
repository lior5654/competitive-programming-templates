#pragma once

#include "../general.hpp"

namespace CompetitiveProgramming
{

namespace Math
{

template<uint32_t sieve_size> class FactorSieve
{
public:
    int sieve[sieve_size+1];

    FactorSieve()
    {
        sieve[1] = 1;
        for(int i = 2; i <= sieve_size; ++i)
        {
            if(!sieve[i])
            {
                for(int j = i ; j <= sieve_size; j += i)
                {
                    sieve[j] = i;

                }
            }
        }
    }

    inline vector<pair<int, int>> factor(int x)
    {
        vector<pair<int, int>> factors;
        while(x != 1)
        {
            int cnt = 0;
            int curr = this->sieve[x];
            while(this->sieve[x] == curr)
            {
                cnt++;
                x /= curr;
            }
            factors.emplace_back(curr, cnt);
        }
        return factors;
    }
    inline bool is_prime(int x)
    {
        return sieve[x] == x && x != 1;
    }
};

template<uint32_t sieve_size> class BooleanSieve
{
public:
    bitset<sieve_size+1> is_composite;

    BooleanSieve()
    {
        is_composite = 0;
        is_composite[1] = 1;
        for(int i = 2; i <= sieve_size; ++i)
        {
            if(!is_composite[i])
            {
                for(int j = 2*i ; j <= sieve_size; j += i)
                {
                    is_composite[j] = 1;

                }
            }
        }
    }

    inline bool is_prime(int x)
    {
        return !is_composite[x];
    }
};

}

}

using namespace Math;