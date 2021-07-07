#pragma once
#include "../template.h"

/****************************** begin /graphs/dsu.h ******************************/
template<int world_size> struct BipartiteDSU {  // 0-indexed
    int p[world_size + 1]; int rnk[world_size + 1];
    bitset<world_size + 1> o; int comps; int n;
    void init(int _n) {
        n = _n;
        comps = n;
        rep(i, n) {
            p[i] = i; rnk[i] = 0; o[i] = 0;
        }
    }
    int find(int x) {
        if(x == p[x]) {
            o[x] = 0;
            return x;
        }
        int par = find(p[x]);
        o[x] = o[x]^o[p[x]];
        return p[x] = par;
    }
    bool unify(int x, int y) {
        int X = find(x); int Y = find(y);
        if(X == Y) return false;
        comps--;
        if(rnk[X] < rnk[Y]) {
            swap(X, Y); swap(x, y);
        }
        if(rnk[X] == rnk[Y]) rnk[X]++;
        o[Y] = o[y]^o[x]^1;
        p[Y] = X;
        return true;
    }
    bool is_bad(int x, int y) {
        if(find(x) != find(y)) return false;
        if(o[x] == o[y]) return true;
        return false;
    }
};

template<int world_size> struct DSU {  // 0-indexed
    int p[world_size + 1]; int rnk[world_size + 1];
    int n;
    void init(int _n) {
        n = _n;
        rep(i, n) {
            p[i] = i; rnk[i] = 0;
        }
    }
    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    bool unify(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return false;
        if(rnk[x] < rnk[y]) swap(x, y);
        if(rnk[x] == rnk[y]) rnk[x]++;
        p[y] = x;
        return true;
    }
};
/****************************** end /graphs/dsu.h ******************************/

