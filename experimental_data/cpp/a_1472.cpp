#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<ctime>
#include<cmath>
#include<vector>
#include<set>
using namespace std;
#define pb push_back
#define PI acos(-1.0)
typedef long long ll;
ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}
inline ll read(){
    char c=getchar();ll x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int inf=0x3f3f3f3f;
const int maxn=5e3+5;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int w,h,n;
		int cnt1=1,cnt2=1;
		scanf("%d%d%d",&w,&h,&n);
		while(w%2==0)
		{
			w/=2;
			cnt1*=2;
		}
		while(h%2==0)
		{
			h/=2;
			cnt2*=2;
		}
		int ans=cnt1*cnt2;
		if(ans>=n)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}