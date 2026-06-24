#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>

using namespace std;

const int inf=200000000;
struct punct
{
    int x,y;
    bool operator <(const punct &aux) const
    {
        return x<aux.x;
    }
}v[100010];
int vmax[100010],vmin[100010],n;

long long solve()
{
    long long st=0,dr=1LL*inf*inf;
    while(st<=dr)
    {
        long long mid=(st+dr)/2;
        int maxx=-inf,minn=inf,ok=0;
        for(int i=1,j=1;j<=n;j++)
        {
            while(1LL*(v[j].x-v[i].x)*(v[j].x-v[i].x)>mid)
            {
                maxx=max(maxx,v[i].y);
                minn=min(minn,v[i].y);
                i++;
            }
            int a=max(maxx,vmax[j+1]),b=min(minn,vmin[j+1]);
            if(a<b) {ok=1;break;}
            if(1LL*(a-b)*(a-b)>mid) continue;
            if(1LL*a*a+1LL*v[i].x*v[i].x>mid) continue;
            if(1LL*a*a+1LL*v[j].x*v[j].x>mid) continue;
            if(1LL*b*b+1LL*v[i].x*v[i].x>mid) continue;
            if(1LL*b*b+1LL*v[j].x*v[j].x>mid) continue;
            ok=1;break;
        }
        if(ok) dr=mid-1;
        else st=mid+1;
    }
    return st;
}

int main()
{
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&v[i].x,&v[i].y);
    sort(v+1,v+1+n);
    vmax[n+1]=-inf;vmin[n+1]=inf;
    for(int i=n;i;i--)
    {
        vmax[i]=max(vmax[i+1],v[i].y);
        vmin[i]=min(vmin[i+1],v[i].y);
    }
    long long sol=min(1LL*(v[n].x-v[1].x)*(v[n].x-v[1].x),1LL*(vmax[1]-vmin[1])*(vmax[1]-vmin[1]));
    sol=min(sol,solve());
    for(int i=1;i<=n;i++) swap(v[i].x,v[i].y);
    sort(v+1,v+1+n);
    vmax[n+1]=-inf;vmin[n+1]=inf;
    for(int i=n;i;i--)
    {
        vmax[i]=max(vmax[i+1],v[i].y);
        vmin[i]=min(vmin[i+1],v[i].y);
    }
    sol=min(sol,solve());
    printf("%lld",sol);
    return 0;
}