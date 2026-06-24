//  " بسم الله الرحمن الرحيم "
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define pi 3.141592654
#define all(a) a.begin(),(a).end()
#define INF 100000000000000
ll pre[10000001];
ll suf[10000001];
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dxx[4] = {-1, 1, 0, 0};
int dyy[4] = {0, 0, -1, 1};
void Fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void setIO(string file){
    if(!file.empty()){
        freopen((file+".in").c_str(),"r",stdin);
        freopen((file+".out").c_str(),"w",stdout);
    }
}
ll fast_power(ll x, ll y) {
    if (y == 0) return 1;
    if (y & 1) return x * fast_power(x, y - 1);
    ll res = fast_power(x, y / 2);
    return res * res;
}
const int mod = (int) 1e9 + 7;
int dp[100002];

void solve() {
    // Think Twice Code Once //
    int n;
    cin>>n;
    vector<int>v(n),pos(n+1),ans(n+1,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
        pos[v[i]]=i+1;
    }
    int cnt=n;
    for(int i=1;i<=n;i++){
            cout<<min(pos[i]+1,n)<<" ";
    }
    cout<<endl;
}

int main() {
    Fast();
    setIO("");
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}