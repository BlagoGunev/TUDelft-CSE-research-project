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
const double PI = 3.141592653589793;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll T;
  cin >> T;
  for (ll testcase = 0; testcase < T; ++testcase) {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
      cin >> A.at(i);
    }
    sort(rng(A));
    ll now = X;
    ll small = 0;
    for (ll i = 0; i < N; ++i) {
      if (A.at(i) <= now + i) {
        small += 1;
      }
      else {
        break;
      }
    }
    if (Y - X <= small) {
      cout << Y - X << "\n";
      continue;
    }
    else if (small <= N - small) {
      cout << -1 << "\n";
      continue;
    }
    ll ans = 0;
    for (ll i = small; i < N; ++i) {
      if (A.at(i) >= Y) {
        break;
      }
      ll itr_time = max(0ll, (A.at(i) - now - small + (small - (N - small)) - 1) / (small - (N - small)));
      ans += N * itr_time;
      now += itr_time * (small - (N - small));
      small += 1;
      // cout << "itr" << itr_time << ' ' << A.at(i) << ' ' << now << "\n";
    }
    ll itr_time = max(0ll, (Y - now - small + (small - (N - small)) - 1) / (small - (N - small)));
    // cout << "itr" << itr_time << ' ' << now << "\n";

    ans += N * itr_time;
    now += itr_time * (small - (N - small));
    ans += Y - now;
    cout << ans << "\n";
  }
}