#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<memory.h>
using namespace std;
typedef long long ll;

const int N = 1e6+6;

int a[N];
int dp[N];
int di[N];
ll all;

int solve(int n, int m, ll b){
    if(all<=b) return 1;
    int l = n-1;
    ll sum = a[l];
    int r = 0;
    while(r<n && sum+a[r]<=b) sum+=a[r++];
    dp[l] = 1;
    di[l] = r;
    int ans = n;
    while(l>0){
        --l;
        sum+=a[l];
        while(sum>b){
            --r;
            if(r<0) r=n-1;
            sum-=a[r];
        }
        //cout<<"?"<<l<<' '<<r<<' '<<sum<<endl;
        if(l<r){
            dp[l] = dp[r]+1;
            di[l] = di[r];
        }else{
            dp[l] = 1;
            di[l] = r;
        }
        if(di[l]>=l) ans = min(ans, dp[l]);
    }
    return ans;
}

int main(){
    //freopen("input.txt","r",stdin);// freopen("output.txt","w",stdout);
    
    int n, m;
    
    scanf("%d%d",&n,&m);
    
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        all+=a[i];
    }
    for(int k=0;k<m;++k){
        ll x;
        scanf("%lld",&x);
        cout<<solve(n,m,x)<<endl;
    }
    
    return 0;
}