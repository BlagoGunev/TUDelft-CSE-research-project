#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 5*1e5+5, INF = 4e18+9;
ll n, a[maxn];
void solve(){
    ll n;
    cin >> n;
    if(n == 2){
        cout << "1 1 \n1 2";
        return;
    }
    if(n == 3){
        cout << "2 1 \n2 3 \n3 1";
        return;
    }
    cout << 1 << " " << 1 << "\n";
    for(int i = 3; i < n; i++){
        cout << 1 << " " << i << "\n";
    }
    cout << n << " " << n << "\n";
    cout << n << " " << n-1 << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << "\n";
    }
    return 0;
}