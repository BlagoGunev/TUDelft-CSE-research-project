#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
constexpr int N = int(4e2) + 5;
constexpr int inf = 0x7f7f7f7f;
constexpr int MOD = int(1e9) + 7;

void solve(){
    int n, m, k = 0, l;
    cin >> n >> m;

    vector<int> v;
    for(int i = 1; i <= n; i++){
        if(k + (i - 1 >> 1) <= m){
            k += i - 1 >> 1;
            v.push_back(i);
            l = v.back() + 1;
        }
        else if(k < m){
            v.push_back(2 * (i - m + k) - 1);
            k = m;
            l = v.back() + 1;
        }
        else v.push_back(int(1e9) - l * (n - i));
    }
    if(k != m) cout << -1;
    else for(auto& i : v) cout << i << ' ';
}
int main() {
    ios::sync_with_stdio(0);    
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}