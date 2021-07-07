#pragma once
#include "../template.h"
/****************************** begin /data_structures/fenwick_tree.h ******************************/
template<class Number, int world_size> struct FenwickTree {
    Number fen[world_size+1];
    FenwickTree() {
        for(int i = 1; i <= world_size; ++i) fen[i] = 0;
    }
    void add(int pos, const Number& val) {
        for(int i = pos; i <= world_size; i += i & (-i)) {
            fen[i] += val;
        }
    }
    Number pquery(int l) {
        Number res = 0;
        for(int i = l; i > 0; i -= i & (-i)) {
            res += fen[i];
        }
        return res;
    }
    Number query(int l, int r) {
        if(l > r) return 0;
        return pquery(r) - pquery(l-1);
    }
};
template<class Number, int i_world_size, int j_world_size> struct FenwickTree2D {
    Number fen[i_world_size+1][j_world_size+1];
    FenwickTree2D() {
        for(int i = 1; i <= i_world_size; ++i) {
            for(int j = 1; j <= j_world_size; ++j) {
                fen[i][j] = 0;
            }
        }
    }
    void add(int ipos, int jpos, const Number& val) {
        for(int i = ipos; i <= i_world_size; i += i & (-i)) {
            for(int j = jpos; j <= j_world_size; j += j & (-j)) fen[i][j] += val;
        }
    }
    Number pquery(int li, int lj) {
        Number res = 0;
        for(int i = li; i > 0; i -= i & (-i)) {
            for(int j = lj; j > 0; j -= j & (-j))
                res += fen[i][j];
        }
        return res;
    }
    Number query(int li, int lj, int ri, int rj) {
        if(li > ri || lj > rj) return 0;
        return pquery(ri, rj) - pquery(ri, lj-1) - pquery(li - 1, rj) + pquery(li-1, lj-1);
    }
};
/****************************** end /data_structures/fenwick_tree.h ******************************/