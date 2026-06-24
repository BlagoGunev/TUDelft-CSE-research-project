#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define lb(x) ((x)&(-(x)))
using namespace std;
inline int read()
{
	int s = 0; char c; while((c=getchar())<'0'||c>'9');
	do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');
	return s;
}
typedef long long lint;
const int N = 200010;
int n,v,lit;
pair< pair<int,int>, int > a[N];
pair<int,int*> li[N];
lint tr[N];
inline void upd(int p,lint x){ for(;p<=v;p+=lb(p)) tr[p] = max(tr[p],x); }
inline lint sum(int p){ lint s = 0; for(;p;p-=lb(p)) s = max(s,tr[p]); return s; }
lint work()
{
	int i;
	for(i=1;i<=n;i++)
	{
		lint tmp = sum(v-(a[i].first.second+1)+1);
		tmp += a[i].second;
		upd(v-a[i].first.first+1,tmp);
	}
	return sum(v);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int i;
	n = read();
	for(i=1;i<=n;i++)
	{
		a[i].first.second = read();
		li[++lit] = make_pair(a[i].first.second,&a[i].first.second);
		a[i].first.first = read();
		li[++lit] = make_pair(a[i].first.first,&a[i].first.first);
		a[i].second = read();
	}
	sort(li+1,li+1+lit);
	li[0].first = -1;
	for(i=1;i<=lit;i++)
	{
		if(li[i].first!=li[i-1].first) v++;
		(*li[i].second) = v;
	}
	sort(a+1,a+1+n);
	printf("%lld\n",work());
	return 0;
}