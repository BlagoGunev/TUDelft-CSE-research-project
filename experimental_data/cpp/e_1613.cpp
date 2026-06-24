#pragma GCC optimize("O3")

#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define ld long double
#define f first
#define s second

using namespace std;
using namespace __gnu_pbds;

typedef tree<ll, null_type,
        less<ll>, rb_tree_tag,
        tree_order_statistics_node_update> oset;

mt19937 gen(time(0));

const ll MOD = 998244353;

int32_t main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else


#endif // LOCAL


    ll t;
    cin >> t;
    while(t--) {
      ll n, m;
      cin >> n >> m;
      char a[n][m];
      bool used[n][m];
      ll kol[n][m];
      ll now[n][m];
      vector<pair<ll,ll>> per = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
     pair<ll,ll> st;

      for(int j = 0; j < n; j++)
      for(int e = 0; e < m; e++) {
        cin >> a[j][e];
        used[j][e] = 0;
        kol[j][e] = 0;
        now[j][e] = 0;
        if(a[j][e] == 'L') st = {j, e};
      }

      for(int  i = 0; i < n; i++)
      for(int j = 0; j < m; j++) {
        if(a[i][j] == '.') {
            for(auto to: per) {
                ll x = i + to.f, y = j + to.s;
                if(x < 0 || y < 0 || x >= n || y >= m) continue;
                if(a[x][y] != '#') kol[i][j]++;
            }
        }
      }
      queue<pair<ll,ll>> q;
      q.push(st);
      used[st.f][st.s] = 1;
      while(q.size()) {
        ll i = q.front().f, j = q.front().s;
        if(a[i][j] != 'L') a[i][j] = '+';
        q.pop();
            for(auto to: per) {
                ll x = i + to.f, y = j + to.s;
                if(x < 0 || y < 0 || x >= n || y >= m) continue;
                if(a[x][y] != '#') {
                        now[x][y]++;
                        if(!used[x][y] && abs(now[x][y] - kol[x][y]) <= 1) q.push({x, y}), used[x][y] = 1;
                }
            }
      }
      for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cout << a[i][j];
      } cout << '\n';
    }


    }
}