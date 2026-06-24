// <!---- Code By: •••••.. Ashu Mittal ..••••• ---->

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;



template<class T>

using minheap = priority_queue<T, vector<T>, greater<T> >;



template<class T>

using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;



template<class key, class value, class cmp = std::less<key>>

using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;



#define ff first

#define ss second

#define ll long long

#define all(s) (s).begin(),(s).end()

#define pb push_back

#define pob pop_back

#define input(a) for(auto &x:(a)) cin>>x;

#define iendl "\n", cout<<flush

#define chal_pncho ios::sync_with_stdio(0); cin.tie(0);

#define dimak_laga solve()

#define mod 1000000007

typedef unsigned long long ull;

typedef long double lld;



#ifndef ONLINE_JUDGE

#include "dbg.cpp"

#else

#define dbg(x)

#endif



//random generator

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rnd(ll a, ll b) {if (a > b) {return -1;} return a + (ll)rng() % (b - a + 1);}



// help

vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

ull power(ull a, ull b) {ull ans = 1; while (b) {if (b & 1) ans = (ans * a) % mod; b >>= 1; a = (a * a) % mod;} return ans;}



/*----------------------------------x x x---------------------------------*/



class segTree {



public:



    vector<ll> tree, v;

    segTree(vector<ll> &vec) { v = vec; ll n = v.size(); tree.resize(4 * n); build(1, 0, n - 1); }

    void update(ll i, ll val) { UP_DATE(i, val, 1, 0, v.size() - 1); }

    ll query(ll i1, ll i2) { return QUerY(1, i1, i2, 0, v.size() - 1); }

    ll fun(ll v1, ll v2) { return v1 + v2; }



// <!------------------------------ BUILD ----------------------------------!>

    void build( ll cur, ll l, ll r ) {

        if (l == r) {

            tree[cur] = v[l];

            return;

        }

        ll mid = (l + r) / 2;

        build(2 * cur, l, mid);

        build( 2 * cur + 1, mid + 1, r);



        tree[cur] = fun(tree[2 * cur], tree[2 * cur + 1]);

    }

// <!------------------------------ UPDATE -----------------------------------!>

    void UP_DATE(ll i, ll val, ll cur, ll l, ll r) {

        if (r == l && i == l) {

            tree[cur] = val;

            return;

        }



        ll mid = (l + r) / 2;

        if (i <= mid) UP_DATE(i, val, 2 * cur, l, mid);

        else UP_DATE(i, val, 2 * cur + 1, mid + 1, r);



        tree[cur] = fun(tree[2 * cur], tree[2 * cur + 1]);

    }

// <!--------------------------------- QUERY -----------------------------------!>

    ll QUerY(ll cur, ll i1, ll i2, ll l, ll r) {

        if (l >= i1 && r <= i2) return tree[cur];

        else if (l > i2 || r < i1) return 0ll;



        ll mid = (l + r) / 2;

        ll val1 = QUerY(2 * cur, i1, i2, l, mid), val2 = QUerY(2 * cur + 1, i1, i2, mid + 1, r);



        return fun(val2, val1);

    }

};



void dimak_laga{

    ll n;

    cin >> n;



    std::vector<ll> v(n);

    input(v);



    std::vector<ll> pre(n + 1, 0);

    for (ll i = 0; i < n; i++) {

        for (ll j = i + 1; j < n; j++) {

            if (v[i] > v[j]) pre[i + 1]++;

        }

    }



    dbg(pre)



    ll ans = 0;

    for (ll i = 0; i < n; i++) {

        for (ll j = 0; j < i ; j++) {

            if (v[j] > v[i]) pre[j + 1]--;

        }

        std::vector<ll> pre1(n + 1, 0);

        for (ll k = 0; k < n; k++) pre1[k + 1] = pre[k + 1] + pre1[k];

        for (ll j = 0; j < i; j++) if (v[j] < v[i]) ans += pre1[i] - pre1[j + 1];

    }

    cout << ans << endl;

}



/*



*/



int main()

{

    chal_pncho



#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif



    ll TT ;

    cin >> TT;

    //TT=1;

    for (ll TEST = 0; TEST < TT; TEST++) {

        // cout<<"Case #"<<TEST<<": ";

        dimak_laga;

    }

}