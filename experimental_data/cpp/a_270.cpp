#include <bits/stdc++.h>



using namespace std;



typedef long long l64;

l64 gcd(l64 a, l64 b) { return b ? gcd(b, a%b) : a; }





int main() { 

	int n, a, g, b;

	cin >> n;

	while (n--) {

		cin >> a;

		g = gcd(a, 180);

		a = a / g;

		b = 180 / g;

		if (abs(b - a) > 0 && abs(b - a) <= 2)cout << "YES\n";

		else cout << "NO\n";

	}

}