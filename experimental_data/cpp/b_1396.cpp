#include<bits/stdc++.h>
#define REP(x, n) for(int x = 0; x < n; ++x)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	REP(x, t) {
		int i, maxO = 0, ilosc = 0;
		cin >> i;
		REP(x, i) {
			int pom;
			cin >> pom;
			maxO = max(maxO, pom);
			ilosc += pom;
		}
		if(maxO > ilosc/2 || ilosc%2) cout << "T\n";
		else cout << "HL\n";
	}
}