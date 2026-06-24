#include <bits/stdc++.h>

using namespace std;

long long ans[100001], tree[100001];
int n;

void upd(int x, int v) {
	for (; x <= n; x += x & -x)
		tree[x] += v;
}

long long sum(int x) {
	long long ret = 0;
	for (; x > 0; x -= x & -x)
		ret += tree[x];
	return ret;
}

int main() {
	int p;
	scanf("%d %d", &n, &p);
	vector<pair<int, int> > vec;
	for (int i = 1; i <= n; ++i) {
		int t;
		scanf("%d", &t);
		vec.push_back({ t, i });
	}
	sort(vec.begin(), vec.end(), greater<pair<int, int> >());

	priority_queue<int, vector<int>, greater<int> > pq;
	queue<int> q;
	long long now = 0;
	while (!vec.empty() || !pq.empty() || !q.empty()) {
		if (!vec.empty() && pq.empty() && q.empty())
			now = vec.back().first;
		while (!vec.empty() && now >= vec.back().first) {
			if ((pq.empty() || pq.top() > vec.back().second) && sum(vec.back().second - 1) == 0) {
				q.push(vec.back().second);
				upd(vec.back().second, 1);
			}
			else 
				pq.push(vec.back().second);
			vec.pop_back();
		}

		int w;
		while (!pq.empty()) {
			w = pq.top();
			if (sum(w - 1) == 0) {
				q.push(w);
				upd(w, 1);
				pq.pop();
			}
			else
				break;
		}

		w = q.front();
		q.pop();
		now += p;
		ans[w] = now;
		while (!vec.empty() && now >= vec.back().first) {
			if ((pq.empty() || pq.top() > vec.back().second) && sum(vec.back().second - 1) == 0) {
				q.push(vec.back().second);
				upd(vec.back().second, 1);
			}
			else
				pq.push(vec.back().second);
			vec.pop_back();
		}
		upd(w, -1);
	}

	for (int i = 1; i <= n; ++i)
		printf("%lld ", ans[i]);

	return 0;
}