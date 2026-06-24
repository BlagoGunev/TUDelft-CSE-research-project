#include<bits/stdc++.h>

#include<unordered_map>

#define ll long long

#define ull unsigned long long

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;



const int inf = 0x3f3f3f3f;

const ll INF = 0x3f3f3f3f3f3f3f3f;

const double eps = 1e-8;

const ll mod = 1000000007;

const int N = 3e5 + 5;



int n, m, is_swap[35], a[N];

struct node {

	int l, r;

	ll sum;

}tree[N << 2];



void push_up(int p)

{

	tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;

}



void build(int l, int r, int p)

{

	tree[p].l = l;

	tree[p].r = r;

	if (l == r)

	{

		tree[p].sum = a[l];

		return;

	}

	int mid = (l + r) / 2;

	build(l, mid, p << 1);

	build(mid + 1, r, p << 1 | 1);

	push_up(p);

}



void update(int pos, int val, int dep, int l, int r, int p)

{

	if (l == r)

	{

		a[l] = val;

		tree[p].sum = val;

		return;

	}

	int mid = (l + r) / 2;

	if (pos <= mid)

		update(pos, val, dep - 1, l, mid, (p << 1) + is_swap[dep]);

	else

		update(pos, val, dep - 1, mid + 1, r, (p << 1 | 1) - is_swap[dep]);

	push_up(p);

}



ll query(int ql, int qr, int dep, int l, int r, int p)

{

	if (ql <= l && qr >= r)

		return tree[p].sum;

	int mid = (l + r) / 2;

	ll ans = 0;

	if (ql <= mid)

		ans += query(ql, qr, dep - 1, l, mid, (p << 1) + is_swap[dep]);

	if(qr > mid)

		ans += query(ql, qr, dep - 1, mid + 1, r, (p << 1 | 1) - is_swap[dep]);

	return ans;

}



void solve()

{

	cin >> n >> m;

	for (int i = 1; i <= (1 << n); i++)

		cin >> a[i];

	build(1, 1 << n, 1);

	while (m--)

	{

		int op;

		cin >> op;

		if (op == 1)

		{

			int x, k;

			cin >> x >> k;

			update(x, k, n, 1, 1 << n, 1);

			//cout << "-----" << query(1, 4, n, 1, 1 << n, 1) << '\n';

		}

		else if (op == 2)

		{

			int k;

			cin >> k;

			for (int i = 1; i <= k; i++)

				is_swap[i] ^= 1;

		}

		else if(op == 3)

		{

			int k;

			cin >> k;

			is_swap[k + 1] ^= 1;

		}

		else

		{

			int l, r;

			cin >> l >> r;

			cout << query(l, r, n, 1, 1 << n, 1) << '\n';

		}

	}

}



signed main()

{

	IOS;

	ll t = 1;

	//cin >> t;

	while (t--)

		solve();

	return 0;

}