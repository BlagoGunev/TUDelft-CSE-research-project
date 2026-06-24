#include<bits/stdc++.h>

using namespace std;

using ll = long long;



struct Link {

	struct T {

		int lst, nxt, head, col, sz;

		T(int c) {

			lst = nxt = head = 0;

			col = c, sz = 1;

		}

	};

	vector<T> t;

	int newnode(int c) {

		int x = t.size();

		t.emplace_back(c);

		t[x].head = x;

		return x;

	}

	int newhead(int c) {

		int x = newnode(c);

		t[x].sz = 0;

		return x;

	}

	Link(int n, int q, const vector<int> &w) {

		t.reserve(n * 2 + q + 5);

		newnode(0);

		for (int i = 1; i <= n; i++) {

			newnode(w[i]);

		}

		for (int i = 1; i <= n; i++) {

			int x = newhead(t[i].col);

			insert(x, i);

		}

	}

	void insert(int u, int v) {

		t[v].head = t[u].head;

		++t[t[u].head].sz;



		t[v].nxt = t[u].nxt;

		if (t[u].nxt) {

			t[t[u].nxt].lst = v;

		}

		t[v].lst = u, t[u].nxt = v;

	}

	int merge(int u, int v) {

		if (t[u].sz < t[v].sz) {

			swap(u, v);

		}

		for (int i = t[v].nxt, j = t[i].nxt; i; i = j, j = t[i].nxt) {

			insert(u, i);

		}

		return u;

	}

	int remove(int v, int w) {

		--t[t[v].head].sz;

		t[t[v].lst].nxt = t[v].nxt;

		if (t[v].nxt) {

			t[t[v].nxt].lst = t[v].lst;

		}

		int x = newhead(w);

		insert(x, v);

		return x;

	}

	int gethead(int v) {

		return t[v].head;

	}

};



int main() {

	ios::sync_with_stdio(false);

	cin.tie(nullptr), cout.tie(nullptr);

	int n, q;

	cin >> n;

	vector<int> w(n + 1);

	for (int i = 1; i <= n; i++) {

		cin >> w[i];

	}

	cin >> q;

	Link lt(n, q, w);

	map<int, int> head;

	for (int i = 1; i <= n; i++) {

		if (head.count(w[i])) {

			head[w[i]] = lt.merge(head[w[i]], lt.gethead(i));

		} else {

			head[w[i]] = lt.gethead(i);

		}

	}

	for (int i = 1; i <= q; i++) {

		int op;

		cin >> op;

		if (op == 1) {

			int k, w;

			cin >> k >> w;

			int x = lt.remove(k, w);

			if (head.count(w)) {

				x = lt.merge(head[w], x);

			}

			lt.t[x].col = w;

			head[w] = x;

		} else if (op == 2) {

			int k;

			cin >> k;

			printf("%d\n", lt.t[lt.gethead(k)].col);

		} else {

			auto change = [&](int l, int r, int x) {

				auto p = head.lower_bound(l);

				int lst = 0;

				while (p != head.end() && p->first <= r) {

					if (lst == 0) {

						lst = p->second;

					} else {

						lst = lt.merge(lst, p->second);

					}

					p = head.erase(p);

				}

				if (lst) {

					if (head.count(x)) {

						lst = lt.merge(head[x], lst);

					}

					lt.t[lst].col = x;

					head[x] = lst;

				}

			};

			int l, r;

			cin >> l >> r;

			int mid = (l + r) / 2;

			change(l, mid, l - 1);

			change(mid + 1, r, r + 1);

		}

	}

	return 0;

}