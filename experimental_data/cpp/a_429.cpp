// Author: bill125
// ntr jcpwfloi
// orz LXLWDGY WJMZBMR dilutedream sevenkplus 
 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <bitset>
#include <cmath>

using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> Pair;
#define rep(i,n) for (int i=0; i<n; ++i)
#define repD(i,n) for (int i=n-1; i>=0; --i)
#define For(i,a,b) for (int i=a; i<=b; ++i)
#define ForD(i,a,b) for (int i=a; i>=b; --i)
#define ForE(i,a) for (Edge* i=h[a]; i; i=i->next)
#define forv(i,a) for (unsigned int i=0, ___t=a.size(); i<___t; ++i)
#define ForV(i,a) for (__typeof(a.begin()) i = a.begin();i != a.end();++i)
#define fill(a,b) memset(a,b,sizeof(a))
#define lowbit(a) ((a) & (-(a)))
#define sqr(a) ((a)*(a))
#define pb push_back
#define mp make_pair
#define gi gI()
#define cut puts("===================")
 
void setIO(string NAME) {
	#ifndef ONLINE_JUDGE
	string in=NAME+".in", out=NAME+".out";freopen(in.c_str(),"r",stdin),freopen(out.c_str(),"w",stdout);
	#endif
}
inline ll gI() {char c=getchar();while ((c<'0' || c>'9')&&c!='-') c=getchar();ll flag=1,p=0;if (c=='-') flag=-1,c=getchar();while (c>='0' && c<='9') p=p*10+(c-'0'),c=getchar();return p*flag;}
int gs(char *C) {char c=getchar();while (c==' ' || c=='\n') c=getchar();int l=0;while (c!=' ' && c!='\n') C[l++]=c,c=getchar();C[l]=0;return l;}
template <class T> void debug (const T a,const int & n) {rep(i,n) printf("%d%c", a[i],(i==n-1)?'\n':' ');}

const int inf=~0U>>1, maxn=100000+10;
int n;
int sum[maxn][2], dep[maxn], p[maxn], q[maxn];
int a[maxn], b[maxn];
bool choose[maxn];

struct Edge {
	int y;
	Edge *next;
	Edge (int _y, Edge *_next) : y(_y), next ( _next) {}
	Edge () {}
}*h[maxn];
void Add_Edge(int x, int y) {
	h[x]=new Edge(y, h[x]);
}

int main() {
	setIO("test");
	
	n = gi;
	rep(i, n-1) {
		int u = gi-1, v = gi-1;
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	
	int r = 1;
	q[0] = 0, p[0] = -1, dep[0] = 0;
	rep(i,r) {
		int x = q[i];
		ForE(e, x) {
			int y = e->y;
			if (y == p[x]) continue;
			dep[y] = dep[x] ^ 1;
			q[r++] = y;
			p[y] = x;
		}
	}
	rep(i,n) a[i]=gi;
	rep(i,n) b[i]=gi;
	
	int ans = 0;
	rep(i,n) {
		int x = q[i];
		if (a[x] ^ sum[x][dep[x]] != b[x]) {
			sum[x][dep[x]] ^= 1, ++ ans;
			choose[x] = 1;
		}
		ForE(e, x) {
			int y = e->y;
			if (y == p[x]) continue;
			sum[y][0] = sum[x][0];
			sum[y][1] = sum[x][1];
		}
	}
	printf("%d\n", ans);
	rep(i,n) {
		int x = q[i];
		if (choose[x]) printf("%d\n", x+1);
	}
	
	return 0;   
}