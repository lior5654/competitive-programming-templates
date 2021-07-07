#pragma once
#include "../template.h"

/****************************** begin /geometry/geometry.h ******************************/

#define EPS 1e-9

template<class T> class pt {
public:
    T x; T y;
    pt() : x(0), y(0) {}
    pt(T _x, T _y) : x(_x), y(_y) {}
    pt& operator +=(const pt& other) { x += other.x; y += other.y; return *this; }
    pt operator +(const pt& other) const { return pt(x + other.x, y + other.y); }
    pt& operator -=(const pt& other) { x -= other.x; y -= other.y; return *this; }
    pt operator -(const pt& other) const { return pt(x - other.x, y - other.y); }
    pt& operator *=(T c) { x *= c; y *= c; return *this; }
    pt operator * (T c) const { return pt(x * c, y * c); }
    pt& operator /= (T c) { assert(abs(c) > EPS); x /= c; y /= c; return *this; }
    pt operator / (T c) const { assert(abs(c) > EPS); return pt(x / c, y / c); }
    T operator * (const pt& other ) { return x * other.x + y * other.y; }
    T operator % (const pt& other) { return x * other.y - y * other.x; }
};
 
using ptl = pt<ll>;
using ptd = pt<ld>;

template<class T> ll sgn(T x) {
    if(x > EPS) return 1;
    else if(x < -EPS) return -1;
    return 0;
}
 
template<class T> ll orn(const pt<T>& o, const pt<T>& a, const pt<T>& b) {
    return sgn((a - o) % (b - o));
}
 
template<class T> bool intersect1d(T l1, T r1, T l2, T r2) {
    if(r1 < l1) swap(l1, r1);
    if(r2 < l2) swap(l2, r2);
    return max(l1, l2) <= min(r1, r2) + ((T)EPS);
}
 
template<class T> bool intersect(const pt<T>& a, const pt<T>& b, const pt<T>& c, const pt<T>& d) {
    return orn(c, d, a) * orn(c, d, b) <= 0 && orn(a, b, c) * orn(a, b, d) <= 0 && intersect1d(a.x, b.x, c.x, d.x) && intersect1d(a.y, b.y, c.y, d.y); 
}

vector<ptl> convex_hull(vector<ptl> pts) {
    const int sz = pts.size();
    sort(all(pts), [&](const ptl& x, const ptl& y){
        if(x.x != y.x) return x.x < y.x;
        return x.y < y.y;
    });
    if(sz <= 3) return pts;
    vector<ptl> h(2*sz); int k = 0;
    for(int i = 0; i < sz; ++i) {
        while(k >= 2 && (h[k-1] - h[k-2]) % (pts[i] - h[k-1]) <= 0) k--;
        h[k++] = pts[i];  
    }
    for(int i = sz-2, t = k + 1; i >= 0; --i) {
        while(k >= t && (h[k-1] - h[k-2]) % (pts[i] - h[k-1]) <= 0) k--;
        h[k++] = pts[i];
    }
    h.resize(k-1);
    return h;
}
/****************************** end /geometry/geometry.h ******************************/