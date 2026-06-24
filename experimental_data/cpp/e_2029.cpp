#include <bits/stdc++.h>
using namespace std;
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream, ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
  os << "[ ";
	for(auto &x : v)
    os << x << ' ';
	return os << "]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator << (Ostream &os, const pair<Ts...> &p){
  return os << "{" << p.first << ", " << p.second << "}";
}
void dbg_cerr() { cerr << "\e[0m\n"; }
template<typename Head, typename... Tail> void dbg_cerr(Head H, Tail... T) { cerr << ' ' << H; dbg_cerr(T...); }
#ifdef LTF
#define DEBUG(...) cerr << "\e[1;31m[" #__VA_ARGS__ "]:", dbg_cerr(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

void Solve() {
  int N; cin >> N;
  vector<int> a(N);
  for (auto &x : a) cin >> x;

  auto SmallestOddDivisor = [&](int x) {
    int mn = x;
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        int a = x / i;
        if (i & 1) mn = min(mn, i);
        if (a & 1) mn = min(mn, a);
      }
    }
    return mn;
  };

  auto Check = [&](int st) {
    bool flag = true;
    int mn = 2 * st;
    for (auto &x : a) {
      if (x == st) continue;
      if (x < mn) return false;

      if (x & 1) {
        int d = SmallestOddDivisor(x);
        int need = x - d;
        if (need < mn) return false;
      }
    }
    return true;
  };
  for (auto &x : a) {
    if (x & 1) {
      int d = SmallestOddDivisor(x);
      if (x == d) {
        // everything must start with d
        if (Check(x)) {
          cout << x << '\n';
        } else {
          cout << -1 << '\n';
        }
        return;
      }
    }
  }

  // everything can start with 2
  cout << 2 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    Solve();
  }
  return 0;
}