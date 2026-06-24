#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int n; cin >> n;
    
    string s; cin >> s;
    
    string t = "";
    int k = sqrtl(n);
    if (k * k != n){
        cout << "No\n";
        return;
    }
    
    for (int i = 0; i < k; i++) for (int j = 0; j < k; j++){
        if (i == 0 || j == 0 || i == k - 1 || j == k - 1) t += "1";
        else t += "0";
    }
    
  //  cout << t << "\n";
    
    if (t == s) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}