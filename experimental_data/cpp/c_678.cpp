#include <bits/stdc++.h>



using namespace std;



int64_t gcd(int64_t a, int64_t b) { return b == 0 ? a : gcd(b, a%b); }

int64_t lcm(int64_t a, int64_t b) { return a / gcd(a, b) * b; }



int main() {

	int64_t N, A, B, P, Q;

	cin >> N >> A >> B >> P >> Q;

	int64_t divbyboth = N/lcm(A,B), divbya = N/A-divbyboth, divbyb = N/B-divbyboth, ans = divbya*P+divbyb*Q;

	if (P > Q) {

		cout << ans + divbyboth*P << endl;

	} else {

		cout << ans + divbyboth*Q << endl;

	}

}