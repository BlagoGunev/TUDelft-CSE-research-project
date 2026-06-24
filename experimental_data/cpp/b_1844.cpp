#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
#define int long long
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
const int INF = 0x3f3f3f3f;

void debug(set<int> s) {
  for (int i : s) {
    cout << i << " ";
  }
  cout << endl;
}

void debug(unordered_set<int> s) {
  for (int i : s) {
    cout << i << " ";
  }
  cout << endl;
}

void debug(vector<string> s) {
  for (string i : s) {
    cout << i << " ";
  }
  cout << endl;
}

void debug(vector<pii> v) { 
  cout << "PAIR START" << endl;
  for (auto i : v) {
    cout << i.first << " " << i.second << endl;
  }
  cout << "PAIR END" << endl;
}

void debug(vector<int> v) { 
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}

void debug(map<int, int> v) { 
  cout << "PAIR START" << endl;
  for (auto i : v) {
    cout << i.first << " " << i.second << endl;
  }
  cout << "PAIR END" << endl;
}

void debug(vector<vector<int>> adj) {
  for (vector<int> i : adj) {
    for (int j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}
 
void iohelp(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

ll max(ll a, ll b) {
  return a > b ? a : b;
}

ll min(ll a, ll b) {
  return a < b ? a : b;
}

void sol() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << "1" << endl;
    return;
  }
  else if (n == 2) {
    cout << "2 1" << endl;
    return;
  }
  else if (n == 4) {
    cout << "2 4 1 3" << endl;
    return;
  }
  else if (n == 5) {
    cout << "5 2 1 4 3" << endl;
    return;
  }
  else {
    vi v(n);
    for (int i = 0; i < n; ++i) {
      v[i] = i + 1;
    }

    swap(v[0], v[n / 2]);
    if (v[0] != 2) {
      swap(v[0], v[1]);
    }
    if (v[n - 1] != 3) {
      swap(v[2], v[n - 1]);
    }

    debug(v);
  }
}
 
int32_t main() {
  fastio;
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    sol();
  }
}