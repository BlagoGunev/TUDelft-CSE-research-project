// LUOGU_RID: 101225145
#include <bits/stdc++.h>

using namespace std;

#define int long long

#define mp make_pair

#define inf 1e9

#define pii pair <int, int>

const int mod = 1e9 + 7;

inline int read () {

	int x = 0, f = 1;

	char ch = getchar ();

	while (ch < '0' || ch > '9') f = ((ch == '-') ? -1 : f), ch = getchar ();

	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar ();

	return x * f;

}

inline void write (int x) {

	if (x < 0) x = -x, putchar ('-');

	if (x >= 10) write (x / 10);

	putchar (x % 10 + '0');

}

struct BIT_TREE {

	int bit[400005];

	inline int lowbit(int x) {

		return x & (-x);

	}

	inline void add(int x, int y) {

//		if(x <= 0) printf("???%lld %lld\n", x, y);

		for(int i = x; i <= 400000; i += lowbit(i)) bit[i] += y;

	}

	inline int Sum(int x) {

		if(x < 0) return 0;

		int Ans = 0;

		for(int i = x; i; i -= lowbit(i)) Ans += bit[i];

		return Ans;

	}

}T;

int n, m, k;

struct st {

	int l, r;

}a[400005];

int ans[200005];



struct Node {

	int l, r, x;

	Node() {}

	Node(int A, int B, int C) {

		l = A, r = B, x = C;

	}

	bool operator <(const Node &A) const {

		return l < A.l || (l == A.l && r < A.r) || (l == A.l && r == A.r && x < A.x);

	}

};



set <Node> S;



inline int deal(int l, int r) {

	int mx = 0;

	while(!S.empty()) {

		auto it = S.lower_bound(Node(l, 0, 0));

		if(it != S.end() && (*it).l <= r) {

			Node now = Node(r + 1, (*it).r, (*it).x);

			T.add((*it).x, -(min((*it).r, r) - (*it).l + 1));

			mx = max(mx, (*it).x);

			S.erase(it);

			if(now.l <= now.r) S.insert(now);

		}

		else if(it != S.begin() && (*--it).r >= l) {

			if((*it).r >= r && (*it).l <= l) {

				Node x = Node((*it).l, l - 1, (*it).x), y = Node(l, (*it).r, (*it).x);

				S.erase(it);

				S.insert(x), S.insert(y);

				continue;

			}

			Node now = Node((*it).l, l - 1, (*it).x);

			T.add((*it).x, -((*it).r - l + 1));

			mx = max(mx, (*it).x);

			S.erase(it);

			if(now.l <= now.r) S.insert(now);

		}

		else break;

	}

//	if(!mx) printf("???\n");

	return mx;

}



inline int Insert(int l, int r, int x, int tp) {

	int mx = deal(l, r);

	if(!tp) S.insert(Node(l, r, x)), T.add(x, r - l + 1);

	else S.insert(Node(l, r, max(mx, x))), T.add(max(mx, x), r - l + 1);

	return mx;

}



signed main () {

//	freopen (".in", "r", stdin);

//	freopen (".out", "w", stdout);

	n = read(), m = read(), k = read();

	for(int i = 1; i <= m; i++) a[i].l = a[i+m].l = read(), a[i].r = a[i+m].r = read();

	

	S.insert(Node(1, n, 2 * m));

	for(int i = m + k - 1; i >= 1; i--) {

//		printf("i:%lld\n", i);

		if(a[i].l < a[i].r) {

			int tmp = Insert(a[i].l + 1, a[i].r, i, 0);

			Insert(a[i].l, a[i].l, tmp, 1);

		}

		if(i <= m) ans[i] = n - T.Sum(i + k - 1);

	}

	for(int i = 1; i <= m; i++) write(ans[i]), putchar(' ');

	putchar('\n');

	return 0;

}

/*

*/