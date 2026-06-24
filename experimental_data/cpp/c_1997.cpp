#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <numeric>
#include <cmath>
#include <map>
#include <unordered_map>
#define ll long long
#define ld long double
 
using namespace std;
 
string S;
ll M = 998244353;
bool ok;
queue <ll> Q;
ll t, n;
vector <ll> V;
priority_queue<ll> pq;
map <ll, ll> mp;
ll A[600000];
ll m, k, q, p, g, a, b, c, d, e, f, s, x, y, z, l, r, mid, mn, mx;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  t = 1;
  cin >> t;
  while (t--) {
    cin >> n >> S;
    s = 0;
    for (int i=0; i<n; i+=2) {
      if (s) {
        S[i] = ')';
        --s;
      }
      else {
        S[i] = '(';
        ++s;
      }
      if (S[i+1] == '(') ++s;
      else --s;
    }
    V.clear();
    int j = 0;
    f = 0;
    for (int i=0; i<n; ++i) {
      if (S[i] == '(') V.push_back(i);
      else {
        f += i-V[j++];
      }
    }
    cout << f << '\n';
  }
}