#include<bits/stdc++.h>
using std::vector;
using std::pair;
using lint = long long int;
using pii = std::pair<int, int>;

int main(void){
	int n, x;
	scanf("%d%d", &n, &x);
	int sum = n-1;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		sum += a;
	}
	if (sum == x) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}