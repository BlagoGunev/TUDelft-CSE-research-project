/// Msaa el 5ra
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define popCnt(x) (__builtin_popcountll(x))
#define int ll

using ll = long long;
using ii = pair<int, int>;
using ull = unsigned long long;

const int N = 2e5 + 5, A = 26, LG = 19, MOD = 1e9 + 7;
const long double PI = acos(-1);
const long double EPS = 1e-7;
int p[305];
int sz[305];
int n, m, c;
vector<int> adj[305], bridge_tree[305];
int get(int i) { return i == p[i] ? i : p[i] = get(p[i]); }
vector<int> vec;

int dfsn[N], low[N], cost[N], timer, cnt, comp_id[N];
stack<int> st;

void dfs(int node, int par) {
  dfsn[node] = low[node] = ++timer;
  st.push(node);
  for (auto i : adj[node]) {
    if (i == par) continue;
    if (dfsn[i] == 0) {
      dfs(i, node);
      low[node] = min(low[node], low[i]);
    }
    else low[node] = min(low[node], dfsn[i]);
  }
  if (dfsn[node] == low[node]) {
    cnt++;
    cost[cnt] = 0;
    while (1) {
      cost[cnt] += 1;
      int cur = st.top();
      st.pop();
      comp_id[cur] = cnt;
      if (cur == node) break;
    }
  }
}
void dfs1(int node, int par) {
  for (auto v : bridge_tree[node])if (v != par) {
    dfs1(v, node);
    cost[node] += cost[v];
  }
}
void doWork() {
  timer = 0;
  cin >> n >> m >> c;
  vector<vector<int>> go(n + 1);
  f(i, 1, n + 1)adj[i].clear(), bridge_tree[i].clear(), p[i] = i, sz[i] = 1, dfsn[i] = low[i] = 0;
  f(i, 0, m) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
    if (get(u) != get(v)) {
      sz[get(v)] += sz[get(u)];
      p[get(u)] = get(v);
    }
  }
  vec.clear();
  f(i, 1, n + 1) {
    if (i == get(i))vec.push_back(i);
    go[get(i)].push_back(i);
  }
  vector<int> dp(305, -1);
  dp[0] = 0;
  for (int i = 0; i < vec.size(); i++) {
    int s = sz[vec[i]];
    for (int j = n; j >= s; --j) {
      if (dp[j - s] != -1) {
        dp[j] = i;
      }
    }
  }
  int ans = 0;
  vector<bool> inSet(vec.size());
  f(i, 0, n / 2 + 1)  if (dp[i] != -1)ans = i;
  int cur = ans, base = ans;
  while (cur)
  {
    inSet[dp[cur]] = 1;
    cur -= sz[vec[dp[cur]]];
  }
  ans = abs((n - base) - base);
  f(i, 0, vec.size()) {
    cnt = 0;
    dfs(vec[i], vec[i]);
    if (cnt != 1) { ///I can split even more
      f(j, 1, cnt + 1)bridge_tree[j].clear();
      for (auto x : go[vec[i]]) {
        for (auto j : adj[x]) {
          if (comp_id[x] != comp_id[j]) {
            bridge_tree[comp_id[x]].push_back(comp_id[j]);
          }
        }
      }
      dfs1(1, 1);
      for (int j = 1; j <= cnt; j++) {
        int x = base, y = n - base;
        if (inSet[i]) {  ///in base
          x -= cost[1];
        }
        else {
          y -= cost[1];
        }
        ans = min(ans, abs((x + cost[j]) - (y + cost[1] - cost[j])));
        ans = min(ans, abs((y + cost[j]) - (x + cost[1] - cost[j])));
      }
    }
  }

  ///x - y = ans
  ///x + y = n
  ///2 * x = ans + n
  if (ans == n) {
    cout << "-1\n";
    return;
  }
  int x = (ans + n) / 2;
  int y = n - x;
  cout << x * x + y * y + c * (vec.size() - 1) << '\n';


}

int32_t main() {
#ifdef LOCAL
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#else
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
#endif
  int t = 1;
  cin >> t;
  while (t--) {
    doWork();
  }
}