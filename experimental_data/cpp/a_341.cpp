#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;

ULL ans, sum;
int n;
int a[100005];

ULL gcd(ULL a, ULL b) {
	return b == 0? a : gcd(b, a % b);
}

int main() {

#ifdef FIN
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int pr = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i];
		sum += (ULL)i * (a[i] - pr);
		ans += sum * 2;
		pr = a[i];
	}
	ULL g = gcd(ans, n);
	cout << ans / g << " " << n / g;

	return 0;
}