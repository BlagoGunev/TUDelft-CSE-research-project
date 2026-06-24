#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int> v;
vector<vector<vector<int>>> pref, sum;

int stupid(int s, int d, int k){
    int ans = 0;
    for(int i = 1; i <= k; i++){
        ans += v[s + (i - 1) * d] * i;
    }
    return ans;
}

void build(){
    for(int i = 1; i <= 100; i++){
        for(int j = 0; j < i; j++){
            sum[i].push_back(vector<int>());
            pref[i].push_back(vector<int>());
            sum[i][j].push_back(0);
            pref[i][j].push_back(0);
            int tj = j;
            int ind = 1;
            while(tj < n){
                int nsum = sum[i][j].back();
                int npref = pref[i][j].back();
                nsum += ind * v[tj];
                npref += v[tj];
                sum[i][j].push_back(nsum);
                pref[i][j].push_back(npref);
                tj += i;
                ind++;
            }
        }
    }
}

void solve(){
    int q;
    cin>>n>>q;
    v = vector<int>(n);
    for(int i = 0; i < n; i++) {
        //v[i] = rand();
        cin >> v[i];
    }
    bool isBuild = (n >= 1000);
    if(isBuild){
        pref = sum = vector<vector<vector<int>>>(101);
        build();
    }
    while(q--){
        int s, d, k; cin>>s>>d>>k;
        s--;
        if(!isBuild || d >= 101)
            cout<<stupid(s, d, k)<<' ';
        else {
            int st = s % d;
            int l = s / d;
            int r = l + k;
            int ans = sum[d][st][r] - sum[d][st][l];
            ans -= (pref[d][st][r] - pref[d][st][l]) * l;
            cout << ans << ' ';
        }
    }
    cout<<'\n';
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--)
        solve();
}