#include<bits/stdc++.h>
// #include"debug.cpp"
#define int long long
using namespace std;
const int N = 2e5 + 10, MOD = 1e9 + 7, inf = 1e18;
void solve()
{
    int n; cin >> n;
    cout << n % 10 + n / 10 << '\n';    
}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}