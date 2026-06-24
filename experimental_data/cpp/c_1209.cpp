//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int INF = 1e6, MAXN = 1e6 + 7;
const int mod = 998244353;
ll gcd(ll a, ll b) {
  return (b == 0) ? a : gcd(b, a%b);
}


int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  //freopen("network.in", "r", stdin);
  //freopen("network.out", "w", stdout);


  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string d; cin >> d;
    string col = d;
    char mi = d[n - 1];
    char pr = '9';
    bool fl = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (d[i] < mi) mi = d[i];
      if (d[i] > mi) {
        col[i] = '2';
        if (d[i] > pr)
          fl = 1;
        else
          pr = d[i];
      }
      else
        col[i] = '1';
    }
    char last = d[0];
    char ma = pr;
    for (int i = 0; i < n; ++i) {
      if (d[i] >= ma) {
        col[i] = '2';
        ma = d[i];
      }
      if (col[i] == '1')
        last = d[i];
    }
    if (pr < last)
      fl = 1;
    if (fl)
      cout << '-' << endl;
    else {
      cout << col << endl;
    }
  }

  return 0;
}