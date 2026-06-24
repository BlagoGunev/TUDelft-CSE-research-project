#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <cctype>
#include <vector>

using namespace std;

inline char read() {
	static const int IN_LEN = 1024 * 1024;
	static char buf[IN_LEN], *s, *t;
	if (s == t) {
		t = (s = buf) + fread(buf, 1, IN_LEN, stdin);
		if (s == t) return -1;	
	}
	return *s++;
}

template<class T>
inline bool R(T &x) {
	static char c;
	static bool iosig;
	for (c = read(), iosig = false; !isdigit(c); c = read()) {
		if (c == -1) return false;
		if (c == '-') iosig = true;
	}
	for (x = 0; isdigit(c); c = read())
		x = (x << 3) + (x << 1) + (c ^ '0');
	if (iosig) x = -x;
	return true;
}

const int OUT_LEN = 1024 * 1024;
char obuf[OUT_LEN], *oh = obuf;
inline void writechar(char c) {
	if (oh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), oh = obuf;
	*oh++ = c;
}

template<class T>
inline void W(T x) {
	static int buf[30], cnt;
	if (!x) writechar(48);
	else {
		if (x < 0) writechar('-'), x = -x;
		for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
		while (cnt) writechar(buf[cnt--]);
	}
}

inline void flush() { fwrite(obuf, 1, oh - obuf, stdout); }

const int MAXN = 100000 + 10;
const int MAXM = 100000 + 10;
int n, x, y, top, tot;
int w[MAXN], first[MAXN];
struct node { int next, to; } edge[MAXM << 1];
struct cut_node { int u, v; } cut_edge[MAXM]; 

inline void create(int x, int y) {
	tot++;
	edge[tot].next = first[x];
	first[x] = tot;
	edge[tot].to = y;
}

void readin() {
	R(n);
	for (int i = 1; i < n; ++i) 
		R(x), R(y), create(x, y), create(y, x);
	for (int i = 1; i <= n; ++i)
		R(w[i]);
}

void dfs(int cur, int fa) {
	for (int p = first[cur]; p; p = edge[p].next) {
		if (edge[p].to != fa) {
			dfs(edge[p].to, cur);
			if (w[edge[p].to] != w[cur]) {
				top++;
				cut_edge[top].u = cur;
				cut_edge[top].v = edge[p].to;
			}
		}
	}
}

void write(bool type, int num = 0) {
	if (type) {
		writechar('Y'), writechar('E'), writechar('S');
		writechar('\n'), W(num);
	} else {
		writechar('N'), writechar('O');
	}
}

void check() {
	int pos = -1;
	if (top == 0) return write(true, 1);
	if (top == 1) return write(true, cut_edge[1].u);
	if (cut_edge[1].u == cut_edge[2].u || cut_edge[1].u == cut_edge[2].v)
		pos = cut_edge[1].u;
	else  if (cut_edge[1].v == cut_edge[2].u || cut_edge[1].v == cut_edge[2].v)
		  	  pos = cut_edge[1].v;
	if (pos == -1) return write(false);
	for (int i = 3; i <= top; ++i)
		if (cut_edge[i].u != pos && cut_edge[i].v != pos)
			return write(false);
	write(true, pos);
}

int main() {
	readin();
	dfs(1, 1);
	check();
	flush();
	return 0;
}