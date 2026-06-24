#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef long long LL;
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <algorithm>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

#define P1 972663749
#define P2 911382323
#define MOD 998244353
int expit(LL b, LL e) {
	LL r=1;
	while(e) {
		if (e&1) { r*=b; r%=MOD; }
		b*=b; b%=MOD;
		e>>=1;
	}
	return r;
}

bool rcmp(int a, int b) { return a>b; }
struct VNode {
	int v;
	bool operator<(const VNode& b) const {
		return v<b.v;
	}
};

int main() {
	int n, i, c, k, m;
	int tc; scanf("%d", &tc); while(tc--) {
		scanf("%d %d %d", &n, &m, &k);
		c = (n+m-1)/m;
		if (c+k>=n) printf("No\n"); else printf("Yes\n");
	}
	return 0;
}