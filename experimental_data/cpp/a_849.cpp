#define ONLINE_JUDGE
#include <bits/stdc++.h>



#define inf 0x3f3f3f3f

#define INF 0x3f3f3f3f3f3f3f3fLL

#define mod 1000000007

#define pb push_back

#define mp make_pair

#define sq(x) ((x)*(x))

#define x first

#define y second

#define eps 1e-8

#define bpt(x) (__builtin_popcount(x))

#define bptl(x) (__builtin_popcountll(x))

#define bit(x, y) (((x)>>(y))&1)

#define bclz(x) (__builtin_clz(x))

#define bclzl(x) (__builtin_clzll(x))

#define bctz(x) (__builtin_ctz(x))

#define bctzl(x) (__builtin_ctzll(x))

#define PQ priority_queue<pii, vector<pii>, greater<pii> >



using namespace std;

typedef long long INT;

typedef vector<int> VI;

typedef pair<int, int> pii;

typedef pair<pii, int> pi3;

typedef double DO;



template<typename T, typename U> inline void smin(T &a, U b) {if (a>b) a=b;}

template<typename T, typename U> inline void smax(T &a, U b) {if (a<b) a=b;}



inline void gn(long long&x){

	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');

	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;

}

inline void gn(int&x){long long t;gn(t);x=t;}

inline void gn(unsigned long long&x){long long t;gn(t);x=t;}

inline void gn(double&x){double t;scanf("%lf",&t);x=t;}

inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}

int power(int a, int b, int m, int ans=1) {

	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;

	return ans;

}



#define NN 110



int a[NN];



int main() {

#ifndef ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	//freopen("out.out", "w", stdout);

#endif

	

	int n;

	gn(n);

	for(int i=1; i<=n; i++) gn(a[i]);

	

	if(a[1]%2==1 and a[n]%2==1 and n%2==1) puts("Yes");

	else puts("No");

	

	return 0;

}