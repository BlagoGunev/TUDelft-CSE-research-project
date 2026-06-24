// LUOGU_RID: 155797601
#include<stdio.h>
#include<bits/stdc++.h>
#define fir first
#define sec second
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int,int> pii;
template<typename type>
inline void chmin(type &x,const type &y)
{
	if(y<x)
		x=y;
}
template<typename type>
inline void chmax(type &x,const type &y)
{
	if(x<y)
		x=y;
}
bool mmp1;
constexpr int Max=1010,lim_6=23,len=100,w_lim=70;
int A,B,C,D;
bool can[lim_6+3][lim_6+3][lim_6+3][lim_6+3][9];
inline ll sp(const int &n)
{
	return n*(n+1)/2;
}
set<array<int,4>>s[w_lim+3];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>A>>B>>C>>D;
	queue<array<int,5>>q;
	auto trans=[&](int a,int b,int c,int d,int w)->void
	{
		if(!can[a][b][c][d][w]&&a<=A+len&&b<=B+len&&c<=C+len&&d<=D+len)
			can[a][b][c][d][w]=true,q.push({a,b,c,d,w});
	};
	trans(0,0,0,0,0);
	while(!q.empty())
	{
		auto t=q.front();
		q.pop();
		int a=t[0],b=t[1],c=t[2],d=t[3],w=t[4];
		if(w==6)
			continue;
		++w;
		trans(abs(a+w),b,c,d,w);
		trans(abs(a-w),b,c,d,w);
		trans(a,abs(b+w),c,d,w);
		trans(a,abs(b-w),c,d,w);
		trans(a,b,abs(c+w),d,w);
		trans(a,b,abs(c-w),d,w);
		trans(a,b,c,abs(d+w),w);
		trans(a,b,c,abs(d-w),w);
	}
	for(int w=0;w<=6;++w)
		for(int a=0;a<=lim_6;++a)
			for(int b=0;b<=lim_6;++b)
				for(int c=0;c<=lim_6;++c)
					for(int d=0;d<=lim_6;++d)
						if(!((a+b+c+d-sp(w))&1)&&sp(w)>=a+b+c+d&&!can[a][b][c][d][w])
							s[w].insert({a,b,c,d});
	auto check=[&](array<int,4>now,int w)->bool
	{
		for(int i=0;i<4;++i)
			for(int j:{-1,1})
			{
				array tmp=now;
				tmp[i]=abs(tmp[i]+j*w);
				if(!s[w-1].count(tmp)&&(tmp[0]+tmp[1]+tmp[2]+tmp[3]<=sp(w-1)))
					return false;
			}
		return now[0]<=A+len&&now[1]<=B+len&&now[2]<=C+len&&now[3]<=D+len;
	};
	for(int w=7;w<=w_lim;++w)
		for(auto now:s[w-1])
			for(int i=0;i<4;++i)
				for(int j:{-1,1})
				{
					auto tmp=now;
					tmp[i]=abs(tmp[i]+j*w);
					if(check(tmp,w))
						s[w].insert(tmp);
				}
	auto init=[&](int n)->vector<ll>
	{
		vector<ll>a(n+1,2);
		a[0]=1;
		return a;
	};
	auto mul=[&](vector<ll>a,vector<ll>b)->vector<ll>
	{
		int n=a.size(),m=b.size();
		vector<ll>c(n+m-1);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				c[i+j]+=a[i]*b[j];
		return c;
	};
	auto get=[&](int x)->int
	{
		int i=0;
		while(sp(i)<x||((sp(i)-x)&1))
			++i;
		return i;
	};
	vector<ll>res=mul(mul(init(A),init(B)),mul(init(C),init(D)));
	ll ans=0;
	for(int i=0;i<(int)res.size();++i)
		ans+=res[i]*get(i);
	for(int w=0;w<=w_lim;++w)
		for(auto now:s[w])
		{
			if(now[0]>A||now[1]>B||now[2]>C||now[3]>D)
				continue;
			int cnt=1;
			for(int i=0;i<4;++i)
				if(now[i])
					cnt*=2;
			ans+=(ll)cnt*(get(sp(w)+2)-w);
		}
	cout<<ans<<"\n";
	return 0;
}