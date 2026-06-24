#include <bits/stdc++.h>
using namespace std;

#define LL 					long long
#define DB					double
#define ULL 				unsigned long long
#define PII 				pair<int,int>

#define eb					emplace_back
#define mp					make_pair
#define fi 					first
#define se 					second
#define psb 				push_back
#define ppb 				pop_back
#define endln 				printf("\n")

#define ALL(x)			 	(x).begin(),(x).end()
#define SZ(x)				(int) (x).size()

#define SETMIN(x)			memset((x), -1, sizeof (x))
#define SETNUL(x)			memset((x),  0, sizeof (x))
#define gc					getchar_unlocked

#ifndef getchar_unlocked
#define getchar_unlocked 	getchar
#endif

const int inf = 1e9 + 5;
const LL infll = 1e18+5;
const int mod = 1e9 + 7;

template <typename T>
void gi(T &ret) {
	ret = 0; char inp = gc(); bool isNeg = 0;
	while (inp < '0' || inp > '9') { 
		if (inp == '-') isNeg = 1; 
		inp = gc();
	}
	while ('0' <= inp && inp <= '9') {
		ret = (ret << 3) + (ret << 1) + (inp - '0');
		inp = gc();
	}
	if (isNeg) ret = -ret;
}

const LL mods = 1000000007LL;
struct M {
	int x; 
	M (LL num) {
		if (num >= mods || num <= -mods) {
			num %= mods;
		}
		if (num < 0) {
			num += mods;
		}
		x = num;
	}
	M () {
		x = 0;
	}
	M operator + (const M &other) const {
		return M(x + other.x);
	}
	M operator - (const M &other) const {
		return M(x - other.x);
	}
	M operator * (const M &other) const {
		return M((LL) x * other.x);
	}
	M operator - () const {
		return M(-x);
	}
};

const int MAXN = 100000;
//0 mulai, 1 berakhir
vector <pair<int, PII>> sweep;
int n;
LL x, y;
int l[MAXN + 5], r[MAXN + 5];
void readInput() {
	gi(n);gi(x);gi(y);
	for (int i = 1; i <= n; ++i) {
		gi(l[i]);gi(r[i]);
		sweep.psb(mp(l[i], mp(0, i)));
		sweep.psb(mp(r[i], mp(1, i)));
	}
	sort(ALL(sweep));
}

priority_queue<int> tv;
void solve() {
	M ans;
	for (auto line : sweep) {
		//in
		if (line.se.fi == 0) {
			int id = line.se.se;
			if (tv.empty()) {
				//rent a new tv;
				ans = ans + x;
				ans = ans + M(y) * (r[id] - l[id]);
			} else {
				//reuse or what?
				int target = tv.top();
				tv.pop();
				if ((LL) (l[id] - target) * y < x) {
					//reuse
					ans = ans + M(y) * (l[id] - target);
					ans = ans + M(y) * (r[id] - l[id]);
				} else {
					//rent a new tv;
					ans = ans + x;
					ans = ans + M(y) * (r[id] - l[id]);				
				}
			}
		} else {			//end
			tv.push(line.fi);
		}
	}
	cout << ans.x << endl;
}

int main() {
	readInput();
	solve();
	return 0;
}