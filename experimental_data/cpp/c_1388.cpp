#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<ctime>
#include<iostream>
using namespace std;
#define bomb exit(1)
#define INF 1061109567
#define LINF 4557430888798830399ll
#define pprint(x) print(x),putchar(' ')
#define fprint(x) print(x),putchar('\n')
#define EE(x); struct edge { int nxt,to,w; }e[M << 1]; int head[N],ecnt = 1;\
	void add(int u,int v,ll w = 0) { e[++ecnt].w = w,e[ecnt].to = v,e[ecnt].nxt = head[u];head[u] = ecnt; }\
	void add_edge(int u,int v,ll w = 0) { add(u,v,w),add(v,u,w * x); }
#define ll long long
#define C const
#define iter iterator
const double pi = acos(-1.0);
const int mod = 998244353;
void reduce(int &a) { a += a >> 31 & mod; }
int Mod(int x) { return x >= mod ? x - mod : x; }
#define eps 0.0000000001
#define fi first
#define se second
//#define getchar() (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
//char BB[1 << 15],*SS = BB,*TT = BB;
int read()
{
	int x = 0;int f = 1;char ch = getchar();
	for(;!isdigit(ch);ch = getchar()) if(ch == '-') f = -1;
	for(;isdigit(ch);ch = getchar()) x = x * 10 + (ch ^ 48);
	return x * f;
}
void print(ll x)
{
	if(x < 0) putchar('-'),x = -x;
	if(x > 9) print(x / 10);putchar(x % 10 + '0');
}
int T = read();
C int N = 100010,M = N;
int n,m;EE(1);
int sum[N],p[N],h[N],num[N];bool fl;
void dfs1(int u,int fa)
{
	sum[u] = p[u];
	for(int i = head[u],v;i;i = e[i].nxt) if((v = e[i].to) ^ fa)
		dfs1(v,u),sum[u] += sum[v];
	if(sum[u] + h[u] < 0 || sum[u] - h[u] < 0 || ((sum[u] + h[u]) & 1)) fl = 1;
	num[u] = sum[u] - h[u] >> 1;
}
void dfs2(int u,int fa)
{
	int tot = 0;
	for(int i = head[u],v;i;i = e[i].nxt) if((v = e[i].to) ^ fa)
		dfs2(v,u),tot += num[v];
	if(num[u] - p[u] > tot) fl = 1;
}
int main()
{
	while(T--)
	{
		n = read(),m = read();
		for(int i = 1;i <= n;i++) p[i] = read();
		for(int i = 1;i <= n;i++) h[i] = read();
		ecnt = 0;for(int i = 1;i <= n;i++) head[i] = 0;
		for(int i = 1;i < n;i++) add_edge(read(),read());
		fl = 0,dfs1(1,0);
		if(fl) { puts("NO");continue; }
		dfs2(1,0);
		if(fl) puts("NO");
		else puts("YES");
	}
	return 0;
}