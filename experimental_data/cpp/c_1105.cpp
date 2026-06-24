#include<bits/stdc++.h>
#define N 200010
#define int long long
#define M 1000000007
using namespace std;

int dp[5];
int l,r,l2,r2;
int k0,k1,k2;
int a[5],n;

int32_t main() {
   // ifstream cin("t.in");
    cin>>n>>l>>r;
    l2=l,r2=r;
    while (l2%3) {
        a[l2%3]++; l2++;
    }
    while (r2%3) {
        a[r2%3]++; r2--;
    }
    a[0]=r2/3-(l2-1)/3;
    a[1]+=a[0]-1;
    a[2]+=a[0]-1;

    dp[0]=a[0]; dp[1]=a[1]; dp[2]=a[2];
    for (int i=2; i<=n; ++i) {
        k0=dp[0]*a[0]+dp[1]*a[2]+dp[2]*a[1];
        k1=dp[0]*a[1]+dp[1]*a[0]+dp[2]*a[2];
        k2=dp[0]*a[2]+dp[1]*a[1]+dp[2]*a[0];
        dp[0]=k0;
        dp[1]=k1;
        dp[2]=k2;
        dp[0]%=M; dp[1]%=M; dp[2]%=M;
    }

    cout<<dp[0];

    return 0;
}