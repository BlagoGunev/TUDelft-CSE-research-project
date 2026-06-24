#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define mp make_pair
#define pb push_back
#define taskname ""
#define all(a) (a).begin(), (a).end()

const int MAXN = 1e6;

int dist(pii a, pii b) {
	return (abs(a.first - b.first) + abs(a.second - b.second));
}


void move(pii &cur , char step) {
	if (step == 'R') cur.second++;
	if (step == 'L') cur.second--;
	if (step == 'U') cur.first--;
	if (step == 'D') cur.first++;
}

int  main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	pii prd = { 0, 0 };
	int cnt = 0;
	pii cur = { 0, 0 };
	for (int i = 0; i < n; ++i) {
		char step;
		cin >> step;
		pii prev = cur;

		move(cur, step);

		if (dist(cur, prd) < dist(prev, prd)) {
			prd = prev;
			++cnt;
		}
	}
	cout << cnt + 1;
			


	return 0;
}