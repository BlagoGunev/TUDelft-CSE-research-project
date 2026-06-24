#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define e "\n"
#define ll long long
#define llong long long
#define all(v) v.begin(),v.end()

void fast() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin),
            freopen("output.txt", "w", stdout);
#endif
}

const ll mod = 1000000007 ,  M = 1002,LOG=25,N=209;

ll gcd(ll a, ll b) { return (!b) ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int dx[]={0,0,-1,1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};
int dp[N][N][N],vis[N][N][N],id;int n; vector<int>v;
int solve(int i,int l,int r){
    
    if(i>n){
        if(l>n)return 0;
        return 1e9;
    }
    
    int &ret=dp[i][l][r];
    if(vis[i][l][r]==id)return ret;
    
    vis[i][l][r]=id;
    ret= solve(i+1,l, max(r,i+1));
    if(i-v[i]+1<=l) {
        ret = min(ret, solve(i + 1, max(r, i + 1), max(r, i + 1)) + 1);
    }
    if(i<=l){
        ret= min(ret, solve(i+1,i+v[i],i+v[i])+1);
    }
    else {
        ret= min(ret, solve(i+1,l,i+v[i])+1);
    }
    return ret;
}
void solve() {
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    ++id;
    cout<<solve(1,1,1)<<e;
}
int main() {
    fast();
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
}