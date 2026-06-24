#include <bits/stdc++.h>
// #include <atcoder/modint>
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define INF 2000000000000000000
#define ll long long
#define ull unsigned long long
#define ld long double
#define pll pair<ll, ll>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const double PI = 3.141592653589793238462643383279;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll T;
  cin >> T;
  for (ll testcae = 0; testcae < T; ++testcae) {
    string S;
    cin >> S;
    if (S.at(0) == S.at(S.size() - 1)) {
      cout << S.at(0) << " ";
      for (ll i = 1; i < S.size() - 1; ++i) {
        cout << S.at(i);
      }
      cout << " " << S.at(S.size() - 1) << "\n";
    }
    else {
      ll f = -1;
      for (ll i = 1; i < S.size() - 1; ++i) {
        if (S.at(i) == 'a') {
          f = i;
        }
      }
      if (f == -1) {
        cout << S.at(0) << " ";
        for (ll i = 1; i < S.size() - 1; ++i) {
          cout << S.at(i);
        }
        cout << " " << S.at(S.size() - 1) << "\n";
      }
      else {
        for (ll i = 0; i < f; ++i) {
          cout << S.at(i);
        }
        cout << " " << S.at(f) << ' ';
        for (ll i = f + 1; i < S.size(); ++i) {
          cout << S.at(i);
        }
        cout << "\n";
      }
    }
  }
}