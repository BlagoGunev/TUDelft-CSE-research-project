// LUOGU_RID: 94166682
#include<set>

#include<map>

#include<ctime>

#include<cmath>

#include<queue>

#include<bitset>

#include<cstdio>

#include<vector>

#include<random>

#include<cstdlib>

#include<cstring>

#include<iostream>

#include<algorithm>

#define ll long long

using namespace std;

#define I inline ll

#define her1 20090115

#define IV inline void

#define cht 998244353

#define ld long double

#define Aestas16 392699

#define ull unsigned long long

#define mem(x,val)memset(x,val,sizeof x)

#define D(i,j,n)for(register int i=j;i>=n;i--)

#define E(i,now)for(register int i=first[now];i;i=e[i].nxt)

#define F(i,j,n)for(register int i=j;i<=n;i++)

#define DL(i,j,n)for(register ll i=j;i>=n;i--)

#define EL(i,now)for(register ll i=first[now];i;i=e[i].nxt)

#define FL(i,j,n)for(register ll i=j;i<=n;i++)

//#define D(i,j,n)for(int i=j;i>=n;i--)

//#define E(i,now)for(int i=first[now];i;i=e[i].nxt)

//#define F(i,j,n)for(int i=j;i<=n;i++)

//#define DL(i,j,n)for(ll i=j;i>=n;i--)

//#define EL(i,now)for(ll i=first[now];i;i=e[i].nxt)

//#define FL(i,j,n)for(ll i=j;i<=n;i++)

ll read(){

	ll ans=0,f=1;

	char c=getchar();

	while(c<'0'||c>'9'){

		if(c=='-')f=-1;

		c=getchar();

	}

	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();

	return ans*f;

}

#define db long double

mt19937 rnd(her1);

const db eps = 1e-9;

const int maxn = 3e5+5;

multiset<pair<db,db> >st;

db sx,sy,tx,ty;ll n,xx,yy,P[maxn],Q[maxn];

IV sol(){

	n=read();xx=read();yy=read();sx=tx=xx,sy=ty=yy;st.clear();

	F(i,1,n)P[i]=read();F(i,1,n)Q[i]=read();if(!xx&&!yy){F(i,1,n)puts("0");return;}

	F(i,1,n){

		db p=P[i],q=Q[i];sx-=p,tx+=p,sy+=q,ty-=q;

		st.insert({q/p,p+p});while(sx<-eps){

			auto it=st.begin();st.erase(it);db r=(*it).first,d=(*it).second;

			if(sx+d>0){db D=sx+d;d-=D;st.insert({r,D});}sx+=d,sy-=d*r;

		}

		while(ty<-eps){

			auto it=--st.end();st.erase(it);db r=(*it).first,d=(*it).second;

			if(ty+r*d>0){db D=ty/r+d;d-=D;st.insert({r,D});}tx-=d,ty+=d*r;

		}

		printf("%.9Lf\n",tx);

	}

}

int main(){ll tc=read();while(tc--)sol();return 0;}