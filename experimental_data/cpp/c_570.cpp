#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <functional>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <climits>
#include <ctime>
using namespace std;

typedef long long ll;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define N 300005
#define M 50000005
#define judge(x,y) ((x)>=0&&(x)<h&&(y)>=0&&(y)<w)

template <class T>
inline bool getInt(T &x) {
	char c = 0; T sign = 1;
	if ((c = getchar()) == EOF) { return false; }
	while ((c < '0' || c > '9') && c != '-') { c = getchar(); };
	if (c == '-') { sign = -1; c = getchar(); }
	x = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') { x = x * 10 + c - '0'; }
	x *= sign;
	return true;
}

char s[N];

int main() {
	int n, m, x; char c[2];
	getInt(n); getInt(m);
	gets(s + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '.' && s[i + 1] == '.') { ans++; }
	}
	for (int i = 0; i < m; i++) {
		getInt(x); scanf("%s", c);
		if (c[0] != s[x]) {
			if (c[0] == '.') {
				ans += (s[x - 1] == '.') + (s[x + 1] == '.');
			} else if (s[x] == '.') {
				ans -= (s[x - 1] == '.') + (s[x + 1] == '.');
			}
			s[x] = c[0];
		}
		printf("%d\n", ans);
	}
}