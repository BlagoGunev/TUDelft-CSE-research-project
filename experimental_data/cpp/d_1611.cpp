#include "bits/stdc++.h"
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
int root;
const int nax = 2e5;
vector<int> position(nax + 5);
vector<int> ans(nax + 5);
vector<int> b(nax + 5);
vector<int> p(nax + 5);
void clear (int n) {
  for (int i = 1; i <= n; i++) {
    ans[i] = 0;
    position[i] = 0;
    b[i] = 0;
    p[i] = 0;
  }
}
bool is_okay (int n) {
  bool flag = 1;
  for (int i = 1; i <= n; i++) {
    if (i == root) continue;
    if (position[i] < position[b[i]]) flag = 0;
  }
  if (p[1] != root) flag = 0;
  return flag;
}
void give_weight (int n) {
  for (int i = 2; i <= n; i++) {
    int node = p[i];
    int ancestor = b[node];
    ans[node] = i - position[ancestor];
    // debug(node, ancestor, sum, ans[node]);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    clear(n);
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      if (b[i] == i) {
        root = i;
        ans[i] = 0;
      }
    }
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      p[i] = x;
      position[x] = i;
    }
    if (not is_okay(n)) {
      cout << -1 << '\n';
      continue;
    }
    give_weight(n);
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}