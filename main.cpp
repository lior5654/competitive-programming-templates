#include "general.hpp"
#include "math/sieve.hpp"
#include "math/modint.hpp"
#include "math/combinatorics.hpp"
#include "math/number_theory.hpp"

signed main()
{
    vector<int> v(3);
    read_container(v);
    output_container(v);
    int a[4];
    read_array(a+1, 3);
    output_iterator_range(a+1, a+4);
    output_array(a+1, 3);
    FactorSieve<1000> s;
    auto f = s.factor(525);
    for(const auto& e : f)
    {
        cout << e.first << ' ' << e.second << '\n';
    }
    cout << s.is_prime(4) << ' ' << s.is_prime(3) << '\n';
    BooleanSieve<100> t;
    cout << t.is_prime(37) << ' ' << t.is_prime(38) << '\n';
    cout << t.is_prime(1) << '\n';
    Mint x = 1000000006;
    x *= 1000000006;
    cout << x << '\n';
    
    Combinatorics<100> yay;

    ll maybe = 1;
    for(ll i = 2; i <= 100; ++i)
    {
        maybe *= i; maybe %= 1000000007;
    }
    cout << maybe << ' ' << yay.fact(100) << '\n';

    cout << gcd(105, 189) << '\n';
    cout << lcm(10, 6) << '\n';
    EGCDResult res = extended_gcd(105, 189);
    cout << res.d << ' ' << res.x << ' ' << res.y << ' ' << res.x * 105 + res.y * 189 << '\n';

    cout << yay.permute(100, 98) << '\n';
    cout << yay.choose(5, 4) << '\n';
    cout << yay.choose(0, 0) << '\n';

    vector<int> divs;
    s.get_divisors(525, divs);
    for(const auto& e : divs)
    {
        cout << e << ' ' << '\n';
    }

}