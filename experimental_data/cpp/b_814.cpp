//#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define IN(a, b, x) (a<=x&&x<b)
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define INF (1LL<<30)
#define LLINF (1LL<<60)
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int a[1010], b[1010], p[1010], c[1010], d[1010], n;
bool check(){
	memset(d, 0, sizeof(d));
	REP(i, n) {
		d[p[i]]++;
	}
	bool ans = true;
	FOR(i, 1, n+1) {
		if(d[i] != 1) ans = false;
	}
	return ans;
}
signed main(void)
{
	cin >> n;
	REP(i, n) cin >> a[i], a[i]--;
	REP(i, n) cin >> b[i], b[i]--;

	int  cnt = 0, idx1 = -1, idx2 = -1;
	VI v;
	REP(i, n) {
		if(a[i] != b[i]) {
			cnt++;
			if(idx1 == -1) idx1 = i;
			else idx2 = i;
		}
		else if(c[a[i]]) {
			idx1 = i;
			cnt = 1;
		} else {
			c[a[i]] = 1;
			p[i] = a[i]+1;
		}
	}

	if(cnt == -1) {
		REP(i, n) {
			if(c[i] == 0) {}
		}
		REP(i, n) {
			cout << p[i] << " ";
		}
		cout << endl;
	}

	if(cnt == 1) {
		REP(i, n) {
			if(c[i] == 0) {
				p[idx1] = i+1;
			}
		}
		REP(i, n) {
			cout << p[i] << " ";
		}
		cout << endl;
		return 0;
	}

	p[idx1] = a[idx1]+1;
	p[idx2] = b[idx2]+1;
	//REP(i, n) cout << p[i] << " ";
	if(check()) {
		REP(i, n) {
			cout << p[i] << " ";
		}
		cout << endl;
		return 0;
	}

	p[idx1] = b[idx1]+1;
	p[idx2] = a[idx2]+1;
	//REP(i, n) cout << p[i] << " ";
	if(check()) {
		REP(i, n) {
			cout << p[i] << " ";
		}
		cout << endl;
		return 0;
	}

	return 0;
}