// LUOGU_RID: 105651101
#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x)
{
	x=0;short f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;return;
}
const int N=1e6+5;
#define ll long long
struct node{
	ll x,y,s;
	ll maxy,maxs;
}tr[N];
ll tag[N];
int pri[N];
int ls[N],rs[N];
int idx,rt;
mt19937 rnd(time(0));
int newnode(ll x,ll y)
{
	idx++;
	tr[idx].x=x;
	tr[idx].y=tr[idx].maxy=y;
	tr[idx].s=tr[idx].maxs=y-x;
	pri[idx]=rnd();
	return idx;
}
void pushup(int u)
{
	tr[u].maxy=tr[u].y;
	tr[u].maxs=tr[u].s;
	if(ls[u])
	{
		tr[u].maxy=max(tr[u].maxy,tr[ls[u]].maxy);
		tr[u].maxs=max(tr[u].maxs,tr[ls[u]].maxs);
	}
	if(rs[u])
	{
		tr[u].maxy=max(tr[u].maxy,tr[rs[u]].maxy);
		tr[u].maxs=max(tr[u].maxs,tr[rs[u]].maxs);
	}
}
void pushtag(int u,ll t)
{
	if(!u) return;
	tag[u]+=t;
	tr[u].y+=t,tr[u].maxy+=t;
	tr[u].s+=t,tr[u].maxs+=t;
}
void pushdown(int u)
{
	pushtag(ls[u],tag[u]);
	pushtag(rs[u],tag[u]);
	tag[u]=0;
}
void split(int u,ll k,int &l,int &r)
{
	if(!u)
	{
		l=r=0;
		return;
	}
	pushdown(u);
	if(tr[u].x<=k)
	{
		l=u;
		split(rs[u],k,rs[u],r);
	}
	else
	{
		r=u;
		split(ls[u],k,l,ls[u]);
	}
	pushup(u);
}
int merge(int u,int v)
{
	if(!u||!v) return u+v;
	if(pri[u]<pri[v])
	{
		pushdown(u);
		rs[u]=merge(rs[u],v);
		pushup(u);
		return u;
	}
	else
	{
		pushdown(v);
		ls[v]=merge(u,ls[v]);
		pushup(v);
		return v;
	}
}
int n,m;
ll c;
vector<pair<ll,int>> v;
int main()
{
	read(n),read(m),read(c);
	for(int i=1;i<=n*2;++i)
	{
		ll x;read(x);
		v.push_back({x,1});
	}
	for(int i=1;i<=m*2;++i)
	{
		ll x;read(x);
		v.push_back({x,2});
	}
	sort(v.begin(),v.end());
	ll dx=0;
	rt=newnode(0,0);
	for(int i=0,msk=0;i<v.size();++i)
	{
		if(i&&msk&&v[i-1].first<v[i].first)
		{
			ll len=v[i].first-v[i-1].first;
			if(msk&1) dx+=len,pushtag(rt,len);
			if(msk&2) dx-=len;
			if(msk==3)
			{
				int l,m,r,tmp;
				split(rt,-c-1-dx,l,tmp);
				split(tmp,c-dx,m,r);
				if(l)
				{
					ll cy=tr[l].maxy;
					m=merge(newnode(-c-dx,cy),m);
				}
				if(r)
				{
					ll cs=tr[r].maxs;
					m=merge(m,newnode(c-dx,cs+(c-dx)));
				}
				pushtag(m,len);
				rt=merge(merge(l,m),r);
			}
		}
		msk^=v[i].second;
	}
	printf("%lld\n",tr[rt].maxy);
	return 0;
}