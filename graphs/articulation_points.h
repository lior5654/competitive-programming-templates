#pragma once

#include "../template.h"
/****************************** begin /graphs/articulation_points.h ******************************/
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
 
vi g[maxn]; int n, m;
bitset<maxn> vis = 0;
int down[maxn];
int d[maxn];
int low[maxn];
void get_articulations(int c, int par=0, int dd=0, vi& articulation_points) {
    vis[c] = 1;
    d[c] = dd;
    low[c] = d[c];
    int odeg = 0;
    bool good = false;
    for(auto e : g[c]) {
        if(e == par) continue;
        if(!vis[e]) {
            get_articulations(e, c, dd+1);
            odeg++;
            if(low[e] >= d[c]) {
                good = true;
            }
            low[c] = min(low[c], low[e]);
        } else {
            low[c] = min(low[c], d[e]);
        }
    }
    if((c != 1 && good) || (c == 1 && odeg >= 2)) articulation_points.pb(c);
}
/****************************** end /graphs/articulation_points.h ******************************/