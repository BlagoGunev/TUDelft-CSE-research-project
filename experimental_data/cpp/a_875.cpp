#include<bits/stdc++.h>
using namespace std;

int n, ans, res[2000];

int check(int x) {
	int sum = x;
	while (x) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

int main() {
	scanf("%d", &n);
	for (int i=max(1, n-200); i<=n; i++)
		if (check(i) == n) res[++ans] = i;
	printf("%d\n", ans);
	for (int i=1; i<=ans; i++) printf("%d\n", res[i]);
	return 0;
}