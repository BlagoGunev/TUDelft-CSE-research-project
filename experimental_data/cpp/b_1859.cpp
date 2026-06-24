#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double
#define fr first
#define fi first
#define sc second
#define se second
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define tofu ios::sync_with_stdio(0);cin.tie(0);

void db(){cout << endl;}
template <typename T, typename ...U> void db(T a, U ...b) {cout << a << ' ', db(b...);}

void solve(){
    int n;
    cin >> n;
    vector<int> a[n];

    int mn = INT_MAX, sum = 0;
    for(int i = 0; i < n; ++i){
        int m; cin >> m;
        while(m--){
            int x; cin >> x;
            a[i].push_back(x);
        }
        sort(all(a[i]));
        mn = min(mn, a[i][0]);
        sum += a[i][1];
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans = max(ans, mn + sum - a[i][1]);
    }
    db(ans);
}

signed main(){
    tofu;

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}