#include<cstdio>

#include<vector>

#include<queue>

#include<cstring>

#include<iostream>

#include<algorithm>

#include<ctime>

#include<random>

#include<assert.h>

#define pb emplace_back

#define mp make_pair

#define fi first

#define se second

#define dbg(x) cerr<<"In Line "<< __LINE__<<" the "<<#x<<" = "<<x<<'\n';

#define dpi(x,y) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<'\n';

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int,int>pii;

typedef pair<ll,int>pli;

typedef pair<ll,ll>pll;

typedef pair<int,ll>pil;

typedef vector<int>vi;

typedef vector<ll>vll;

typedef vector<pii>vpii;

typedef vector<pil>vpil;

template<typename T>T cmax(T &x, T y){return x=x>y?x:y;}

template<typename T>T cmin(T &x, T y){return x=x<y?x:y;}

template<typename T>

T &read(T &r){

	r=0;bool w=0;char ch=getchar();

	while(ch<'0'||ch>'9')w=ch=='-'?1:0,ch=getchar();

	while(ch>='0'&&ch<='9')r=r*10+(ch^48),ch=getchar();

	return r=w?-r:r;

}

template<typename T1,typename... T2>

void read(T1 &x,T2& ...y){read(x);read(y...);}

const int mod=998244353;

inline void cadd(int &x,int y){x=(x+y>=mod)?(x+y-mod):(x+y);}

inline void cdel(int &x,int y){x=(x-y<0)?(x-y+mod):(x-y);}

inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}

inline int del(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}

inline int lowbit(int x){

	return x&(-x);

}

const int N=1000100;

int n,m,z[N],p[N],q[N];

char a[N],b[N],s[N];

ll ans;

struct Tree{

	ll tree[N];

	void modify(int x,ll v){++x;for(;x<=n+1;x+=lowbit(x))tree[x]+=v;}

	ll query(int x){++x;ll s=0;for(;x;x-=lowbit(x))s+=tree[x];return s;}

	ll query(int l,int r){return query(r)-query(l-1);}

}tr1,tr2;

signed main(){

	#ifdef do_while_true

//		assert(freopen("data.in","r",stdin));

//		assert(freopen("data.out","w",stdout));

	#endif

	read(n,m);

	scanf("%s%s%s",a+1,b+1,s+1);

	for(int i=2,l=0,r=0;i<=m;i++){

		if(i<=r)z[i]=min(z[i-l+1],r-i+1);

		else z[i]=0;

		while(i+z[i]<=m && s[z[i]+1]==s[i+z[i]])++z[i];

		if(i+z[i]-1>r)r=i+z[i]-1,l=i;

	}

	for(int i=1,l=0,r=0;i<=n;i++){

		if(i<=r)p[i]=min(z[i-l+1],r-i+1);

		else p[i]=0;

		while(p[i]<m && i+p[i]<=n && s[p[i]+1]==a[i+p[i]])++p[i];

		if(i+p[i]-1>r)r=i+p[i]-1,l=i;

	}

	reverse(b+1,b+n+1);

	reverse(s+1,s+m+1);

	for(int i=2,l=0,r=0;i<=m;i++){

		if(i<=r)z[i]=min(z[i-l+1],r-i+1);

		else z[i]=0;

		while(i+z[i]<=m && s[z[i]+1]==s[i+z[i]])++z[i];

		if(i+z[i]-1>r)r=i+z[i]-1,l=i;

	}

	for(int i=1,l=0,r=0;i<=n;i++){

		if(i<=r)q[i]=min(z[i-l+1],r-i+1);

		else q[i]=0;

		while(q[i]<m && i+q[i]<=n && s[q[i]+1]==b[i+q[i]])++q[i];

		if(i+q[i]-1>r)r=i+q[i]-1,l=i;

	}	

	reverse(q+1,q+n+1);

	/*

	for(int i=1;i<=n;i++)cout << p[i] << ' ';

	puts("");

	for(int i=1;i<=n;i++)cout << q[i] << ' ';

	puts("");

	*/

	for(int i=1;i<=n;i++)cmin(p[i],m-1),cmin(q[i],m-1);

	/*

	for(int i=1;i<=n;i++)

		for(int j=1;j<=n;j++)

			if(i<=j&&j<=i+m-2)

				if(p[i]>=m-q[j])

					ans+=p[i]-(m-q[j])+1;

	*/

	for(int i=n;i;i--){

		tr1.modify(m-q[i],1);

		tr2.modify(m-q[i],-m+q[i]+1);

		ans+=tr1.query(p[i])*p[i];

		ans+=tr2.query(p[i]);

		if(i-m+1>=1){

			int l=i-m+1;

			ans-=tr1.query(p[l])*p[l];

			ans-=tr2.query(p[l]);

		}

	}

	cout << ans << '\n';

    #ifdef do_while_true

		cerr<<'\n'<<"Time:"<<1.0*clock()/CLOCKS_PER_SEC*1000<<" ms"<<'\n';

	#endif

	return 0;

}