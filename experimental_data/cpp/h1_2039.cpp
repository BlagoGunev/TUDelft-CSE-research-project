#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ll long long
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define debug(x) [](decltype(x) _x) {cerr << #x << " = " << _x << endl; return _x;}(x)
using pii = pair<int, int>;

// const int inf = 1 << 30;
const ll inf = 1ll << 60;

const int MOD = 1e9 + 7;

template <class T, class U>
ostream& operator<<(ostream& out, pair<T, U> p) {
  return out << "(" << p.f << ", " << p.s << ")";
}
template <class T, class _ = decltype(begin(declval<T>()))>
enable_if_t<!is_same_v<T, string>, ostream&> operator<<(ostream& out, T a) {
  string dlm = "";
  out << "{";
  for(auto i : a) {
    out << dlm << i;
    dlm = ", ";
  }
  return out << "}";
}

struct segtree {
  vector<int> t;
  int n = 1;
  segtree(int s) {
    while(n < s) n *= 2;
    t.resize(n * 2);
  }
  void update(int l, int r, int v) {
    for(l += n, r += n; l < r; l /= 2, r /= 2) {
      if(l & 1) t[l++] += v;
      if(r & 1) t[--r] += v;
    }
  }
  int query(int i) {
    int res = 0;
    for(i += n; i > 0; i /= 2) res += t[i];
    return res;
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<bool> prime(4e5 + 5, true);
  vector<int> d(4e5 + 5);
  prime[0] = prime[1] = false;
  for(int i = 2; i < prime.size(); i++) {
    if(prime[i]) {
      d[i] = i;
      for(int j = i * 2; j < prime.size(); j += i) {
        if(prime[j]) d[j] = i;
        prime[j] = false;
      }
    }
  }
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    deque<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<string> ans;
    if(n == 2) {
      if(a[0] > a[1]) {
        cout << 1 << endl;
        cout << "RD" << endl;
      } else {
        cout << 0 << endl;
      }
      continue;
    }
    int head = 0;
    for(int _ = 0; _ < n * 2; _++) {
      ans.push_back("R");
      for(int i = 1; i < n - 1; i += 2) {
        if(i + 1 != head && a[i] > a[i + 1]) {
          ans.back() += "RDDR";
          swap(a[i], a[i + 1]);
        } else {
          ans.back() += "DRDR";
        }
      }
      ans.back() += "D";
      while(ans.back().size() > n * 2 - 2) {
        ans.back().pop_back();
      }
      a.push_back(a[0]);
      a.pop_front();
      head = (head + n - 1) % n;
      // debug(a);
      // debug(head);
    }
    cout << ans.size() << endl;
    for(auto i : ans) {
      cout << i << endl;
    }
    // debug(a);
  }
}