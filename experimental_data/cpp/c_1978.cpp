#include<bits/stdc++.h>
#define sf(x) scanf("%d",&x)
#define pf(x) printf("%d ",x)
#define sf2(x,y) scanf("%d %d",&x,&y)
#define pf2(x,y) printf("%d %d ",x,y)
#define sf3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define pf3(x,y,z) printf("%d %d %d ",x,y,z)
#define sfc(c) scanf(" %c",&c)
#define pfc(c) printf("%c",c)
#define pb(x) push_back(x)
#define sfl(x) scanf("%lld",&x)
#define mp(x,y) make_pair(x,y)
#define INF 1000000007
#define LLINF ll(1e18+10)
#define ENDL puts("")





using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef unsigned int uint;
typedef long double ld;



template<class T>
void printVector(T begin, T end) {
	for(T i=begin; i!=end; i++) {
		cout<<*i<<' ';
	}
	cout<<endl;
}





ll readLL() {
	ll x;
	cin >> x;
	return x;
}

int readInt() {
	int x;
	cin >> x;
	return x;
}








int p[200200];

void solve()
{
	ll n,k;
	cin>>n>>k;
	if(k&1)
	{
		printf("No\n");
		return;
	}
	for(int i=1; i<=n; i++)
	{
		p[i]=i;
	}
	int p1=1,p2=n;
	while(p1<p2)
	{
		if(abs(p[p2]-p1)+abs(p[p1]-p2)<=k)
		{
			k-=abs(p[p2]-p1)+abs(p[p1]-p2);
			swap(p[p1],p[p2]);
			p1++;
			p2--;
		}
		else
		{
			p1++;
		}
	}
	if(k)
	{
		printf("No\n");
	}
	else
	{
		printf("Yes\n");
		for(int i=1; i<=n; i++)
		{
			printf("%d ",p[i]);
		}
		printf("\n");
	}
}








int main() 
{
	/*
	/**/
	int t=1;
	sf(t);
	while(t--) 
	{
		solve();
	}
	return 0;
}