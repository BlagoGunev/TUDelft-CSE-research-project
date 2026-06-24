#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif

#define maxn 1000010

struct atype
{
	int place, s0, s1;
};

atype a[maxn];
LL sl0[maxn], sl1[maxn], sr0[maxn], sr1[maxn];

int len,n; 
int ac0=0, ac1=0;

void solve()
{
	//solve non-crossover type
	if (a[1].s1>0)
	{
		rep(i,1,n) swap(a[i].s0,a[i].s1);
		swap(ac0,ac1);
	}
	
	LL final=0;
	if (ac1==0)	//all zero
	{
		if (n==1)
		{
			final=LL(a[1].s0)*(a[1].s0-1)*(a[1].s0-2)/6;
		}
		else
		{
			final+=LL(a[1].s0)*a[n].s0*(ac0-a[1].s0-a[n].s0);
			final+=LL(a[1].s0)*(a[1].s0-1)/2*(a[n].s0);
			final+=LL(a[1].s0)*(a[n].s0)*(a[n].s0-1)/2;
		}
		cout<<final<<endl;
		return;
	}
	
	int pl=0;
	rep(i,1,n) if (a[i].s1>0) { pl=i; break; }
	
	LL v1=2*(a[pl-1].place-a[1].place), c1=0;
	c1+=LL(a[1].s0)*a[pl-1].s0*(ac0-a[1].s0-a[pl-1].s0);
	c1+=LL(a[1].s0)*(a[1].s0-1)/2*(a[pl-1].s0);
	c1+=LL(a[1].s0)*(a[pl-1].s0)*(a[pl-1].s0-1)/2;
	
	LL v2=2*(a[n].place-a[pl].place), c2=0;
	c2+=LL(a[pl].s1)*a[n].s1*(ac1-a[pl].s1-a[n].s1);
	c2+=LL(a[pl].s1)*(a[pl].s1-1)/2*(a[n].s1);
	c2+=LL(a[pl].s1)*(a[n].s1)*(a[n].s1-1)/2;
	
	LL v3=2*(len-(a[pl].place-a[pl-1].place)), c3=0;
	c3=LL(a[pl].s1)*a[pl-1].s0*(ac0+ac1-a[pl-1].s0-a[pl-1].s1-a[pl].s0-a[pl].s1);
	c3+=LL(a[pl].s1)*a[pl-1].s0*(a[pl-1].s0-1)/2;
	c3+=LL(a[pl].s1)*(a[pl].s1-1)/2*a[pl-1].s0;
	
	LL fv=v1; fv=max(fv,max(v2,v3));
	final=0;
	if (fv==v1) final+=c1;
	if (fv==v2) final+=c2;
	if (fv==v3) final+=c3;
	cout<<final<<endl;
}

	
void lemon()
{
	map<int, pair<int,int> > mc; 
	scanf("%d%d",&len,&n);
	rep(i,1,n) 
	{
		int x,y; scanf("%d%d",&x,&y);
		if (x==0) mc[y].first++; else mc[y].second++;
		if (x==0) ac0++; else ac1++;
	}
	
	int all=0;
	rept(it,mc)
	{
		all++; a[all].place=it->first; a[all].s0=it->second.first; a[all].s1=it->second.second;
	}
	n=all;
	
	//crossover type
	sl0[0]=0; sl1[0]=0;
	rep(i,1,n)
	{
		sl0[i]=sl0[i-1]+a[i].s0; sl1[i]=sl1[i-1]+a[i].s1;
	}
	
	sr0[n+1]=0; sr1[n+1]=0;
	repd(i,n,1)
	{
		sr0[i]=sr0[i+1]+a[i].s0; sr1[i]=sr1[i+1]+a[i].s1;
	}
	
	//answer=2n
	LL final=0;
	rep(i,1,n)
		if (a[i].s0>0)
		{
			final+=LL(a[i].s0)*(sl1[i-1])*sr1[i+1];
			final+=LL(a[i].s0)*(a[i].s1-1)*(a[i].s1)/2;
			final+=LL(a[i].s0)*a[i].s1*(sl1[i-1]+sr1[i+1]);
		}
		
	rep(i,1,n)
		if (a[i].s1>0)
		{
			final+=LL(a[i].s1)*sl0[i-1]*sr0[i+1];
			final+=LL(a[i].s1)*(a[i].s0-1)*(a[i].s0)/2;
			final+=LL(a[i].s1)*a[i].s0*(sl0[i-1]+sr0[i+1]);
		}
	
	if (final==0) 
	{
		solve();
		return;
	}
	
	if (a[1].place==0 && a[1].s0>0 && a[n].place==len && a[n].s0>0)
	{
		final+=LL(a[1].s0)*a[n].s0*(ac0-a[1].s0-a[n].s0);
		final+=LL(a[1].s0)*(a[1].s0-1)/2*(a[n].s0);
		final+=LL(a[1].s0)*(a[n].s0)*(a[n].s0-1)/2;
	}
	
	if (a[1].place==0 && a[1].s1>0 && a[n].place==len && a[n].s1>0)
	{
		final+=LL(a[1].s1)*a[n].s1*(ac1-a[1].s1-a[n].s1);
		final+=LL(a[1].s1)*(a[1].s1-1)/2*(a[n].s1);
		final+=LL(a[1].s1)*(a[n].s1)*(a[n].s1-1)/2;
	}
	
	cout<<final<<endl;
	
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("E.in","r",stdin);
	#endif
	lemon();
	return 0;
}