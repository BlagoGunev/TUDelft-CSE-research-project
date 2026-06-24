#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define MULTI_TEST_CASE 1 // modify
#define DEBUG if (1) // modify
using namespace std;

int test, n, k;

int gcd(int number1, int number2) {
	if (!number1 || !number2) return max(number1,number2);
	return gcd(max(number1,number2)%min(number1,number2),min(number1,number2));
}

int lcm(int number1, int number2) {
	return (number1*number2)/gcd(number1,number2);
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if (MULTI_TEST_CASE) cin >> test;
	else test = 1;
	while (test--) {
		cin >> n >> k;
		if (k <= 4*n-4) cout << (k+1)/2 << endl;
		else if (k == 4*n-3) cout << n+n-1 << endl;
		else cout << 2*n << endl;
	}
}