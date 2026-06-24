#include <bits/stdc++.h>
using namespace std;

#define int long long
#define form2(i, a, b) for (int i = (a); i < (b); ++i)
#define ford2(i, a, b) for (int i = (a-1); i >= (b); --i)
#define form(i, n) form2(i, 0, n)
#define ford(i, n) ford2(i, n, 0)

#define chmax(x, v) x = max(x, (v))
#define chmin(x, v) x = min(x, (v))
#define fi first
#define se second

const long long BIG = 1000000000000000000LL;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

void solve();
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}

const int lgb = 62;
int n;
int kx[lgb];
const int borne = (int)(1e5) + 5;
vector<int> a;

int tester(int dep)
{
	vector<int> par(n, -1);
	vector<int> mdis(n, BIG);
	mdis[dep] = 0;
	queue<int> bfs;
	bfs.push(dep);
	int rep = BIG;
	while (! bfs.empty()) {
		int nod = bfs.front();
		bfs.pop();
		form(oth, n) if (oth != nod && oth != par[nod]) {
			if ((a[nod] & a[oth]) == 0) continue;
			if (mdis[oth] != BIG) {
				chmin(rep, mdis[nod] + mdis[oth] + 1);
				continue;
			}
			mdis[oth] = mdis[nod]+1;
			par[oth] = nod;
			bfs.push(oth);
		}
	}
	return rep;
}
void solve()
{
	cin >> n;
	form(osef, n) {
		int x; cin >> x;
		if (x == 0) continue;
		int el = a.size();
		a.push_back(x);
		form(iBit, lgb) {
			if (a[el] & (1LL << iBit)) {
				++kx[iBit];
				if (kx[iBit] == 3) {
					cout << "3\n";
					return;
				}
			}
		}
	}
	n = a.size();

	int rep = BIG;
	form(i, n) chmin(rep, tester(i));
	if (rep == BIG) rep = -1;
	cout << rep << "\n";

}