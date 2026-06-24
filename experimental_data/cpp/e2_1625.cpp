#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



#define ld long double

#define ull unsigned long long

#define ll long long

#define pb push_back

#define ppb pop_back

#define eb emplace_back

#define pii pair<int, int>

#define pll pair<ll, ll>

#define pld pair<ld, ld>

#define all(x) x.begin(), x.end()

#define rall(x) x.rbegin(), x.rend()

#define sz(x) ((int)(x).size())

#define fast_io cin.tie(0), ios_base::sync_with_stdio(0)



//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2,fma,bmi,bmi2,lzcnt,popcnt")

//#pragma GCC optimize("Ofast")

//#pragma GCC optimize("O3")



using namespace std;

using namespace __gnu_pbds;

typedef tree<pll, null_type, less<>, rb_tree_tag,

    tree_order_statistics_node_update> ordered_set_of_pairs;



ld eps = 1. / 1e9;

ll inf_ll = 1e18 + 100, mod1 = 1e9 + 7, mod2 = 998244353;

ll mersen_mod = 2305843009213693951;

mt19937 gen32(time(nullptr));



ll sqr(ll a) { return a * a; }

ll gcd(ll a, ll b) { return !a ? b : gcd(b % a, a); }

ll add(ll a, ll b, ll mod) {

  a += b;

  if (a >= mod) a -= mod;

  return a;

}

ll sub(ll a, ll b, ll mod) {

  a -= b;

  if (a < 0) a += mod;

  return a;

}

ll binpow(ll a, ll b, ll mod) {

  return b ? (b % 2 ? (a * (sqr(binpow(a, b / 2, mod)) % mod)) % mod :

              sqr(binpow(a, b / 2, mod)) % mod) : 1;

}

ll binmult(ll a, ll b, ll mod) {

  return b ? (b % 2 ? (2 * binmult(a, b / 2, mod) + a) % mod :

              (2 * binmult(a, b / 2, mod)) % mod) : 0;

}



/// Code here

string str;

int pos_in_eul[300010], parent[300010], pos;

ll eul[300010], seg[1200050];

pii borders[300010];

ordered_set_of_pairs child_borders[300010];



void build() {

  stack<int> ps;



  for (int i = 0; i < str.size(); i++) {

    if (str[i] == '(') ps.push(i);

    else if (str[i] == ')') {

      if (ps.empty()) str[i] = '.';

      else ps.pop();

    }

  }

  while (!ps.empty()) {

    str[ps.top()] = '.';

    ps.pop();

  }



  pos = 1;

  for (int i = 0; i < str.size(); i++) {

    parent[i] = -1;

    if (str[i] == '(') {

      pos_in_eul[i] = pos++;

      ps.push(i);

    } else if (str[i] == ')') {

      int left_pos = ps.top();

      int eul_left = pos_in_eul[left_pos];

      borders[eul_left] = borders[pos] = {left_pos, i};

      pos_in_eul[i] = pos++;



      int cur_pos = eul_left + 1;

      while (cur_pos < pos - 1) {

        child_borders[eul_left].insert(borders[cur_pos]);

        parent[cur_pos] = eul_left;

        cur_pos = pos_in_eul[borders[cur_pos].second] + 1;

      }



      ll sz = sz(child_borders[eul_left]);

      eul[eul_left] = sz * (sz - 1) / 2 + 1;

      ps.pop();

    }

  }



  int cur_pos = 1;

  while (cur_pos < pos) {

    child_borders[0].insert(borders[cur_pos]);

    parent[cur_pos] = 0;

    cur_pos = pos_in_eul[borders[cur_pos].second] + 1;

  }

  ll sz = sz(child_borders[0]);

  eul[0] = sz * (sz - 1) / 2;

}



void build_seg(int l, int r, int v) {

  if (l == r) {

    seg[v] = eul[l];

    return;

  }

  int m = (l + r) / 2;

  build_seg(l, m, 2 * v);

  build_seg(m + 1, r, 2 * v + 1);

  seg[v] = seg[2 * v] + seg[2 * v + 1];

}



void update(int l, int r, int v, int cpos) {

  if (l == r) {

    seg[v] = eul[l];

    return;

  }

  int m = (l + r) / 2;

  if (cpos <= m) update(l, m, 2 * v, cpos);

  else update(m + 1, r, 2 * v + 1, cpos);

  seg[v] = seg[2 * v] + seg[2 * v + 1];

}



ll get(int l, int r, int tl, int tr, int v) {

  if (l == tl && r == tr) return seg[v];

  int m = (l + r) / 2;

  if (tr <= m) return get(l, m, tl, tr, 2 * v);

  else if (tl > m) return get(m + 1, r, tl, tr, 2 * v + 1);

  else return get(l, m, tl, m, 2 * v) + get(m + 1, r, m + 1, tr, 2 * v + 1);

}



int main() {

  fast_io;

  int n, q, t, l, r;

  cin >> n >> q >> str;

  build();

  build_seg(0, pos - 1, 1);

  while (q--) {

    cin >> t >> l >> r;

    l--, r--;

    int left = pos_in_eul[l];

    int pnt = parent[left];

    if (t == 1) {

      eul[left] = 0;

      update(0, pos - 1, 1, left);

      eul[pnt] -= sz(child_borders[pnt]) - 1;

      update(0, pos - 1, 1, pnt);

      child_borders[pnt].erase(borders[left]);

    } else {

      ll kl = (ll)child_borders[pnt].order_of_key(borders[pos_in_eul[r]]) - (ll)child_borders[pnt].order_of_key(borders[left]) + 1;

      cout << get(0, pos - 1, left, pos_in_eul[r], 1) + kl * (kl - 1) / 2 << '\n';

    }

  }

  //cerr << '\n' << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << '\n';

  return 0;

}