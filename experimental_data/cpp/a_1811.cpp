# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

# define int long long
# define For(i, n) for(int i=0; i<n; i++)
# define Fori(i, n) for(int i=1; i<=n; i++)
# define Each(x, v) for(auto x : v)

int solve(){
  int n, d; cin >> n >> d;
  bool ok = true;
  for(int i=0; i<n; i++){
    char x; cin >> x;

    int res = x-'0';
    if(d > res && ok){
      cout << d;
      ok = false;
    }
    cout << res;
  }
  if(ok) cout << d;
  cout << endl;
  return 0;
}

signed main(){
  ios_base :: sync_with_stdio(false);
  int t; cin >> t;
  while(t--){
    int ans = solve();
  }
}