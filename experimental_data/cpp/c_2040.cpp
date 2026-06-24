#include <bits/stdc++.h>
#define int long long
#define maxm 500005
#define maxn 1005
#define inf 0x3f3f3f3f3f3f
using namespace std;
int T,n,m,sum;
int a[maxm];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>sum;
        int l=1,r=n;sum--;
        for(int i=1;i<=n;i++){
            int x=n-i-1;
            if(x>60||x==-1)a[l++]=i;
            else{
                x=1ll<<x;
                if(sum>=x)sum-=x,a[r--]=i;
                else a[l++]=i;
            }
            // cout<<i<<" ["<<l<<","<<r<<"] "<<sum<<"\n";
        }
        if(sum)cout<<"-1\n";
        else{
            for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<"\n";
        }
    }
    return 0;
}