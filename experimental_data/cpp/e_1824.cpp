// LUOGU_RID: 138775588
//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
struct SegT{
	ll lo[N<<2],hi[N<<2],sum[N<<2],val[N<<2];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l,hi[x]=r,sum[x]=val[x]=0;
		if(l==r)
		{
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		return;
	}
	void update(ll x,ll l,ll v)
	{
		ll tl=lo[x],tr=hi[x];
		if(tl==l&&l==tr)
		{
			sum[x]+=v;
			val[x]=sum[x]*tl;
			return;
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			update(a,l,v);
		}
		else
		{
			update(a|1,l,v);
		}
		sum[x]=sum[a]+sum[a|1];
		val[x]=val[a]+val[a|1];
		return;
	}
	ll query(ll x,ll v)
	{
		if(!v)
		{
			return 0;
		}
		ll tl=lo[x],tr=hi[x];
		if(tl==tr)
		{
			return tl*min(v,sum[x]);
		}
		ll a=x<<1;
		if(v>sum[a|1])
		{
			return val[a|1]+query(a,v-sum[a|1]);
		}
		return query(a|1,v);
	}
}segtn,segte;
ll n,a[N],b[N],fa[N],totleaf=0,leafnum=0,totnd,toted;
vector<pair<ll,pair<ll,ll> > > alled;
set<pair<ll,ll> > nei[N];
multiset<ll> nds[N];
ll getf(ll x){return x==fa[x]?x:fa[x]=getf(fa[x]);}
void insed(ll v)
{
	segte.update(1,v,1);
	return;
}
void deled(ll v)
{
	segte.update(1,v,-1);
	return;
}
void insnd(ll v)
{
	segtn.update(1,v,1);
	return;
}
void delnd(ll v)
{
	segtn.update(1,v,-1);
	return;
}
ll querynd(ll v)
{
	return segtn.query(1,v);
}
ll queryed(ll v)
{
	return segte.query(1,v);
}
void Merge(ll x,ll y)
{
//	cout<<"merge: "<<x<<" , "<<y<<endl;
	x=getf(x),y=getf(y);
	if(x==y)
	{
		return;
	}
	deled((*nei[x].lower_bound(make_pair(y,0))).S);
	toted--;
	if(nei[x].size()==1)
	{
		leafnum--;
		if(!nds[x].empty())
		{
			ll cval=*(--nds[x].end());
			totleaf-=cval;
			insnd(*(--nds[x].end()));
		}
	}
	if(nei[y].size()==1)
	{
		leafnum--;
		if(!nds[y].empty())
		{
			ll cval=*(--nds[y].end());
			totleaf-=cval;
			insnd(*(--nds[y].end()));
		}
	}
	nei[x].erase(nei[x].lower_bound(make_pair(y,0)));
	nei[y].erase(nei[y].lower_bound(make_pair(x,0)));
	if(nds[x].size()>nds[y].size())
	{
		swap(x,y);
	}
	for(set<pair<ll,ll> >::iterator it=nei[x].begin();it!=nei[x].end();it++)
	{
		nei[it->F].erase(make_pair(x,it->S));
		nei[it->F].insert(make_pair(y,it->S));
		nei[y].insert(*it);
	}
	nei[x].clear();
	for(multiset<ll>::iterator it=nds[x].begin();it!=nds[x].end();it++)
	{
		nds[y].insert(*it);
	}
	nds[x].clear();
	fa[x]=y;
	if(nei[y].size()==1)
	{
		leafnum++;
		if(!nds[y].empty())
		{
			ll cval=*(--nds[y].end());
			totleaf+=cval;
			delnd(cval);
		}
	}
	return;
}
ll calc()
{
	ll tot=min(totnd,toted+1);
	ll ndnum=tot-leafnum,ednum=tot-1;
//	cout<<ndnum<<" , "<<ednum<<": "<<querynd(ndnum)<<" , "<<queryed(ednum)<<endl;
	return totleaf+querynd(ndnum)+queryed(ednum);
}
int main(){
	ll i,j,x,y,z,w;
	segtn.build(1,1,200000);
	segte.build(1,1,200000);
	scanf("%lld",&n);
	totnd=n,toted=n-1;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		alled.push_back(make_pair(a[i],make_pair(i,-1)));
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&b[i]);
		nds[i].insert(b[i]);
		insnd(b[i]);
	}
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld%lld%lld",&x,&y,&z,&w);
		x--,y--;
		alled.push_back(make_pair(z,make_pair(x,y)));
		nei[x].insert(make_pair(y,w));
		nei[y].insert(make_pair(x,w));
		insed(w);
	}
	for(i=0;i<n;i++)
	{
		fa[i]=i;
		if(nei[i].size()==1)
		{
			leafnum++;
			totleaf+=b[i];
			delnd(b[i]);
		}
	}
	sort(alled.begin(),alled.end());
	ll ans=0;
	for(i=0;i<alled.size();i++)
	{
		ans=max(ans,alled[i].F*calc());
//		cout<<alled[i].F<<": "<<calc()<<endl;
		if(alled[i].S.S==-1)
		{
			totnd--;
			x=alled[i].S.F,y=getf(x);
//			cout<<"erz: "<<x<<endl;
			delnd(b[x]);
			if(nei[y].size()==1)
			{
				ll cval=*(--nds[y].end());
				totleaf-=cval;
				insnd(cval);
			}
			nds[y].erase(nds[y].lower_bound(b[x]));
			if(nei[y].size()==1)
			{
				if(nds[y].empty())
				{
					z=y;
					while(true)
					{
						w=(*nei[z].begin()).F;
						Merge(z,w);
						w=getf(w);
						if(nds[w].empty()&&nei[w].size()==1)
						{
							z=w;
						}
						else
						{
							break;
						}
					}
				}
				else
				{
					ll cval=*(--nds[y].end());
					totleaf+=cval;
					delnd(cval);
				}
			}
		}
		else
		{
			x=alled[i].S.F,y=alled[i].S.S;
			Merge(x,y);
		}
	}
	printf("%lld\n",ans);
	return 0;
}