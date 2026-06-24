#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

const int maxn = 100000 + 10;
const int INF = 0x3f3f3f3f;

template<typename T> bool chkmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool chkmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define REP(i, a, b) for(int i = (a); i < (b); i++) 
#define DREP(i, a, b) for(int i = (a-1); i >= (b); i--)
#define EREP(i, a) for(int i = Begin[(a)]; i; i = Next[i])

int read() {
	int n(0), f(1);
	register char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >='0' && ch <='9') { n = n * 10 + ch - 48; ch = getchar(); }
	return n * f;
}

int n;
int ans, res;
bool vis[maxn];

int main() {
	
	n = read();
	for(int i = 1; i <= 2*n; i++) {
		int a = read();
		if(vis[a]) --ans;
		else ++ans, vis[a] = 1;
		chkmax(res, ans);
	}printf("%d\n", res);

	return 0;
}