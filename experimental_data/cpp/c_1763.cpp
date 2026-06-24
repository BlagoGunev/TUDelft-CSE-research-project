#include<cstdio>

#include<iostream>

#include<vector>

#include<cstring>

#include<algorithm>

#define ll long long

#define inf 0x7fffffff

#define N 200010

using namespace std;

ll T,n,a[N];

ll read(){

    char c=getchar();

    ll x=0,f=1;

    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}

    while(c>='0'&&c<='9'){x=x*10+c-48,c=getchar();}

    return x*f;

}

int main(){

	T=read();

	while(T--){

		n=read();

		ll maxn=0;

		for(ll i=1;i<=n;++i)a[i]=read(),maxn=max(maxn,a[i]);

		if(n==2){

			printf("%lld\n",max(2*abs(a[1]-a[2]),a[1]+a[2]));

			continue;

		}

		if(n==3){

			printf("%lld\n",max(a[1]+a[2]+a[3],max(max(3*a[1],3*a[3]),max(3*abs(a[1]-a[2]),3*abs(a[2]-a[3])))));

			continue;

		}

		printf("%lld\n",maxn*n);

	}

	return 0;

}//