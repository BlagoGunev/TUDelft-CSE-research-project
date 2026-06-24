#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int Reduction(string S) {
	bool one = 0;
	int zero = 1e9;
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == '1') one = 1;
		else zero = min(zero, i);
	}
	if (!one) return 0;

	int a = 1;
	while (a < S.size()) {
		if (S[a] == '0') {
			a++;
			continue;
		}
		if (S[a - 1] == '1' || S[a] == '0') {
			a++;
			continue;
		}

		if (a + 1 < S.size()) S[a + 1] ^= 1;
		S[a] = '0';
		while (zero < S.size() && S[zero] == '1') zero++;

		S[zero] = '1';
		if (zero + 1 < S.size()) S[zero + 1] = '1', zero++;
		a++;
	}

	int cnt = 0;
	for (int i = 0; i < S.size(); ++i) if (S[i] == '0') return i;
	return S.size();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int _T;
	cin >> _T;
	while (_T--) {
		int N;
		cin >> N;
		string A, B;
		cin >> A >> B;
		int a = Reduction(A), b = Reduction(B);
		a++; b++;
		cout << ((a / 2) == (b / 2) ? "YES" : "NO") << '\n';
	}
	return 0;
}