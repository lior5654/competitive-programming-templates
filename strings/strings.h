#pragma once
#include "../template.h"

/****************************** begin /strings/strings.h ******************************/

vi z_array(const string& s) {
    const int string_size = s.size();
    vi z; z.resize(string_size, 0);
    int x = 0; int y = 0;
    z[0] = 0;
    rep(i, string_size)
    {
        z[i] = max(0, min(z[i-x], y - i + 1));
        while (i + z[i] < string_size && s[z[i]] == s[i+z[i]])
        {
            ++z[i]; x = i; y = i + z[i] - 1;
        }
    }
    return z;
}



template<int hmod, int max_n> struct Hasher {
    ll p[max_n + 1]; ll ip[max_n + 1]; ll base; ll ibase;

    static inline int mod() {
        return hmod;
    }
    static inline ll reduce(ll x) {
        x %= hmod;
        if(x < 0) x += hmod;
        return x;
    }
    static inline ll bexp(ll b, ll p) {
        b = reduce(b);
        ll res = 1; ll curr = b;
        while(p) {
            if(p%2) {
                res *= curr; res %= hmod;
            }
            curr *= curr; 
            curr %= hmod;
            p /= 2LL;
        }
        return res;
    }
    static inline ll inv(ll x) {
        return bexp(x, hmod-2);
    }
    Hasher()
    {
        base = (rnd() % 10000000) + 1337;
        ibase = this->inv(base);
        p[0] = 1;
        ip[0] = 1;
        for(int i = 1; i <= max_n; ++i) {
            p[i] = p[i-1] * base; p[i] %= hmod;
            ip[i] = ip[i-1] * ibase; ip[i] %= hmod;
            assert((p[i] * ip[i]) % hmod == 1);
        }
    }
    vl hash(const string& s) {
        const int string_size = s.size();
        if(!string_size) return vl();
        vl hd(string_size);
        hd[0] = s[0];
        for(int i = 1; i < string_size; ++i) {
            hd[i] = hd[i-1] + p[i] * s[i];
            hd[i] %= hmod;
        }
        return hd;
    }
};

Hasher<1000000007, 200005> h1;
Hasher<1000000009, 200005> h2;

struct Hashed {
    vl hd1; vl hd2;
    Hashed(const string& s) {
        hd1 = h1.hash(s); hd2 = h2.hash(s);
    }
    pair<ll, ll> get_hash(int l, int r) {
        return {(h1.reduce(hd1[r] - (l?hd1[l-1]:0)) * h1.ip[l]) % h1.mod(), 
                (h2.reduce(hd2[r] - (l?hd2[l-1]:0)) * h2.ip[l]) % h2.mod()};
    }
};
/****************************** end /strings/strings.h ******************************/