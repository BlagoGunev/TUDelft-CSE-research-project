#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

void fileio()
{
  #ifdef LGS
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif
}
void termin()
{
  #ifdef LGS
  std::cout<<"\n\nEXECUTION TERMINATED";
  #endif
  exit(0);
}

using namespace std;

const LL MOD=1e9+7;

LL qpow(LL x,LL a)
{
	LL res=x,ret=1;
	while(a>0)
	{
		if(a&1) (ret*=res)%=MOD;
		a>>=1;
		(res*=res)%=MOD;
	}
	return ret;
}

LL n,q,par[200010][20],l[200010],r[200010],dep[200010];
LL ans=1;
vector <LL> g[200010];

void dfs(LL pos,LL d)
{
  dep[pos]=d;
  rep(i,g[pos].size()) dfs(g[pos][i],d+1);
}

LL getLCA(LL x,LL y)
{
  for(int i=18;i>=0;--i) if(par[x][i]>0&&dep[par[x][i]]>=dep[y]) x=par[x][i];
  for(int i=18;i>=0;--i) if(par[y][i]>0&&dep[par[y][i]]>=dep[x]) y=par[y][i];
  if(x==y) return x;
  for(int i=18;i>=0;--i) if(par[x][i]!=par[y][i]) x=par[x][i],y=par[y][i];
  return par[x][0];
}
LL getAnces(LL x,LL y){rep(i,19) if(y&(1<<i)) x=par[x][i];return x;}

struct Dsu
{
  LL fa[400010];
  Dsu(){rep(i,400005) fa[i]=i;}
  LL find(LL x){return fa[x]==x ? x:fa[x]=find(fa[x]);}
  bool merge(LL x,LL y,LL lev)
  {
    if(find(x)==find(y)) return false;
    if(lev==0)
    {
      (ans*=qpow((r[fa[x]]-l[fa[x]]+1)*(r[fa[y]]-l[fa[y]]+1)%MOD,MOD-2))%=MOD;
      (ans*=max(min(r[fa[x]],r[fa[y]])-max(l[fa[x]],l[fa[y]])+1,0LL))%=MOD;
      r[fa[y]]=min(r[fa[y]],r[fa[x]]);l[fa[y]]=max(l[fa[y]],l[fa[x]]);
    }
    fa[find(x)]=find(y);
    return true;
  }
}dsu[20];
void merge(LL x,LL y,LL lev)
{
  if(!dsu[lev].merge(x,y,lev)||lev==0) return;
  merge(x,y,lev-1);merge(par[x][lev-1],par[y][lev-1],lev-1);
}
void mergeR(LL x,LL y,LL lev)
{
  if(!dsu[lev].merge(x,y+(lev==0 ? 0:n),lev)||lev==0) return;
  mergeR(x,par[y][lev-1],lev-1);mergeR(par[x][lev-1],y,lev-1);
}
void mergePath(LL x,LL y,LL len)
{
  LL lev=__lg(len);
  merge(x,y,lev);
  merge(getAnces(x,len-(1<<lev)),getAnces(y,len-(1<<lev)),lev);
}
void mergePathR(LL x,LL y,LL len)
{
  LL lev=__lg(len);
  mergeR(x,getAnces(y,len-(1<<lev)),lev);
  mergeR(getAnces(x,len-(1<<lev)),y,lev);
}

int main()
{
  fileio();
  
  cin>>n;
  for(int i=2;i<=n;++i) scanf("%lld",&par[i][0]),g[par[i][0]].pb(i);
  rep(i,19) repn(j,n) par[j][i+1]=par[par[j][i]][i];
  repn(i,n) scanf("%lld %lld",&l[i],&r[i]),(ans*=(r[i]-l[i]+1))%=MOD;
  dfs(1,0);

  cin>>q;
  rep(qn,q)
  {
    LL a,b,c,d,ab,cd;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    if(ans==0)
    {
      puts("0");
      continue;
    }
    ab=getLCA(a,b);cd=getLCA(c,d);
    if(dep[a]-dep[ab]<dep[c]-dep[cd]) swap(a,c),swap(b,d),swap(ab,cd);
    LL tot=dep[a]+dep[b]-dep[ab]*2+1,l1=dep[c]-dep[cd]+1,l2=(dep[a]-dep[ab])-(dep[c]-dep[cd]),l3=tot-l1-l2;
    if(l1) mergePath(a,c,l1);
    if(l2) mergePathR(getAnces(a,l1),getAnces(d,l3),l2);
    if(l3) mergePath(b,d,l3);
    printf("%lld\n",ans);
  }

  termin();
}