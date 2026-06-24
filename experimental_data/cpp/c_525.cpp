//akartik80
 
#include <iostream>
#include <cstdio>
#include <algorithm>
 
#define get getchar//_unlocked
#define put putchar_unlocked
#define li long int
#define ll long long int
#define pb push_back
#define mp make_pair
#define pd(x) printf("%d", x)
#define pdn(x) printf("%d\n", x)
#define pld(x) printf("%ld", x)
#define pldn(x) printf("%ld\n", x)
#define plld(x) printf("%lld", x)
#define plldn(x) printf("%lld\n", x)
#define sd(x) scanf("%d", &x)
#define sld(x) scanf("%ld", &x)
#define slld(x) scanf("%lld", &x)
#define ss(x) scanf("%s", x)
#define ps(x) printf("%s", x)
#define psn(x) printf("%s\n", x)
 
using namespace std;
 
inline int scan()
{
	int n = 0, sign = 1, ch = get();
 
	while (ch < 48 || ch > 57) {
		if (ch == '-') {
			sign = -1;
		}
 
		ch = get();
	}
 
	while (ch >= 48 && ch <= 57) {
		n = (n << 3) + (n << 1) + ch - 48;
		ch = get();
	}
 
	return n * sign;
}
 
int main()
{
	int n, i;
	ll temp1 = 0, ans = 0;

	n = scan();

	int a[n];

	for (i = 0; i < n; i++) {
		a[i] = scan();
	}

	sort(a, a + n);

	for (i = n - 1; i > 0; i--) {
		if (a[i] == a[i - 1] || a[i] - 1 == a[i - 1]) {
			if (temp1 == 0) {
				temp1 = a[i - 1];
				i--;
			} else {
				temp1 *= a[i - 1];
				i--;
				ans += temp1;
				temp1 = 0;
			}
		}
	}

	plldn(ans);
}