/*
  author : ** Kaleem Raza Syed **
*/
#include<bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#warning commment line 12 if the problem is interactive

#define pb push_back
#define endl '\n'
#define ll long long
#define ld long double
#define mset multiset
#define all(x) x.begin(), x.end()
#define pop_count(mask) __builtin_popcountll(mask)
#define SQ(x) (1ll * (x) * (x))
#define C2(x) (1ll * (x) * ((x) - 1) / 2)


void solve()
{
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i ++)
    cin >> a[i];
  ll gc = 0;
  for(int i = 0; i < n; i ++)
    gc = gcd(a[i], gc);
  for(int i = 0; i < n; i ++)
    a[i] /= gc;
  sort(a, a + n);
  if((a[0] == 1 && a[1] == 1) || (a[0] == a[n-1]))
    {
      cout << "NO\n";
      return;
    }
  cout << "YES\n";
  
}

int main()
{ 
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  
  int t = 1;
  cin >> t;
  while(t--)
    solve();
  return 0;
}