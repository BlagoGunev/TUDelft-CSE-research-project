#include<cstdio>
#include<vector>
#include<algorithm>
#define N 10001000
#define M 500100
#define Q 1000000007
using namespace std;
int mu[N],cnt[N];
int lpf[N];
int prm[N/10],pcnt;
int a[M];
int qpow(int p)
{
    int r=1,x=2;
    while(p)
    {
        if(p&1) r=1LL*r*x%Q;
        x=1LL*x*x%Q;
        p>>=1;
    }
    return r;
}
int main()
{
    for(int i=2; i<N; i++)
    {
        if(!lpf[i]) lpf[i]=i,prm[pcnt++]=i;
        for(int j=0; j<pcnt && i*prm[j]<N; j++)
        {
            lpf[i*prm[j]]=prm[j];
            if(i%prm[j]==0) break;
        }
    }
    vector<int> v;
    int n;
    long long ans=0;
    mu[1]=-1;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        v.assign(1,1);
        cnt[1]++;
        for(int tmp=a[i]; tmp>=2;)
        {
            int p=lpf[tmp],tsz=v.size();
            while(tmp%p==0) tmp/=p;
            for(int i=0; i<tsz; i++)
            {
                v.push_back(v[i]*p);
                mu[v[i]*p]=-mu[v[i]];
                cnt[v[i]*p]++;
            }
        }
    }
    for(int i=2; i<N; i++)
    {
        ans+=1LL*mu[i]*(qpow(cnt[i])-1)*(n-cnt[i])%Q;
    }
    ans%=Q;
    if(ans<0) ans+=Q;
    printf("%d\n",(int)ans);
    return 0;
}