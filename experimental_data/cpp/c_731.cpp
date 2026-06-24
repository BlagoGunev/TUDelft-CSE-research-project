#include <vector>

#include <map>

#include <set>

#include <queue>

#include <stack>

#include <algorithm>

#include <sstream>

#include <iostream>

#include <cstdio>

#include <cmath>

#include <cstdlib>

#include <cstring>

#include <string>

#include <ctime>

#define fur(i,a,b) for(int i=(a);i<=(b);i++)

#define furr(i,a,b) for(int i=(a);i>=(b);i--)

#define cl(a) memset((a),0,sizeof(a))

#ifdef HandsomeHow

#define debug(...) fprintf(stderr, __VA_ARGS__)

#define dbg(x) cerr << #x << " = " << x << endl

#else

#define debug(...)

#define dbg(x)

#endif

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef pair <int, int> pii;

const int inf=0x3f3f3f3f;

const double eps=1e-8;

const int mod=1000000007;

const double pi=acos(-1.0);

inline void gn(long long&x){

    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');

    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;

}

inline void gn(int&x){long long t;gn(t);x=t;}

inline void gn(unsigned long long&x){long long t;gn(t);x=t;}

ll gcd(ll a,ll b){return a? gcd(b%a,a):b;}

ll powmod(ll a,ll x,ll mod){ll t=1ll;while(x){if(x&1)t=t*a%mod;a=a*a%mod;x>>=1;}return t;}

// (づ°ω°)づe★-------------------------------------------------

const int maxn = 200002;

int has[maxn];

int n,m,k;

struct Node{

	int p;

	int c;

}node[maxn];

int sz[maxn];

int findf(int x){

	if(x == node[x].p) return x;

	int tmp = findf(node[x].p);

	node[x].p = tmp;

	return tmp;

}



void merge(int x, int y){

	x = findf(x);

	y = findf(y);

	if(x!=y){

		if(sz[y]<sz[x])

			swap(x,y);

		sz[y] += sz[x];

		node[x].p = y;			

	}

}



bool cmp(Node &x, Node &y){

	return x.p < y.p;

}



int main(){

#ifdef HandsomeHow

    freopen("data.in","r",stdin);

    //freopen("data.out","w",stdout);

    time_t beginttt = clock();

#endif

	cl(has);

	gn(n);gn(m);gn(k);

	fur(i,1,n){

		sz[i]=1;

		node[i].p = i;

	}

	fur(i,1,n) gn(node[i].c);

	fur(i,1,m){

		int a,b;

		gn(a);gn(b);

		merge(a,b);

	}

	fur(i,1,n) 

		if(node[i].p == i) 

			continue;

		else 

			findf(i);

	

	sort(node+1,node+1+n,cmp);

	int ans = 0;

	int mx = 0;

	int beg = 1;

	fur(i,1,n){

		has[node[i].c]++;

		mx=max(mx,has[node[i].c]);

		if(node[i].p != node[i+1].p){

			ans+=sz[node[i].p]-mx;

			mx=0;

			fur(j,beg,i) has[node[j].c] = 0;

			beg = i+1;

		}

	}

	cout<<ans<<endl;

#ifdef HandsomeHow

	time_t endttt = clock();

    debug("time: %d\n",(int)(endttt - beginttt));

#endif

	return 0;

}