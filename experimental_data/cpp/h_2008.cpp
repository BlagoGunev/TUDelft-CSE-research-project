#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(arr) arr.begin(), arr.end()
#define multitest() int _gorilla_silverback; cin >> _gorilla_silverback; while (_gorilla_silverback --> 0)
#define ls(id) (id << 1 | 1)
#define rs(id) ((id << 1) + 2)
#define sqr(x) ((x) * (x))
#define dlg(x) (31 - __builtin_clz(x))
#define ulg(x) (32 - __builtin_clz(x))
#define inf 1e9

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MXN = 2e6 + 5;
const int mod = 1e9 + 7;
const int B = 1316;

int pre[MXN], f[MXN];

void solve()
{
  int n, q;
  cin >> n >> q;
  int a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  for (int i = 0; i <= n; i++){
    pre[i] = 0;
  }
  for (int i = 0; i < n; i++){
    pre[a[i]]++;
  }
  for (int i = 1; i <= n; i++){
    pre[i] += pre[i - 1];
  }
  vector<int> ans(n + 1, -1);
  for (int i = 1; i <= min(B, n); i++){
    for (int j = 0; j < i; j++){
      f[j] = 0;
    }
    for (int j = 0; j < n; j++){
      f[a[j] % i]++;
    }
    int cur = 0;
    for (int j = 0; j < i; j++){
      cur += f[j];
      if (cur >= n / 2 + 1){
        ans[i] = j;
        break;
      }
    }
  }
  while (q--)
  {
    int x;
    cin >> x;
    if (ans[x] != -1){
      cout << ans[x] << ' ';
      continue;
    }
    int l = 0, r = x - 1;
    while (l < r)
    {
      int mid = (l + r) >> 1;
      int cnt = 0;
      for (int k = 0; k * x <= n; k++){
        cnt += pre[min(n, k * x + mid)] - (k ? pre[k * x - 1] : 0);
      }
      if (cnt >= n / 2 + 1){
        r = mid;
      }
      else{
        l = mid + 1;
      }
    }
    cout << (ans[x] = l) << ' ';
  }
  cout << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int T;
  cin >> T;
  while (T--)
  {
    solve();
  }
}