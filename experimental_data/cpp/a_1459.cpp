#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <list>

#include <fstream>

#include <deque>

#include <set>

#include <map>

#include <queue>

#include <functional>

#include <numeric> 

#include <cmath> 

#include <bitset> 

#include <stack> 

#include <cassert> 

#include <chrono> 

#include <unordered_map> 

#include <array> 

//if (1.0 * clock() / CLOCKS_PER_SEC > 0.9)

using namespace std;

#define ifthen(x,y,z) (x ? y : z)

#define all(a) (a).begin(), (a).end()

#define sz(a) ((long long)(a).size());

#define ve vector

#define vf(a,n)for (int i = 0; i < (n); i++)cin >> (a)[i];

#define int long long

#define ld long double

#define ya cout << "Yes" << endl

#define no cout << "No" << endl

typedef ve<int> vi;

const int N = 1e6+ 1;

int MOD = 1e9 + 7;

const int inf = 1e9;

int mod_mul(int a, int b) { a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD; }

int mod_add(int a, int b) { a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD; }

int binpow(int a, int n) {

	int res = 1;

	while (n != 0) {

		if (n & 1)

			res = res * a % MOD;

		a = a * a % MOD;

		n >>= 1;

	}

	return res;

}

ve<int> prevs(ve<int>& a) {

	int n = a.size();

	ve<int> pr(n + 1);

	for (int i = 1; i <= n; i++)

	{

		pr[i] = pr[i - 1] + a[i - 1];

	}

	return pr;

}

struct SegmentTreeMass

{

	struct Node

	{

		int sum = 0;

		int add = 0;



		Node(int Sum = 0, int Add = 0)

		{

			sum = Sum;

			add = Add;

		}

	};



	Node neutral = Node();

	int n;

	vector<Node> tree;



	SegmentTreeMass(vector<int>& start)

	{

		n = start.size();

		tree.resize(4 * n + 228);

		init(start);

	}



	SegmentTreeMass(int N)

	{

		n = N;

		tree.resize(4 * n + 228);

		vector<int> start(n, 0);

		init(start);

	}



	Node merge(Node n1, Node n2)

	{

		return Node(n1.sum + n2.sum);

	}



	void fix(int v, int l, int r)

	{

		tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);

	}



	void apply(int v, int l, int r, int val)

	{

		tree[v].add += val;

		tree[v].sum += val * (r - l);

	}



	void init(int v, int l, int r, vector<int>& start)

	{

		if (l + 1 == r)

		{

			tree[v] = Node(start[l], 0);

			return;

		}



		int m = (r + l) / 2;

		init(v * 2 + 1, l, m, start);

		init(v * 2 + 2, m, r, start);

		fix(v, l, r);

	}



	void init(vector<int>& start)

	{

		init(0, 0, n, start);

	}



	void push(int v, int l, int r)

	{

		int m = (r + l) / 2;



		apply(v * 2 + 1, l, m, tree[v].add);

		apply(v * 2 + 2, m, r, tree[v].add);

		tree[v].add = 0;

	}



	// [l: r)

	Node query(int v, int l, int r, int ql, int qr)

	{

		if (ql <= l && r <= qr)

		{

			return tree[v];

		}

		if (r <= ql || qr <= l)

		{

			return neutral;

		}



		int m = (r + l) / 2;

		push(v, l, r);

		return merge(

			query(v * 2 + 1, l, m, ql, qr),

			query(v * 2 + 2, m, r, ql, qr));



	}



	Node query(int ql, int qr)

	{

		return query(0, 0, n, ql, qr);

	}



	void add(int v, int l, int r, int ql, int qr, int val)

	{

		if (ql <= l && r <= qr)

		{

			apply(v, l, r, val);

			return;

		}

		if (r <= ql || qr <= l)

		{

			return;

		}



		int m = (r + l) / 2;

		push(v, l, r);

		add(v * 2 + 1, l, m, ql, qr, val);

		add(v * 2 + 2, m, r, ql, qr, val);

		fix(v, l, r);

	}



	void add(int ql, int qr, int val)

	{

		add(0, 0, n, ql, qr, val);

	}



};

signed main()

{

	ios::sync_with_stdio(0);

	cin.tie(0);

	int tt = 1;

	cin >> tt;

	// пишу контест крутого чувака

	while (tt--)

	{

		int n;

		cin >> n;

		ve<int> a(n);

		ve<int> b(n);

		int colr = 0;	int colb = 0;



		for (int i = 0; i < n; i++)

		{

			char x;

			cin >> x;

			a[i] = x -  '0';

		}

		for (int i = 0; i < n; i++)

		{

			char x;

			cin >> x;

			b[i] = x - '0';

		}

		for (int i = 0; i < n; i++)

		{

			if (a[i] > b[i])

			{

				colr++;

			}

			else if(a[i] < b[i]) {

				colb++;

			}

		}

		if (colr == colb)

		{

			cout << "EQUAL" << endl;

		}

		if (colr < colb)

		{

			cout << "BLUE" << endl;

		}

		if (colr>colb)

		{

			cout << "RED" << endl;

		}

	}

}