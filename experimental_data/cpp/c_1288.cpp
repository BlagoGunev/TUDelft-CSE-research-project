#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define mod 1000000007
#define iP pair<int,int>
int power(int x,int y){
    int res=1;
    //x=x%mod;
    while(y>0){
        if(y&1)res=(res*x);
        x=(x*x);
        y/=2;
    }
    return res;
}
int mulmod(int a,int b){ 
    int res=0;
    a=a%mod; 
    while(b>0){
        if(b%2==1) 
        res=(res+a)%mod;
        a=(a*2)%mod; 
        b/=2;
    }
    return res%mod; 
}
int32_t main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> dp(n+1,1);
    for(int i=1;i<=2*m;i++){
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i]%mod+dp[i-1]%mod)%mod;
        }
    }
    cout<<dp[n];
}