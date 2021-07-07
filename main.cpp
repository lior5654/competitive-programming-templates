#pragma once

/****************************** begin /template.h ******************************/

/***********************************************************************
 * [?] APIO 2021 Template
 * [+] Made By: Lior Yehezkely, FiveSixFiveFour
 * [~] Apples are ORZ
 * *********************************************************************/

/*** begin #define flags ***/
// #define USE_ORDERED_STATISTICS
// #define BIG_BIGINT
/*** end #define flags ***/

/*** begin includes ***/
#include <bits/stdc++.h>

#ifdef USE_ORDERED_STATISTICS
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
#endif

using namespace std;
/*** end includes ***/

/*** begin typedefs ***/
typedef long long int ll;
#ifdef BIG_BIGINT
    typedef __int128_t bigint;
#else
    typedef ll bigint;
#endif
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpi> vvpi;
typedef vector<vpl> vvpl;
typedef set<int> si;
typedef multiset<int> msi;
typedef set<ll> sl;
typedef multiset<ll> msl;
typedef long double ld;
template<class T> using func = function<T>;

#ifdef USE_ORDERED_STATISTICS
    typedef tree<
    pl,
    null_type,
    less<pl>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
#endif

/*** end typedefs ***/

/*** begin #defines ***/
#define clrcin cin.ignore(numeric_limits<streamsize>::max(),'\n');
#define GOGOGO ios::sync_with_stdio(false); cin.tie(nullptr);
#define BYEBYE return 0;

#define all(cn) (cn).begin(), (cn).end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define csz(c) ((int)c.size())
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define popcnt __builtin_popcount
#define popcntll __builtin_popcount_ll

/*** end #defines ***/

const int INFI = 1e9 + 5;
const ll INFL = 1e18 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
auto dist = uniform_int_distribution<int>(0, INFI); 
auto distll = uniform_int_distribution<ll>(0, INFL); 
int rnd() { return dist(rng); }
ll rndl() { return distll(rng); }

/****************************** end /template.h ******************************/


/****************************** begin /main.cpp ******************************/


/*** begin #define flags ***/
//#define BRUH_WHY_TESTCASES
//#define PREC 7
//#define INPUT_FILE "hi.in"
//#define OUTPUT_FILE "hi.out"
/*** end #define flags ***/


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


void solve() {
    

}











































signed main()
{
    #ifdef INPUT_FILE
        freopen(INPUT_FILE, "r", stdin);
    #endif
    #ifdef OUTPUT_FILE
        freopen(OUTPUT_FILE, "w", stdout);
    #endif
    GOGOGO
    #ifdef PREC
      cout << fixed << setprecision(PREC);
    #endif
    int t=1;
    #ifdef BRUH_WHY_TESTCASES
            cin >> t;
    #endif
    while(t--)
    {
        solve();
    }
    BYEBYE
}

/* PLEASE READ THIS
* N = 1
* GUESS A!!!!!!!
* DO SOMETHING INSTEAD OF NOTHING
*/

/****************************** end /main.cpp ******************************/





