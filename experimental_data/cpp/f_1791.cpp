#define _CRT_SEstartE_NO_DEPRECATE

#pragma warning(disable : 4996)

#include <map>

#include <unordered_map>

#include <set>

#include <fstream>

#include <queue>

#include <deque>

#include <stack>

#include <vector>

#include <string>

#include <iostream>

#include <algorithm>

#include <iterator>

#include <bitset>

#include <cstring>

#include <cstdio>

#include <cmath>

#include <cstdio>

#include <bits/stdc++.h>

#define ACcode ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

typedef long long ll;

typedef unsigned long long ull;

const ll maxn = 1e6 + 7;

const ll maxm = 2e7 + 7;

constexpr ll mod = 998244353;

const ll inf = 0x3f3f3f3f;

const ll INF = 0x3f3f3f3f3f3f3f3f;

const int Prime = 100007;

const double eps = 1e-10;

const double pi = acos(-1.0);

using namespace std;

int a[maxn], tree[maxn], n, m;

int lowbit(int x)

{

	return x & (-x);

}

void addone(int x, int y)

{

	for (; x <= n; x += lowbit(x))

		tree[x] += y;

}

void addall(int l, int r, int y)

{

	addone(l, y);

	addone(r + 1, -y);

}

int getone(int x)

{

	int val = 0;

	for (; x; x -= lowbit(x))

		val += tree[x];

	return val;

}

int cal(int x)

{

	int ans = 0;

	while (x)

	{

		ans += x % 10;

		x /= 10;

	}

	return ans;

}

void solve()

{

	cin >> n >> m;

	for (int i = 1; i <= n; i++)

		cin >> a[i], tree[i] = 0;

	for (int i = 1; i <= m; i++)

	{

		int ope, l, r;

		cin >> ope;

		if (ope == 1)

		{

			cin >> l >> r;

			addall(l, r, 1);

		}

		else

		{

			cin >> l;

			int cnt = getone(l);

			int temp = a[l];

			while (temp >= 10 && cnt)

				temp = cal(temp), cnt--;

			cout << temp << '\n';

		}

	}

}

signed main()

{

	ACcode;

	//freopen("house.in", "r", stdin);

	//freopen("house.out", "w", stdout);

	int t = 1;

	cin >> t;

	while (t--)

	{

		solve();

	}

	return 0;

}