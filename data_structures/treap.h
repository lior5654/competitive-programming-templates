#pragma once
#include "../template.h"

/****************************** begin /data_structures/treap.h ******************************/

namespace Treap
{

struct Node {
    ll val; int prio; Node* l; Node* r;
    int sz; ll sm; ll lazy; bool flip_needed;

    Node() {}
    Node(int _val) : val(_val), prio(rnd()), l(0), r(0), sz(1),  sm(_val), lazy(0), flip_needed(false) { }
};

void debug(Node* c) {
    if(!c) return;
    push(c);
    debug(c->l);
    cout << c->val << ' ' << c->sm << '\n';
    debug(c->r);
}

inline int size(Node* c) {
    return c ? c->sz : 0;
}

inline void pull(Node* c) {
    if(!c) return;
    c->sz = 1;
    c->sm = c->val + c->lazy * size(c);
    if(c->l) {
        c->sz += c->l->sz;
        c->sm += c->l->sm + c->l->lazy*size(c->l);
    }
    if(c->r) {
        c->sz += c->r->sz;
        c->sm += c->r->sm + c->r->lazy * size(c->r);
    }
}

inline void push(Node* c) {
    if(!c || (!c->lazy && !c->flip_needed)) return;
    c->val += c->lazy;
    if(c->l) {
        c->l->lazy += c->lazy;
    }
    if(c->r) {
        c->r->lazy += c->lazy;
    }
    c->lazy = 0;
    if(c->flip_needed) {
        swap(c->l, c->r);
        if(c->l) {c->l->flip_needed = !c->l->flip_needed; }
        if(c->r) {c->r->flip_needed = !c->r->flip_needed; }
        c->flip_needed = false;
    }
}

void split(Node* c, int left_count, Node*& l, Node*& r) {
    if(!c) { l = 0; r = 0; return; }
    push(c);
    if(left_count <= size(c->l)) {
        split(c->l, left_count, l, c->l); r = c;
    } else {
        left_count -= size(c->l) + 1;
        split(c->r, left_count, c->r, r); l = c;
    }
    pull(c);
}

void merge(Node* l, Node* r, Node*& c) {
    if(!l) { c = r; return; }
    if(!r) { c = l; return; }
    push(l); push(r);
    if(l->prio < r->prio) { // l should be on top
        merge(l->r, r, l->r); c = l;
    } else {
        merge(l, r->l, r->l); c = r;
    }
    pull(c);
}

void add(Node*& c, int ql, int qr, ll v) {  // 0 based indexed
    if(ql > qr) return;
    Node* l; Node* lr; Node*  part; Node* r;
    split(c, ql, l, lr);
    split(lr, qr - ql + 1, part, r);
    part->lazy += v;
    pull(part);
    merge(part, r, lr);
    merge(l, lr, c);
}

ll query(Node*& c, int ql, int qr) {  // o based indexed
    if(ql > qr) return 0;
    Node* l; Node* lr; Node*  part; Node* r;
    split(c, ql, l, lr);
    split(lr, qr - ql + 1, part, r);
    //Treap::debug(part);
    ll res = part->sm;
    merge(part, r, lr);
    merge(l, lr, c);
    return res;
}

void reverse(Node*& c, int ql, int qr) {  // 0 based indexed
    if(ql > qr) return;
    Node* l; Node* lr; Node*  part; Node* r;
    split(c, ql, l, lr);
    split(lr, qr - ql + 1, part, r);
    part->flip_needed = !part->flip_needed;
    pull(part);
    merge(part, r, lr);
    merge(l, lr, c);
}

};

using Node = Treap::Node; 
/****************************** end /data_structures/treap.h ******************************/