#include <bits/stdc++.h>
using namespace std;

int a, b;

int gcd(int a, int b) {
	while(a && b) {
		(a > b) ? (a %= b) : (b %= a);
	}
	return a + b;
}

void solve() {
	if(abs(a/gcd(a, b) - b/gcd(a, b)) == 1) {
		puts("Equal");
		return;
	}
	if(a > b) {
		puts("Masha");
		return;
	}
	puts("Dasha");
}

int main (int argc, char *argv[])
{
	scanf("%d%d", &a, &b);
	solve();
	return 0;
}