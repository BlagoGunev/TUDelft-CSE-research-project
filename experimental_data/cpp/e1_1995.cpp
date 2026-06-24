#include <bits/stdc++.h>

using namespace std;

#ifdef lisie_bimbi
#else
#define endl '\n'
#endif
typedef long long ll;

#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,bmi2,fma")

#define inf 2000000010
//10^18

//#define int long long
//#define double long double

void solve1(int &n, vector<pair<int, int>> &v){
    int mx = 0;
    int mn = inf;
    for(int i = 0; i < n / 2; i++){
        int j = (i + n / 2) % n;
        int mn1 = min(v[i].first + v[i].second, v[j].first + v[j].second);
        int mx1 = max(v[i].first + v[i].second, v[j].first + v[j].second);
        swap(v[i].first, v[j].first);
        int mn2 = min(v[i].first + v[i].second, v[j].first + v[j].second);
        int mx2 = max(v[i].first + v[i].second, v[j].first + v[j].second);
        if(mn2 > mn1){
            mn = min(mn, mn2);
            mx = max(mx, mx2);
        }else{
            mn = min(mn, mn1);
            mx = max(mx, mx1);
        }
    }
    cout << mx - mn << endl;
    
}

int dp[5000][2];

int ans_(vector<int> &a, int nado){
    int mn = inf;
    int n = a.size() / 2;
    dp[0][0] = inf;
    dp[0][1] = inf;
    if(a[0] + a[1] >= nado){
        dp[0][0] = a[0] + a[1];
    }
    if(a[0] + a[2] >= nado){
        dp[0][1] = a[0] + a[2];
    }
    for(int i = 1; i < n; i++){
        dp[i][0] = inf;
        dp[i][1] = inf;
        if(a[i * 2] + a[i * 2 + 1] >= nado){
            dp[i][0] = min(dp[i][0], max(dp[i - 1][0], a[i * 2] + a[i * 2 + 1]));
        }
        if((i * 2 + 2 < 2 * n) && (a[i * 2] + a[i * 2 + 2] >= nado)){
            dp[i][1] = min(dp[i][1], max(dp[i - 1][0], a[i * 2] + a[i * 2 + 2]));
        }
        if(a[i * 2 - 1] + a[i * 2 + 1] >= nado){
            dp[i][0] = min(dp[i][0], max(dp[i - 1][1], a[i * 2 - 1] + a[i * 2 + 1]));
        }
        if((i * 2 + 2 < 2 * n) && (a[i * 2 - 1] + a[i * 2 + 2] >= nado)){
            dp[i][1] = min(dp[i][1], max(dp[i - 1][1], a[i * 2 - 1] + a[i * 2 + 2]));
        }
    }
    return dp[n - 1][0];
}

int ans(vector<int> &a, int nado){
    int mn = ans_(a, nado);
    swap(a[0], a[a.size() - 1]);
    mn = min(mn, ans_(a, nado));
    if(mn == inf){
        return mn;
    }
    return mn - nado;
}


void solve(){
    int n;
    cin >> n;
    vector<int> b(2 * n);
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        cin >> b[i * 2] >> b[i * 2 + 1];
        v.push_back({b[i * 2], b[i * 2 + 1]});
    }
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    if(n % 2 == 0){
        solve1(n, v);
        return;
    }
    vector<int> a;
    int now = 0;
    for(int i = 0; i < 2 * n; i++){
        a.push_back(b[now]);
        if(now % 2 == 0){
            now++;
        }else{
            now = (now + n) % (2 * n);
        }
    }
    vector<int> mn;
    for(int i = 0; i < n; i++){
        int ind1 = i * 2;
        int ind2 = i * 2 + 1;
        mn.push_back(a[ind1] + a[ind2]);
        mn.push_back(a[(ind1 - 1 + 2 * n) % (2 * n)] + a[ind2]);
        mn.push_back(a[ind1] + a[(ind2 + 1) % (2 * n)]);
        mn.push_back(a[(ind1 - 1 + 2 * n) % (2 * n)] + a[(ind2 + 1) % (2 * n)]);
    }
    sort(mn.begin(), mn.end());
    int aaa = inf;
    int last = -1;
    for(auto i : mn){
        if(i != last){
            aaa = min(aaa, ans(a, i));
        }
        last = i;
    }
    cout << aaa << endl;
}

signed main(){
#ifdef lisie_bimbi
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(nullptr)->sync_with_stdio(false);           
#endif
    cout << setprecision(30) << fixed;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}