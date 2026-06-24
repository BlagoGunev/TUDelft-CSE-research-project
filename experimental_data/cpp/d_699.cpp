// Copyright (c) 2016 jszyxw. All rights reserved.

#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
  
#define X first
#define Y second
#define LL long long
#define MP make_pair
#define pii pair<int, int>
#define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#define REP(i, x, y) for (int i = (x), _ = (y); i <= _; ++ i)
#define rep(i, x, y) for (int i = (y), _ = (x); i >= _; -- i)
#define REPedge(G, i, u) for (int i = st[u]; i; i = e[i].next)
  
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
  
template <class T> inline bool Chkmin(T &x, T y) { return x > y ? x = y, true : false; }
template <class T> inline bool Chkmax(T &x, T y) { return x < y ? x = y, true : false; }
  
template <class T> inline T read(T &x) 
{
	static int f;
	static char c; 
	for (f = 1; !isdigit(c = getchar()); ) if (c == '-') f = -1;
	for (x = 0; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	return x *= f;
}
template <class T> inline void write(T x, char P = 0) 
{
	static char s[25];
	static int top = 0; 
	if (x < 0) putchar('-'), x = -x;
	do s[++top] = x % 10 + 48; while (x /= 10);
	do putchar(s[top]); while (-- top);
	if (P) putchar(P);
}
  
using namespace std;
  
static int ___;
static const LL OO = 1e18;
static const int oo = 2e9;
static const int MO = 1e9 + 7;
static const double eps = 1e-8;
static const int MAXN = 2e5 + 5;
static const int End_Time = CLOCKS_PER_SEC * 0.98;
  
// EOT
 
int N;
int a[MAXN];
int b[MAXN];
int vis[MAXN];

int root;
int st[MAXN];
struct edge { int to, next; } e[MAXN << 1];
inline void addedge(int u, int v)
{
	static int ecnt = 0;
	e[++ecnt] = (edge) {v, st[u]};
	st[u] = ecnt;
}

void DFS(int x)
{
	vis[x] = 1;
	for (int i = st[x]; i; i = e[i].next) {
		if (vis[e[i].to] == 1) {
			if (root) b[x] = root;
			else b[x] = root = x;
		}
		if (!vis[e[i].to])
			DFS(e[i].to);
	}
	vis[x] = 2;
}

void Init()
{
	read(N);
	for (int i = 1; i <= N; ++ i) {
		b[i] = read(a[i]);
		if (a[i] == i) {
			if (root)
				b[i] = root, addedge(i, root);
			else
				root = i;
		} else addedge(i, a[i]);
	}
}

void Solve()
{
	if (root) DFS(root);

	for (int i = 1; i <= N; ++ i) {
		if (!vis[i]) { DFS(i); }
	}

	int ans = 0;
	for (int i = 1; i <= N; ++ i) {
		if (b[i] != a[i]) ans ++;
	}
	write(ans, '\n');
	for (int i = 1; i <= N; ++ i) {
		write(b[i] ? b[i] : a[i], ' ');
	}
}
 
// BOT
  
string Program_Name = "";
string Iput = Program_Name + ".in";
string Oput = Program_Name + ".out";
  
int main() 
{
	if (fopen(Iput.c_str(), "r") != NULL) {
		freopen(Iput.c_str(), "r", stdin);
		freopen(Oput.c_str(), "w", stdout);
	}

	Init();
	Solve();
  
	return 0;
}