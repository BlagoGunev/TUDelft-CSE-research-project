#include <bits/stdc++.h>
using namespace std;

// For Policy Based DS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// ---------------------------------------
#define endl            "\n"
#define ff              first
#define ss              second
#define int             long long
#define pb              emplace_back
#define mp              make_pair
#define pll             pair<int,int>
#define vll             vector<int>
#define vpll            vector<pair<int,int>>
#define all(c)          (c).begin(), (c).end()
#define bs              binary_search
#define pqb             priority_queue<int>
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define mem(arr,x)      memset(arr,x,sizeof(arr))
#define pi              3.14159265358979323846
#define inf             2000000000000000000
#define ps(x,y)         fixed<<setprecision(y)<<x
#define test(x)         int x; cin>>x;while(x--)

template<class A> void read(vector<A>& v);
template<class A, size_t S> void read(array<A, S>& a);
template<class T> void read(T& x) {
  cin >> x;
}
void read(double& d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double& d) {
  string t;
  read(t);
  d = stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template<class A> void read(vector<A>& x) {
  for (auto &a : x)
    read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
  for (auto &a : x)
    read(a);
}
void c_p_c()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
/***************************CODE BEGINS**************************************/
const int N = 1e5;
bitset <N> cal;
vector<int>prime;
void sieve()
{
  cal.set();
  cal[0] = cal[1] = 0;
  for (int i = 2; i < N; i++)
  {
    if (cal[i] == 1)
    {
      prime.pb(i);
      for (int j = i * i; j < N; j += i)
        cal[j] = 0;
    }
  }
}
map<int, int> divisor(int num)
{
  map<int, int> m;
  int i = 0;
  int p = prime[i++];
  while (p * p <= num)
  {
    while (num % p == 0)
    {
      m[p]++;
      num /= p;
    }
    p = prime[i++];
  }
  if (num != 1)
    m[num]++;
  return m;
}
void solve ()
{
  int n;
  read(n);
  map<int, int> mp = divisor(n);
  int ans = -1, mx = 1;
  for (auto it : mp) {
    int pp = it.ff, q = it.ss;
    if (q > mx) {
      mx = q;
      ans = pp;
    }
  }
  if (ans == -1)
    cout << "1" << endl << n << endl;
  else {
    cout << mx << endl;
    for (int i = 1; i < mx; i++) {
      cout << ans << " ";
      n /= ans;
    }
    cout << n << endl;
  }
}
int32_t main()
{
  c_p_c();
  sieve();
  test(x)
  solve();
  return 0;
}