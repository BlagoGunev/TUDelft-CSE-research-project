#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define vi vector<int>
#define sz(a) (int((a).size()))
#define mp make_pair
#define f first
#define s second

using namespace std;
const int N = 100100;
int n;
string a[N];
int sz, root = 0;
int ans = 0;

struct node {
	bool is_t;
	map<char, int> nxt;
	node () {
		this->is_t = false;
	}
	
} t[N];

multiset<int> st[N];

void add(string s) {
	int cur = root;
	for (int i = 0; i < sz(s); i++) {
		if (!t[cur].nxt.count(s[i])) t[cur].nxt[s[i]] = ++sz;
		cur = t[cur].nxt[s[i]];
	}
	t[cur].is_t = true;
	st[cur].insert(sz(s));
}

void dfs(int v, int len) {
	for (auto pr : t[v].nxt) {
		int to = pr.s;
		dfs(to, len + 1);
		for (auto x : st[to])
			st[v].insert(x);
	}
	if (!t[v].is_t && v > 0) {
		auto it = st[v].end();
		it--;
		ans -= *it;
		ans += len;
		st[v].erase(it);
		st[v].insert(len);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		add(a[i]);
		ans += sz(a[i]);
	}
	
	dfs(root, 0);
	cout << ans << endl;
	return 0;
}