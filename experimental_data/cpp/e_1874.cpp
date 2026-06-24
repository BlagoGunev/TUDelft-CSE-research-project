#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

const int N=205;
const int mo=1e9+7;
long long fac[N],rfac[N];
long long F[N*N*2];
long long pw[N*N*2][N];
long long f[N*N*2];
long long ans[N*N*2];
int mx=0;
long long poww(long long a,long long n)
{
    long long ans=1;
    while(n)
    {
        if(n&1)
        {
            ans=a*ans%mo;
        }
        a=a*a%mo;
        n>>=1;
    }
    return ans;
}
int n,m;
long long C(int n,int m)
{
    if(m>n)return 0;
    return fac[n]*rfac[m]%mo*rfac[n-m]%mo;
}
long long add(long long x,long long y)
{
    long long ans=x+y;
    if(ans>=mo)return ans-mo;
    return ans;
}
long long g[2*N*N],xs[2*N*N];
void lgr()
{
    xs[0]=1;
	for(int i=1;i<=mx;i++)
    {
		for(int j=i;j>=1;j--)
        {
            xs[j]=add(xs[j]*(mo-i)%mo,xs[j-1]);
        }
        xs[0]=1ll*xs[0]*(mo-i)%mo;
	}
	for(int i=1;i<=mx;i++)
    {
        long long rv=1;
        for(int j=1;j<=mx;j++)
        {
            if(j!=i)rv=rv*(i-j+mo)%mo;
        }
        rv=poww(rv,mo-2);
        int inv=poww(mo-i,mo-2);
        g[0]=xs[0]*inv%mo;
        ans[0]=add(ans[0],1ll*g[0]*rv%mo*F[i]%mo);
        for(int j=1;j<=mx;j++)
        {
            g[j]=(xs[j]-g[j-1]+mo)*1ll*inv%mo;
            ans[j]=add(ans[j],1ll*g[j]*rv%mo*F[i]%mo);
        }
        // for(int j=0;j<mx;j++)
        // {
        //     ans[j]=add(ans[j],1ll*g[j]*rv%mo*F[i]%mo);
        // }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    fac[0]=rfac[0]=1;
    for(int i=1;i<=n;i++)
    {
        fac[i]=fac[i-1]*i%mo;
        rfac[i]=poww(fac[i],mo-2);
    }
    mx=n*(n+1)/2+1;
    for(int i=1;i<=mx;i++)
    {
        pw[i][0]=1;
        for(int j=1;j<=n;j++)
        {
            pw[i][j]=pw[i][j-1]*i%mo;
        }
    }

    for(int tp=1;tp<=mx;tp++)
    {
        memset(f,0,sizeof(f));
        f[0]=1;
        for(int i=1;i<=n;i++)
        {
            f[i]=0;
            for(int j=1;j<=i;j++)
            {
                f[i]=add(f[i],f[j-1]*f[i-j]%mo*C(i-1,j-1)%mo);
                
            }
            f[i]=f[i]*pw[tp][i]%mo;
        }
        F[tp]=f[n];

    }
    lgr();
    int as=0;
    for(int i=m;i<mx;i++)
    {
        
        as=add(as,ans[i]);
    }
    cout<<as<<'\n';
}