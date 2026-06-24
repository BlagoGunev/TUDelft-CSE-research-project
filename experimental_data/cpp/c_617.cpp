#include <bits/stdc++.h>
#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cctype>

#include<ctime>

#include<cstdlib>

#include<string>

#include<queue>

#include<cmath>

#define Rep(x,a,b) for (int x=a;x<=b;x++)

#define Per(x,a,b) for (int x=a;x>=b;x--)

#define ll long long

using namespace std;

inline int IN(){

	int x=0,ch=getchar(),f=1;

	while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();

	if (ch=='-'){f=-1;ch=getchar();}

	while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}

	return x*f;

}

struct Flower{

	ll x,y,da,db;

	bool operator <(const Flower&w)const{return da<w.da;} 

}a,b,c[2005];

ll Dist(Flower a,Flower b){

	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);

}

int n;

ll mxb[2005];

int main(){

	n=IN();

	a.x=1ll*IN(),a.y=1ll*IN();

	b.x=1ll*IN(),b.y=1ll*IN();

	Rep(i,1,n){

		c[i].x=1ll*IN(),c[i].y=1ll*IN();

		c[i].da=Dist(c[i],a);

		c[i].db=Dist(c[i],b);

	}

	sort(c+1,c+n+1);

	mxb[n+1]=0; 

	Per(i,n,1) mxb[i]=max(mxb[i+1],c[i].db);

	ll Ans=mxb[1],ND=0;

	Rep(i,2,n+1) Ans=min(Ans,c[i-1].da+mxb[i]);

	printf("%lld\n",Ans);

}