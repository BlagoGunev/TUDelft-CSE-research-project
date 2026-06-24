#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;

#define FOR(i,a,n) for (int i = (a); i < (n); ++i)
#define FORE(i,a,n) for (int i = (a); i <= (n); ++i)
#define FORD(i,a,b) for (int i = (a); i >= (b); --i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define LL long long
#define FIR(n) REP(i,n)
#define FJR(n) REP(j,n)
#define ALL(v) v.begin(), v.end()

#define FI FIR(n)
#define FJ FJR(n)
#define FR(i,a) FOR(i,a,n)
#define REPN(i) REP(i,n)

#define GI(n) scanf("%d", &n)
#define GI2(n,m) scanf("%d %d", &n, &m)

LL a[100500];
LL B;
int n, k;

int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "rt", stdin);
#endif

	int t;
	GI2(n, k);
	cin >> B;
	FI {
		GI(t); a[i] = t;
	}

	priority_queue<int, vector<int>, greater<int> > q;

	int res = n-1;
	LL s = 0;
	FIR(k-1) {
		q.push(a[n-2-i]);
		s += a[n-2-i];
	}

	FORD(i, n-1-k, 0) {
		if (s + a[i] > B)
			res = i;
		
		if (k > 1 && q.top() < a[i]) {
			s -= q.top();
			q.pop();
			q.push(a[i]);
			s += a[i];
		}
	}
	
	cout << res +1 << endl;
}