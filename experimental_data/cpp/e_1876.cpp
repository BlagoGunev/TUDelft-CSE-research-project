#include<bits/stdc++.h>
#define ll long long
#define Ull unsigned ll
#define Int __int128
#define ld double
#define fi first
#define se second
#define PII pair<int,int>
#define PPIIL pair<PII,ll>
#define PLI pair<ll,int>
#define PIL pair<int,ll>
#define PLL pair<ll,ll>
#define FF fflush(stdout)
#define iter set<PPIIL>::iterator
using namespace std;
const int N=1e5+5;
int n,f[N],ans,rt,Sta[N],top,cnt;
vector<PII>E[N];
void DFS1(int x,int dad)
{
    for(PII p:E[x])if(p.fi!=dad)
    {
        f[1]+=(p.se!=-1);
        DFS1(p.fi,x);
    }
}
void DFS2(int x,int dad)
{
    if(f[x]>ans)ans=f[rt=x];
    for(PII p:E[x])if(p.fi!=dad)
    {
        f[p.fi]=f[x]-p.se;
        DFS2(p.fi,x);
    }
}
void DFS3(int x,int dad)
{
    for(PII p:E[x])if(p.fi!=dad)
    {
        int col=Sta[top];
        if(p.se!=-1)printf("%d %d %d\n",x,p.fi,Sta[++top]=++cnt);
        else printf("%d %d %d\n",p.fi,x,Sta[top--]);
        DFS3(p.fi,x);
        if(p.se!=-1)--top;
        else Sta[++top]=col;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    #endif

    scanf("%d",&n);
    for(int i=1,x,y,z;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        E[x].push_back({y,z});
        E[y].push_back({x,-z});
    }
    DFS1(1,0),DFS2(1,0);
    printf("%d\n",ans);
    DFS3(rt,0);

	fprintf(stderr,"%.15lf\n",(ld)clock()/CLOCKS_PER_SEC);
}