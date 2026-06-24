#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <chrono>
 
using namespace std;
 
#define _int64 long long
#define mo 998244353

template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
  }
  void add(int i, T x){
    while (i <= N){
      BIT[i] += x;
      i += i & -i;
    }
  }
  T get(int i){
    T ans = 0;
    while (i > 0){
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
  T get(int L, int R){
    return get(R) - get(L-1);
  }
};

int b[5000001];
int fi[5000001];
int p[5000001];
int dep[5000001];
vector<int> a[5000001];
vector<int> primes;
int ind[50000001];
int m;
int v[110000];

int mi[310000];
int ma[310000];

void doit(int x,int d)
{
	int i,y;
	ind[x]=m;
	dep[m]=d;
	m++;
	for (i=0;i<a[x].size();i++)
	{
		y=a[x][i];
		doit(y,d+1);
		p[ind[y]]=ind[x];
	}
}

void add1(int x,int l,int r,int ind,int v)
{
	int mid;
	if (l==r)
	{
		ma[x]=v;
		mi[x]=v;
		return;
	}
	mid=(l+r)/2;
	if (ind<=mid) add1(x+x+1,l,mid,ind,v);
	else add1(x+x+2,mid+1,r,ind,v);
	ma[x]=max(ma[x+x+1],ma[x+x+2]);
	mi[x]=min(mi[x+x+1],mi[x+x+2]);
}

pair<int,int> get1(int x,int l,int r,int ll,int rr)
{
	int mid;
	pair<int,int> p1,p2;
	if (r<ll) return make_pair((1<<30),-1);
	if (rr<l) return make_pair((1<<30),-1);
	if ((ll<=l)&&(r<=rr)) return make_pair(mi[x],ma[x]);
	mid=(l+r)/2;
	p1=get1(x+x+1,l,mid,ll,rr);
	p2=get1(x+x+2,mid+1,r,ll,rr);
	return make_pair(min(p1.first,p2.first),max(p1.second,p2.second));
}

int main()
{
	int i,j,k,n,l,t,x,y,o,b1,qq,ty,xx,yy,tmp;
	_int64 ans;
	set<int> st;
	memset(b,-1,sizeof(b));
	primes.clear();
	fi[1]=1;
	for (i=2;i<=5000000;i++)
	{
		if (b[i]==-1)
		{
			b[i]=primes.size();
			primes.push_back(i);

		}
		for (j=0;j<=b[i];j++)
		{
			if (i*primes[j]>5000000) break;
			b[i*primes[j]]=j;
		}
		if (i/primes[b[i]]%primes[b[i]]==0)
			fi[i]=fi[i/primes[b[i]]]*primes[b[i]];
		else fi[i]=fi[i/primes[b[i]]]*(primes[b[i]]-1);
	}
	for (i=1;i<=5000000;i++)
		a[i].clear();
	for (i=2;i<=5000000;i++)
		a[fi[i]].push_back(i);
	m=0;
	p[0]=-1;
	doit(1,0);
	//for (i=0;i<20;i++)
	//	cerr<<"i,b[i],fi[i]:"<<i<<" "<<b[i]<<" "<<fi[i]<<endl;
	scanf("%d%d",&n,&qq);
	for (i=0;i<310000;i++)
	{
		mi[i]=(1<<30);
		ma[i]=-1;
	}
	st.clear();
	binary_indexed_tree<_int64> bit(n+10);

	for (i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
		v[i]=ind[v[i]];
		add1(0,0,(1<<17)-1,i,v[i]);
		if (v[i]!=0) st.insert(i);
		//cerr<<"i,v[i]:"<<i<<" "<<v[i]<<" "<<dep[v[i]]<<endl;
		bit.add(i+1,dep[v[i]]);
	}
	for (o=0;o<qq;o++)
	{
		scanf("%d%d%d",&ty,&x,&y);
		x--;y--;
		if (ty==1)
		{
			while (1)
			{
				set<int>::iterator it=st.lower_bound(x);
				if (it==st.end()) break;
				tmp=*it;
				if (tmp>y) break;
				v[tmp]=p[v[tmp]];
				add1(0,0,(1<<17)-1,tmp,v[tmp]);
				bit.add(tmp+1,-1);
				if (v[tmp]==0) st.erase(tmp);
				x=tmp+1;
			}
		}
		else
		{
			//cerr<<"x,y:"<<x<<" "<<y<<endl;
			pair<int,int> pa=get1(0,0,(1<<17)-1,x,y);
			xx=pa.first;
			yy=pa.second;
			//cerr<<"xx,yy:"<<xx<<" "<<yy<<endl;
			while (xx!=yy)
			{
				if (dep[xx]>dep[yy])
				{
					xx=p[xx];
				}
				else yy=p[yy];
			}
			//cerr<<"x,y,xx:"<<x<<" "<<y<<" "<<xx<<" "<<dep[xx]<<endl;
			ans=(y-x+1);
			ans*=dep[xx];
			ans=bit.get(x+1,y+1)-ans;
			printf("%lld\n",ans);
		}
	}
}