/*苍天负我笑,痴情待明朝*/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#define mp makepair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
void getint(ll &x){
	ll flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')flag=-1;ch=getchar();}
	ll ret=0;
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	x=ret*flag;
}
void getint(int &x){
	int flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')flag=-1;ch=getchar();}
	int ret=0;
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	x=ret*flag;
}
int n;
int X[100005],v[100005];

bool check(double k)
{
	double L=0,R=1e10;
	for(int i=1;i<=n;i++)
	{
		double x=X[i]-1.0*k*v[i];
		double y=X[i]+1.0*k*v[i];
		L=max(L,x);
		R=min(R,y);
	}
	return R>=L;
}

int main(){
	getint(n);
	
	double l=0,r=1e10,mid;

	for(int i=1;i<=n;i++)
	{
		getint(X[i]);
	}
	for(int i=1;i<=n;i++)getint(v[i]);
	
	double ans=1;
	
	while(l<r-1e-6)
	{
		mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	
	cout<<fixed<<setprecision(8)<<l;
	return 0;
}