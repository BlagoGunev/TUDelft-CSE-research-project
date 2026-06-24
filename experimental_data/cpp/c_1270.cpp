/*
Author: WangXP
Date:
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inc(i,n) for (int i=0;i<n;i++)
#define icc(i,n) for (int i=1;i<=n;i++)
#define rep(i,a,b) for (int i=a;i<b;i++)
#define rpp(i,a,b) for (int i=a;i<=b;i++)
#define dec(i,n) for (int i=n-1;i>=0;i--)
#define dcc(i,n) for (int i=n;i;i--)
ll rd(){
	ll x=0,f=1;char c=getchar();
	while (!isdigit(c) && c!='-') c=getchar();
	if (c=='-') f=-1,c=getchar();
	while (isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*f;
}

const int N=500010;

ll a[N];

int main(){
	int T=rd();
	while (T--){
		int n=rd();
		inc(i,n) a[i]=rd();
		ll sum=accumulate(a,a+n,0ll);
		ll s2=0;
		inc(i,n) s2^=a[i];
		//cout<<sum+s2+(sum+s2)<<' '<<2*(sum+s2)<<'\n';
		puts("2");
		printf("%lld %lld\n",s2,sum+s2);
	}
	return 0;
}