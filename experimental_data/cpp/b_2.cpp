#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;


// FAST IO
//{{{
char *fstart;
const int MAXBUF=30000000;
char buf[MAXBUF];
void skip() {
	while (*fstart != 0  && !('0' <= *fstart && *fstart <= '9')) ++fstart;
}
template <class T> void GETNUM(T& n){
	skip();
	n=0;
	while ('0' <= *fstart && *fstart <= '9') n = n*10 + *fstart-'0', ++fstart;
}
void take_input() { // Take input using fast I/O
	int sz=fread(buf, sizeof(char), MAXBUF, stdin);
	buf[sz]=0;
	fstart=buf;
}
//}}}
// END FAST IO

const int MAX=1010;
int am2[MAX][MAX];
int am5[MAX][MAX];

int dp2[MAX][MAX];
int dp5[MAX][MAX];

const int INF=1<<19;
int n;

void do_dp() {
	for (int i=0;i<n;++i)
		for (int j=0;j<n;++j)
			dp2[i][j] = dp5[i][j] = INF;

	dp2[0][0] = dp5[0][0] = 0;
	for (int i=0;i<n;++i) {
		for (int j=0;j<n;++j) {
			dp2[i][j] += am2[i][j];
			dp5[i][j] += am5[i][j];
			if (i+1 < n) {
				if (dp2[i][j] < dp2[i+1][j]) dp2[i+1][j] = dp2[i][j];
				if (dp5[i][j] < dp5[i+1][j]) dp5[i+1][j] = dp5[i][j];
			}
			if (j+1 < n) {
				if (dp2[i][j] < dp2[i][j+1]) dp2[i][j+1] = dp2[i][j];
				if (dp5[i][j] < dp5[i][j+1]) dp5[i][j+1] = dp5[i][j];
			}
		}
	}
}

void reconstruct_path(int x, int y, int am[MAX][MAX], int dp[MAX][MAX]) {
	if (x==0 && y==0) return;
	if (x-1 >= 0 && dp[x][y] == dp[x-1][y] + am[x][y]) {
		reconstruct_path(x-1,y,am,dp);
		printf("D");
	}
	else {
		assert(y-1>=0);
		assert(dp[x][y] == dp[x][y-1] + am[x][y]);
		reconstruct_path(x,y-1,am,dp);
		printf("R");
	}
}

int main() {
	take_input();
	GETNUM(n);
	bool zero = 0;
	int zi, zj;
	for (int i=0;i<n;++i) {
		for (int j=0;j<n;++j) {
			int x;
			GETNUM(x);
			am2[i][j] = am5[i][j] = 0;
			if (x==0) {
				am2[i][j] = am5[i][j] = INF;
				zero=1,zi=i,zj=j;
			}
			while (x > 0 && !(x & 1)) ++am2[i][j], x >>= 1;
			while (x > 0 && x % 5 == 0) ++am5[i][j], x /= 5;
		}
	}
	do_dp();
	int ans2 = dp2[n-1][n-1];
	int ans5 = dp5[n-1][n-1];
	int minv = min(ans2, ans5);

	if (zero && 1 < minv) {
		printf("1\n");
		int i = 0, j = 0;

		// Go to (zi,zj)
		while (i < zi) printf("D"), ++i;
		while (j < zj) printf("R"), ++j;

		// Go to (n-1, n-1)
		while (i < n-1) printf("D"), ++i;
		while (j < n-1) printf("R"), ++j;

		printf("\n");
		return 0;
	}

	if (ans2 < ans5) {
		printf("%d\n", ans2);
		reconstruct_path(n-1,n-1,am2, dp2);
		printf("\n");
	}
	else {
		printf("%d\n", ans5);
		reconstruct_path(n-1, n-1, am5, dp5);
		printf("\n");
	}
}