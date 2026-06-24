#include <bits/stdc++.h>

using namespace std;



#define N 100100



#define idx(c) (c - 'a')



struct Trie {

	int sz, c[N];

	vector <int> v[N];

	bool win[N], lose[N];



	int newnode(int val) {

		c[sz] = val;

		v[sz].clear();

		return sz ++;

	}



	void init() {

		sz = 0;

		newnode(-1);

	}



	void insert(char *s) {

		int x = 0;

		for (int i = 0; s[i]; i ++) {

			int nxt = 0, u = idx(s[i]);

			for (int j = 0; j < v[x].size(); j ++) {

				if (c[v[x][j]] == u) {

					nxt = v[x][j]; break;

				}

			}

			if (!nxt) nxt = newnode(u), v[x].push_back(nxt);

			x = nxt;

		}

	}



	void DFS(int x) {

		win[x] = 0;

		lose[x] = 0;

		for (int i = 0; i < v[x].size(); i ++) {

			int y = v[x][i];

			DFS(y);

			if (!win[y]) win[x] = 1;

			if (!lose[y]) lose[x] = 1;

		}

		if (!v[x].size()) lose[x] = 1;

	}

} Trie;



int n, k;

char s[N];



int main() {

//	freopen("d.in", "r", stdin);

	scanf("%d %d", &n, &k);

	Trie.init();

    for (int i = 1; i <= n; i ++) {

		scanf("%s", s);

		Trie.insert(s);

    }

    Trie.DFS(0);

    if (Trie.win[0] && (Trie.lose[0] || k % 2)) puts("First");

    else puts("Second");

	return 0;

}