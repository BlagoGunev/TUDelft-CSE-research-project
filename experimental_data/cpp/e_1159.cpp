#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <map>
#include <functional>

using namespace std;

typedef long long ll;
#define pii pair<int, int>
#define mp make_pair

ll read() {
	int f = 1;
	ll res = 0;
	char ch;
	do {
		ch = getchar();
		if (ch == '-') f = -f;
	} while (ch < '0' || ch > '9');
	do {
		res = res * 10 + ch - '0';
		ch = getchar();

	} while (ch >= '0' && ch <= '9');
	return f == 1 ? res : -res;
}

const int N = 500010;
const int INF = 1000000000;
int n, m, q, K;
int mod = 1000000007;
int head[N], to[N << 1], nxt[N << 1], weight[N << 1], tot = 1;
char str[N];
int A[N], B[N];

void addEdge(int u, int v, int w) {
	tot++;
	nxt[tot] = head[u];
	to[tot] = v;
	head[u] = tot;
	weight[tot] = w;
}

ll myPow(ll a, int b) {
	if (b == 0) return 1;
	ll ans = myPow(a, b / 2);
	ans *= ans;
	ans %= mod;
	if (b % 2 == 1) {
		ans *= a;
		ans %= mod;
	}
	return ans;
}

void addMod(int &a, ll b) {
	a = (a + b) % mod;
}

int mulMod(int a, int b) {
	return 1LL * a * b % mod;
}

ll mmin(ll a, ll b) {
	return a < b ? a : b;
}

ll mmax(ll a, ll b) {
	return a > b ? a : b;
}

bool contain(int set, int i) {
	return (set & (1 << i)) > 0;
}
int countOne(int set) {
	int res = 0;
	while (set) {
		res++;
		set &= set - 1;
	}
	return res;
}

int main() {
	//freopen("C:/Users/user/Downloads/testdata.in", "r", stdin);
	//freopen("C:/Users/user/Downloads/testdata2.out", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
		}
		//fill(B + 1, B + n, -1);
		int start = 1;
		int end = n;
		stack<pii> cap;
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			while (!cap.empty()) {
				if (cap.top().first == i) {
					pii cur = cap.top();
					B[cur.second] = start++;
					cap.pop();
				}
				else break;
			}
			if (!cap.empty() && A[i] > cap.top().first) {
				ok = false;
				break;
			}
			if (A[i] == -1 ){
				if (cap.empty()) cap.push(mp(n + 1, i));
				else cap.push(mp(cap.top().first, i));
			}
			else {
				cap.push(mp(A[i], i));
			}
		}
		if (!ok) {
			cout << -1 << '\n';
		}
		else {
			while (!cap.empty()) {
				pii cur = cap.top();
				B[cur.second] = start++;
				cap.pop();
			}
			for (int i = 1; i <= n; i++) cout << B[i] << " ";
			cout << '\n';
		}
	}
	
	
	//system("pause");
	return 0;
}