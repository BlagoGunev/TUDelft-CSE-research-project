#include<bits/stdc++.h>
using namespace std;
int a[45][45];
int d[45],b[45];
int maxn,n;
void dfs(int k,int r)
{
    int i;
    bool flag;
    if (r+n-k+1<=maxn) return ;
    if (k==n+1)
    {
        if (r>maxn) maxn=r;
        return ;
    }
    flag=true;
    if (d[k]<=maxn-1) flag=false;
    else
    {
        for(i=1;i<=r;i++)
            if (a[b[i]][k]==0) {flag=false;break;}
    }
    if (flag)
    {
        b[r+1]=k;
        dfs(k+1,r+1);
    }
    dfs(k+1,r);
}
int main()
{
    int i,j,k;
    double ans;
    cin>>n>>k;
    memset(d,0,sizeof(d));
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if (a[i][j]==1) d[i]++;
        }
    maxn=1;dfs(1,0);
    ans=(maxn-1)*k*k*1.0/(2*maxn);
    printf("%.12f\n",ans);
    return 0;
}