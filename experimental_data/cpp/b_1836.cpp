#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

void solve(){
    ll n, k, g;
    cin >> n >> k >> g;
    ll ans = k * g - n * ((g - 1) / 2);
    if (ans <= 0){
        cout << k * g << endl;
        return;
    }
    ans = ans / g + (ans % g != 0);
    cout << (k - ans) * g << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
    return 0;
}