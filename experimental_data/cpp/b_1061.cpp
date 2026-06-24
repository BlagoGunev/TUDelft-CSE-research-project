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

const int MAXN = 100000;
int n, m;
int arr[MAXN + 5];
void readInput() {
	gi(n);
	gi(m);
	for (int i = 1; i <= n; ++i) {
		gi(arr[i]);
	}
	sort(arr + 1, arr + n + 1);
}

void solve() {
	int lastHeight = 0;
	int lastPos = 0;
	int totalDiff = 0;
	int sisa = 0;
	LL sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += arr[i];
		if (!(i == n || arr[i] != arr[i + 1])) {
			continue;
		}
		totalDiff += arr[i] - lastHeight;
		
		int occ = i - lastPos;
		sisa += occ;
		
		totalDiff = max(0, totalDiff - occ);
		
		lastHeight = arr[i];
		lastPos = i;
	}
	sisa += totalDiff;
	
	cout << sum - sisa << endl;
}

int main() {
	readInput();
	solve();
	return 0;
}