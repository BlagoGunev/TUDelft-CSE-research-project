#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rof(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int Maxn=1e4,inf=1e9;

int n,s[Maxn+5],t[Maxn+5],st[Maxn+5],h[2];
int f[Maxn+5][Maxn+5],pr[Maxn+5],mx[Maxn+5];

inline void Solve()
{
    cin>>n; For(i,1,n) scanf("%1d",&s[i]);
    int c0=0; For(i,1,n) scanf("%1d",&t[i]),c0+=(!t[i]);
    if(c0<n-c0) For(i,1,n) s[i]^=1,t[i]^=1;
    For(i,1,n) pr[i]=pr[i-1]+h[t[i]];
    For(i,0,n) For(j,0,n) f[i][j]=inf; f[0][0]=0;
    For(i,1,n)
    {
        if(!s[i])
        {
            For(j,0,i) f[i][max(0,j-1)]=min(f[i][max(0,j-1)],f[i-1][j]+t[i]);
            For(j,1,i) f[i][j]=min(f[i][j],f[i-1][j-1]+(t[i]^1)); continue;
        }
        if(t[i]) {For(j,1,i) f[i][j]=min(f[i][j],f[i-1][j-1]); continue;}
        For(j,1,i) f[i][j]=min(f[i][j],f[i-1][j-1]+1);
        For(j,0,i-1) f[i][j]=min(f[i][j],f[i-1][j+1]); mx[i]=-1;
        int top=0; For(j,i+1,n) mx[j]=max(mx[j-1],0)+h[t[j]];
        for(int j=i+1;j<=n;j+=2)
        {
            if(!t[j-1]) st[++top]=j-1; if(!t[j]) st[++top]=j; st[top+1]=j;
            int cur=pr[j]-pr[i-1],k=(-cur)/2,p=st[top-k+1],w=j-p+1+max(0,mx[p-1]);
            f[j][w]=min(f[j][w],f[i-1][0]+k); if(cur==0) break;
        }
    } int ans=inf;
    For(i,0,n) ans=min(ans,f[n][i]);
    printf("%d\n",ans);
}

int main()
{
    // freopen("1.in","r",stdin);

    int T; cin>>T; h[0]=-1,h[1]=1;
    while(T--) Solve();
    return 0;
}