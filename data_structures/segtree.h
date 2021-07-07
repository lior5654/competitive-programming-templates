#pragma once
#include "../template.h"

/****************************** begin /data_structures/segtree.h ******************************/

struct Segtree {
    int tl; int tr; int tm; ll val; Segtree* l; Segtree* r;
    Segtree(int _tl, int _tr) {
        tl=_tl; tr=_tr; tm = tl+(tr-tl)/2; l=r=nullptr; val=0;
    }
    void pull() {
        val = l->val + r->val;
    }
    void build() {  // NO INITIAL ARRAY
        if(tl == tr) {
            val = 0; 
        } else {
            l = new Segtree(tl, tm); r = new Segtree(tm+1, tr);
            l->build(); r->build();
            pull();
        }
    }
    void build(ll* x) {  // INITIAL ARRAY
        if(tl == tr) {
            val = x[tl]; 
        } else {
            l = new Segtree(tl, tm); r = new Segtree(tm+1, tr);
            l->build(x); r->build(x);
            pull();
        }
    }
    void update(int pos, ll v) {
        if(tl == tr) {
            val = v;
        } else {
            if(pos <= tm) {
                l->update(pos, v);
            } else {
                r->update(pos, v);
            }
            pull();
        }
    }
    ll query(int ql, int qr) {
        if(ql > qr || qr < tl || ql > tr) return 0;
        if(ql == tl && qr == tr) return val;
        return l->query(ql, min(tm, qr)) + r->query(max(ql,tm+1), qr);
    }
};

struct PersistentSegtree {
    int tl; int tr; int tm; ll val; PersistentSegtree* l; PersistentSegtree* r;
    PersistentSegtree(int _tl, int _tr) {
        tl=_tl; tr=_tr; tm = tl+(tr-tl)/2; l=r=nullptr; val=0;
    }
    void pull() {
        val = l->val + r->val;
    }
    void build() {  // NO INITIAL ARRAY
        if(tl == tr) {
            val = 0; 
        } else {
            l = new PersistentSegtree(tl, tm); r = new PersistentSegtree(tm+1, tr);
            l->build(); r->build();
            pull();
        }
    }
    void build(ll* x) {  // INITIAL ARRAY
        if(tl == tr) {
            val = x[tl]; 
        } else {
            l = new PersistentSegtree(tl, tm); r = new PersistentSegtree(tm+1, tr);
            l->build(x); r->build(x);
            pull();
        }
    }
    PersistentSegtree* update(int pos, ll v) {
        PersistentSegtree* curr = new PersistentSegtree(tl, tr);
        if(tl == tr) {
            curr->val = v;
        } else {
            if(pos <= tm) {
                curr->r = r;
                curr->l = l->update(pos, v);
            } else {
                curr->l = l;
                curr->r = r->update(pos, v);
            }
            pull();
        }
        return curr;
    }
    ll query(int ql, int qr) {
        if(ql > qr || qr < tl || ql > tr) return 0;
        if(ql == tl && qr == tr) return val;
        return l->query(ql, min(tm, qr)) + r->query(max(ql,tm+1), qr);
    }
};

/****************************** end /data_structures/segtree.h ******************************/