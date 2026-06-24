#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fs first
#define sc second
#define pb push_back

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a[m],b[m];
    int idx=-1;
    while(n--){
        int x;
        cin>>x;
        if(x>0){
            if(idx>=0)a[idx].pb(x);
        }else if(x<0){
            if(idx>=0)b[idx].pb(-x);
        }else idx++;
    }
    for(int i=0;i<m;i++){
        sort(begin(a[i]),end(a[i]));
        sort(begin(b[i]),end(b[i]));
    }
    int dp[m+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=m-1;i>-1;i--){
        for(int j=0;j<=i;j++){
            /*
            strength: j
            intelligence: i-j
            */
            dp[i][j]=max(dp[i][j],(int)(dp[i+1][j+1]+(upper_bound(begin(a[i]),end(a[i]),j+1)-begin(a[i]))+(upper_bound(begin(b[i]),end(b[i]),i-j)-begin(b[i]))));
            dp[i][j]=max(dp[i][j],(int)(dp[i+1][j]+(upper_bound(begin(a[i]),end(a[i]),j)-begin(a[i]))+(upper_bound(begin(b[i]),end(b[i]),i-j+1)-begin(b[i]))));
        }
    }
    cout<<dp[0][0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();
}