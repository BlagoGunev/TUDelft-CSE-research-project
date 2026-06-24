/*

.o.                oooo

.888.               `888

.8"888.      .oooo.o  888 .oo.   oooo  oooo

.8' `888.    d88(      888P"Y88b  `888  `888

.88ooo8888.   `"Y88b.   888   888   888   888

.8'     `888.      )88b  888   888   888   888

o88o     o8888o 8""888P' o888o o888o  `V88V"V8P'



*/



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

ll LCM(ll a, ll b) {return (a / gcd(a, b)) * b;}

vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

ull power(ull a, ull b) {ull ans = 1; while (b) {if (b & 1) ans = (ans * a) % mod; b >>= 1; a = (a * a) % mod;} return ans;}



/*----------------------------------x x x---------------------------------*/



void dimak_laga{

  ll n, k;

  cin >> n >> k;



  std::vector<vector<ll>> v(n);

  ll root, nastiya;

  cin >> root >> nastiya;

  root--, nastiya--;



  std::vector<bool> inc(n, 0), exc(n, 0);

  for (ll i = 0; i < k; i++) {

    ll x; cin >> x;

    exc[x - 1] = 1;

  }



  inc[nastiya] = 1, inc[root] = 1;;

  for (ll i = 0; i < n - 1; i++) {

    ll a, b;

    cin >> a >> b;

    v[a - 1].push_back(b - 1);

    v[b - 1].push_back(a - 1);

  }



  function<void(ll, ll)> dfs = [&](ll x, ll p) {

    for (auto &i : v[x]) {

      if (i == p) continue;

      dfs(i, x);

      if (inc[i]) inc[x] = 1;

      else if (exc[i]) exc[x] = 1;

    }

  };



  dfs(root, -1);



  ll ans = 0;

  for (ll i = 0; i < n; i++) {

    if (i == root) continue;



    if (inc[i]) ans ++;// optimal as finally we have to go to nastiya

    else if (exc[i]) ans += 2;

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