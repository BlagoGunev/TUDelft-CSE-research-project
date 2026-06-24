#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <string>

#include <array>

#include <vector>

#include <map>

#include <unordered_map>

#include <set>

#include <unordered_set>

#include <stack>

#include <queue>

#include <bitset>

#include <algorithm>

#include <numeric>

#include <functional>

#include <cmath>

#include <complex>



using namespace std;

typedef long long ll;

#define finc(i,a,b) for(int i=(int)(a);i<(int)(b);i++)

#define fdec(i,a,b) for(int i=(int)(b);i-->(int)(a);)

#define endl '\n'

#define endb ' '

#define read(a,str) scanf("%"#str,&a)



class Find

{

private:

	int n, id;

	vector<vector<pair<int, int>>> st;

	vector<int> cnt, fa;



	void change(int a, int b)

	{

		fa[a] = b, cnt[b] += a;

		st[a].push_back({ id,b });

	}

	int getFa(int u)

	{

		while (u != fa[u])

			u = fa[u];

		return u;

	}

	int getFa(int u, int now)

	{

		while (1)

		{

			int ret = 0;

			for (auto& I : st[u])

				if (I.first <= now)

					ret = I.second;

			if (u == ret)

				return u;

			u = ret;

		}

	}

public:

	Find(int _n) :n(_n), id(0)

	{

		st.assign(n + 1, {});

		cnt.assign(n + 1, 1), fa.assign(n + 1, 0);

		finc(i, 1, n + 1)

			st[i].push_back({ 0,i }), fa[i] = i;

	}



	void add(int u, int v)

	{

		id++;

		auto a = getFa(u), b = getFa(v);

		if (a != b)

			if (cnt[a] < cnt[b])

				change(a, b);

			else

				change(b, a);

	}

	bool check(int u, int v, int now)

	{

		return getFa(u, now) == getFa(v, now);

	}

};

class St

{

private:

	int n;

	vector<array<int, 20>> st;

	vector<int> fact;



public:

	St(int _n, const vector<int>& vec) :n(_n)

	{

		st.assign(n + 1, {}), fact.assign(n + 1, 0);



		fact[0] = -1;

		finc(i, 1, n + 1)

			st[i][0] = vec[i], fact[i] = fact[i >> 1] + 1;



		finc(j, 1, 20)

			finc(i, 1, n + 1)

			st[i][j] = max(st[i][j - 1], st[min(n, i + (1 << (j - 1)))][j - 1]);

	}



	int query(int l, int r)

	{

		if (r < l)

			return 0;

		int x = fact[r - l + 1];

		return max(st[l][x], st[r - (1 << x) + 1][x]);

	}

};



void ac()

{

	int n, m, q; cin >> n >> m >> q;



	Find kaze(n);

	finc(i, 1, m + 1)

	{

		int u, v; cin >> u >> v;

		kaze.add(u, v);

	}



	vector<int> note(n + 1);

	finc(i, 1, n)

	{

		int l = 0, r = m + 1;

		while (l < r)

		{

			int mid = (l + r) >> 1;

			if (kaze.check(i, i + 1, mid))

				note[i] = mid, r = mid;

			else

				l = mid + 1;

		}

	}



	St hana(n, note);

	while (q--)

	{

		int l, r; cin >> l >> r;

		cout << hana.query(l, r - 1) << endl;

	}

	cout << endl;

}



int main()

{

	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int test = 1; cin >> test;



	while (test--)

		ac();



	return 0;

}