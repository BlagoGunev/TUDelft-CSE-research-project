#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;


int n, k;
int a[MAXN];

void solve(){
    cin >> n >> k;
    map<int,vector<int>> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        m[a[i]%k].push_back(i);
    }
    for(auto &k : m){
        if(k.second.size()==1){
            cout << "YES\n";
            cout << k.second[0]+1 << '\n';
            return;
        }
    }
    cout << "NO\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int32_t qqq=1;
    cin >> qqq;
    while(qqq--)solve();
    return 0;
}