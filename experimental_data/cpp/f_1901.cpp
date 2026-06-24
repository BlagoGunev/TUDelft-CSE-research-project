#include<bits/stdc++.h>
 
using namespace std;
 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
 
#define x first
#define y second
 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
 
template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
	return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
	fore(i, 0, sz(v)) {
		if(i) out << " ";
		out << v[i];
	}
	return out;
}
 
pt operator+ (const pt &a, const pt &b) {
	return {a.x + b.x, a.y + b.y};
}
pt operator- (const pt &a, const pt &b) {
	return {a.x - b.x, a.y - b.y};
}
li operator *(const pt &a, const pt &b) {
	return a.x * 1ll * b.x + a.y * 1ll * b.y;
}
li operator %(const pt &a, const pt &b) {
	return a.x * 1ll * b.y - a.y * 1ll * b.x;
}
 
const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
 
int n;
vector<pt> old, nw;
 
inline bool read() {
	if(!(cin >> n))
		return false;
	old.resize(n);
	nw.resize(n);
	fore (i, 0, n) {
		old[i].x = i;
		cin >> old[i].y;
	}
	fore (i, 0, n) {
		nw[i].x = i;
		cin >> nw[i].y;
	}
	return true;
}
 
inline ld getTr(const pt &a, const pt &b) {
	pt tmp = b - a;
	pt v = {-tmp.y, tmp.x};
	ld c = v * a;
	ld y0 = (c - v.x * 0) / v.y;
	ld y1 = (c - v.x * li(n - 1)) / v.y;
	return (y0 + y1);
}
 
vector<pt> hull(const vector<pt> &ps, int l, int r) {
	vector<pt> h;
	fore (i, l, r) {
		while (sz(h) > 1 && (h[sz(h) - 1] - h[sz(h) - 2]) % (ps[i] - h[sz(h) - 1]) >= 0)
			h.pop_back();
		h.push_back(ps[i]);
	}
	return h;
}
 
inline void solve() {
	vector<ld> maxTr(n - 1, 0);
	fore (t, 0, 2) {
		auto h = hull(old, n / 2, n);
 
		auto best = [&](const pt &p) {
			int l = -1, r = sz(h) - 1;
			while (r - l > 1) {
				int mid = (l + r) >> 1;
				if ((h[mid] - p) % (h[mid + 1] - h[mid]) >= 0)
					l = mid;
				else
					r = mid;
			}
			return h[r].x;
		};
		
		vector<ld> bs(n / 2 + 1, 0);
		for (int i = n / 2 - 1; i >= 0; i--) {
			int j = best(old[i]);
			bs[i] = getTr(old[i], old[j]);
			bs[i] = max(bs[i], bs[i + 1]);
		}
		
		ld lans = 0;
		fore (i, 0, n / 2) {
			int j = best(nw[i]);
			lans = max(lans, getTr(nw[i], old[j]));
			maxTr[i] = max({maxTr[i], lans, bs[i + 1]});
		}
		
		reverse(all(old));
		reverse(all(nw));
		swap(old, nw);
		fore (i, 0, n)
			old[i].x = nw[i].x = i;
		
		reverse(all(maxTr));
	}
			
	maxTr.push_back(maxTr.back());
	cout << maxTr << endl;
}
 
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(12);
	
	if(read()) {
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}