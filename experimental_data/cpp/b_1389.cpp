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
C int N = 100010;
int T = read();
int n,k,z,a[N],ans,sum[N];
int main()
{
	while(T--)
	{
		n = read(),k = read(),z = read();
		for(int i = 1;i <= n;i++) a[i] = read();
		for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
		ans = 0;
		for(int i = 0;i <= z;i++)
		{
			int r = k + 1 - 2 * i,maxx = 0;
			if(r <= 1) continue;
			for(int i = 1;i < r;i++) maxx = max(maxx,a[i] + a[i + 1]);
			ans = max(ans,sum[r] + maxx * i);
		}
		for(int i = 1;i <= z;i++)
		{
			int r = k - 2 * (i - 1),maxx = 0;
			if(r <= 0) continue;
			for(int i = 1;i < r;i++) maxx = max(maxx,a[i] + a[i + 1]);
			ans = max(ans,sum[r] + maxx * (i - 1) + a[r - 1]);
		}
		fprint(ans);
	}
	return 0;
}