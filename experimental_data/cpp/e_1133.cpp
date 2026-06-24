#include <bits/stdc++.h>
using namespace std;
#define _____ ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<ll,ll> pii;
#define mkp make_pair
#define pb push_back
const int maxn = 5e3 + 5;
int n,k;
int dp[maxn][maxn];
int lst[maxn];
int a[maxn];
signed main(){
    _____
    #ifdef FWL
    freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    #endif // FWL
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    int l = 1, r = 1;
    while(r <= n){
        while(a[r] - a[l] > 5)l++;
        lst[r] = l-1;
        r++;
    }
    for(int j = 1; j <= k; j++)dp[1][j] = 1;
    int ans = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < k; j++){
            dp[i][j+1] = max(dp[lst[i]][j] + (i-lst[i]),dp[i-1][j+1]);
            ans = max(ans,dp[i][j+1]);
        }
    }
    cout << ans << '\n';
    return 0;
}