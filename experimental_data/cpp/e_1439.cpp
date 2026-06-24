#include <stdio.h>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#define inf 2000000000
using namespace std;
map<pair<int,int>,int> mp;int N,sd[400010],de[400010];
struct SPt
{
    int x,y;SPt(){}
    SPt(int X,int Y):x(X),y(Y){}
    int sd(){return x+y;}
    int wz()
    {
        auto t=make_pair(x,y);
        if(mp[t])return mp[t];
        mp[t]=++N;::sd[N]=x+y;
        return N;
    }
};
bool operator==(const SPt&a,const SPt&b)
{
    return a.x==b.x&&a.y==b.y;
}
struct SLi
{
    SPt s,t;SLi(){}
    SLi(SPt S,SPt T):s(S),t(T){}
    int getfx(){return s.x==t.x;}
};
int lb(int x){return x==0?inf:x&(-x);}
int split(int x,int y,SLi li[100])
{
    int rt=0;
    while(x||y)
    {
        SPt e(x,y);
        if(lb(x)<lb(y))
        {
            while(lb(x)<lb(y))x&=x-1;
            li[rt++]=SLi(SPt(x,y),e);
        }
        else
        {
            while(lb(x)>lb(y))y&=y-1;
            li[rt++]=SLi(SPt(x,y),e);
        }
    }
    for(int i=0,j=rt-1;i<j;i++,j--)swap(li[i],li[j]);
    return rt;
}
SPt getlca(SPt a,SPt b,int&cm)
{
    if(a==b){cm=0;return a;}
    SLi la[100],lb[100];
    int sa=split(a.x,a.y,la);
    int sb=split(b.x,b.y,lb),i;
    for(i=0;i<sa&&i<sb;i++)
    {
        if(la[i].t==lb[i].t)continue;
        if(la[i].getfx()!=lb[i].getfx())
        {
            cm=(la[i].getfx()==0?-1:1);
            return la[i].s;
        }
        else
        {
            if(la[i].getfx()==0)
            {
                if(la[i].t.x>lb[i].t.x)
                    {cm=(i==sb-1?1:-1);return lb[i].t;}
                else {cm=(i==sa-1?-1:1);return la[i].t;}
            }
            else
            {
                if(la[i].t.y>lb[i].t.y)
                    {cm=1;return lb[i].t;}
                else {cm=-1;return la[i].t;}
            }
        }
    }
    if(i==sa){cm=-1;return a;}
    else {cm=1;return b;}
}
SPt getlca(SPt a,SPt b)
{
    int c;
    return getlca(a,b,c);
}
bool operator<(const SPt&a,const SPt&b)
{
    int cm;getlca(a,b,cm);
    return cm<0;
}
SPt st[400010];int tp;vector<int> ve[400010];
int build(SPt sz[200010],int n)
{
    sz[n++]=SPt(0,0);
    sort(sz,sz+n);
	st[0]=sz[0];tp=1;
	for(int i=1;i<n;i++)
	{
        if(sz[i]==sz[i-1])continue;
		SPt u=sz[i],lc=getlca(u,st[tp-1]); 
		while(tp>=2&&lc.sd()<=st[tp-2].sd())
		{
			ve[st[tp-2].wz()].push_back(st[tp-1].wz());
			tp-=1;lc=getlca(u,st[tp-1]);
		}
		if(!(lc==st[tp-1]))
		{
			ve[lc.wz()].push_back(st[tp-1].wz());
			st[tp-1]=lc;
		}
		st[tp++]=u;
	}
	for(int i=0;i+1<tp;i++)ve[st[i].wz()].push_back(st[i+1].wz());
	return st[0].wz();
}
int bz[19][400010],cf[400010],cc[400010];
void yucl(int n)
{
    for(int s=1;s<=18;s++)
        for(int i=1;i<=n;i++)
            bz[s][i]=bz[s-1][bz[s-1][i]];
}
int getlca(int x,int y)
{
    if(de[x]<de[y])swap(x,y);
    for(int i=18;i>=0;i--)
        if(de[bz[i][x]]>=de[y])x=bz[i][x];
    if(x==y)return x;
    for(int i=18;i>=0;i--)
        if(bz[i][x]!=bz[i][y])x=bz[i][x],y=bz[i][y];
    return bz[0][x];
}
void dfs0(int u,int f)
{
    bz[0][u]=f;de[u]=de[f]+1;
    for(int x:ve[u])dfs0(x,u);
}
int dfs1(int u)
{
    for(int x:ve[u])cf[u]+=dfs1(x);
    return cf[u];
}
SPt A[100010],B[100010],sz[200010];map<int,int> jg;
void ins(int l,int r)
{
    if(l)jg[l-1]^=1;
    jg[r]^=1;
}
int main()
{
    int m;scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d%d",&A[i].x,&A[i].y,&B[i].x,&B[i].y);
        sz[i*2]=A[i];sz[i*2+1]=B[i];
    }
    int ro=build(sz,m*2);
    dfs0(ro,0);yucl(N);
    for(int i=0;i<m;i++)
    {
        int c=getlca(A[i].wz(),B[i].wz());
        cf[A[i].wz()]+=1;
        cf[B[i].wz()]+=1;cf[c]-=2;cc[c]=1;
    }
    dfs1(ro);
    for(int u=1;u<=N;u++)
    {
        if(u==ro||cf[u]==0)continue;
        int f=bz[0][u];
        ins(sd[f]+1,sd[u]);
    }
    for(int u=1;u<=N;u++)
        if(cc[u]&&cf[u]==0)ins(sd[u],sd[u]);
    int ans=0;
    for(auto it:jg)ans+=it.second;
    printf("%d",ans);
    return 0;
}