#pragma once

#include "../template.h"

/****************************** begin /math/math.h ******************************/

const int mod = 1e9 + 7;  // CHANGE

ll reduce(ll x) {
    x %= mod;
    if(x < 0) x += mod;
    return x;
}
ll bexp(ll b, ll p) {
    b = reduce(b);
    ll res = 1; ll curr = b;
    while(p) {
        if(p%2) {
            res *= curr; res %= mod;
        }
        curr *= curr; 
        curr %= mod;
        p /= 2LL;
    }
    return res;
}
ll inv(ll x) {
    return bexp(x, mod-2);
}
template<uint32_t world_size> class Combinatorics
{
private:
    ll factorial_cache[world_size+1];
    ll inverse_factorial_cache[world_size+1];
public:
    Combinatorics()
    {
        factorial_cache[0] = 1;
        factorial_cache[1] = 1;
        for(int i = 2; i <= world_size; ++i)
        {
            factorial_cache[i] = factorial_cache[i-1] * i;
            factorial_cache[i] %= mod;
        }
        inverse_factorial_cache[world_size] = inv(factorial_cache[world_size]);
        for(int i = world_size - 1; i >= 0; --i)
        {
            inverse_factorial_cache[i] = (i+1LL) * inverse_factorial_cache[i+1];
            inverse_factorial_cache[i]  %= mod;
        }
    }

    inline ll fact(int x)
    {
        return factorial_cache[x];
    }

    inline ll ifact(int x)
    {
        return inverse_factorial_cache[x];
    }

    inline ll permute(int n, int k)
    {
        if(k > n) return 0;
        return (fact(n) * ifact(n-k)) % mod;
    }
    inline ll choose(int n, int k)
    {
        if(k > n) return 0;
        return (((fact(n) * ifact(k)) % mod) * ifact(n-k)) % mod;
    }
};

inline ll gcd(ll a, ll b) 
{
    return (b == 0) ? a : gcd(b, a % b);
}

inline ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
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

    void get_divisors(int x, vector<int>& res, int out_factor = 1)
    {
        if(x != 1)
        {
            int cnt = 0;
            int curr = this->sieve[x];
            while(this->sieve[x] == curr)
            {
                cnt++;
                x /= curr;
            }
            for(int chosen_cnt = 0, extra_factor = 1; chosen_cnt <= cnt; ++chosen_cnt, extra_factor *= curr)
            {
                get_divisors(x, res, out_factor * extra_factor);
            }
        }
        else
        {
            return res.push_back(out_factor);
        }
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
/****************************** end /math/math.h ******************************/