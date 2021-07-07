#pragma once

#include "../template.h"
/****************************** begin /graphs/bipartite_matching.h ******************************/

const int maxn = 5e2 + 5; // CHANGE
const int maxm = 5e2 + 5; // CHANGE
int n; int m;

vi g[maxn];

bitset<maxn> vis = 0;
int chs[maxm]; // chs[i] - the worker assigned to job i
bool try_khun(int v) {
    if(vis[v]) return false;
    vis[v] = true;
    for(auto e : g[v]) {
        if(chs[e] == -1 || try_khun(chs[e])) {
            chs[e] = v; return true;
        }
    }
    return false;
}
int bipartite_match() {  // one based indexed
    int res = 0;
    for(int i = 1; i <= m; ++i) {
        chs[i] = -1;
    }
    for(int i = 1; i <= n; ++i) {
        vis = 0;
        if(try_khun(i)) res++;
    }
    return res;
}

/****************************** end /graphs/bipartite_matching.h ******************************/