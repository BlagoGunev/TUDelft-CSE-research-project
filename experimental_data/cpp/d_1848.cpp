#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[200010],sum[200010];
int main(){
    int t;scanf("%d",&t);
    while(t--){
        ll n,m;scanf("%lld%lld",&n,&m);
        if(n%5==0){
            printf("%lld\n",max(n*m,(n+n%10)*(m-1)));
            continue;
        }
        ll ans=n*m;
        if(m<=40){
            for(int i=1;i<=40;i++)
            n+=n%10,m--,ans=max(ans,m*n);
            printf("%lld\n",ans);
            continue;
        }
        for(int i=1;i<=20;i++)
        n+=n%10,m--,ans=max(ans,m*n);
        ll s=0,v=n%10,k=0;
        do{
            s+=v%10;
            k++;v+=v%10;
        }while(v%10!=n%10);
        ll l=0,r=m/k;
        while(l<r){
            ll mid=l+r>>1;
            if((n+mid*s)*(m-k*mid)<(n+(mid+1)*s)*(m-k*(mid+1)))l=mid+1;
            else r=mid;
        }l=max(l-5,0ll);
        n+=l*s;m-=l*k;l*=k;
        ans=max(ans,n*m);
        int t=min(400ll,m);
        while(t--){
            n+=n%10,m--,
            ans=max(ans,m*n);
        }
        printf("%lld\n",ans);
    }
}