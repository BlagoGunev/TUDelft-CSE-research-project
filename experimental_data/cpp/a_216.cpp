#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) ((int)(x).size())
#define rep(i,l,r) for(int i=(l);i<(r);++i)
//-------head-------
int calc(int n) {
	return n * (n + 1) >> 1;
}
int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d", calc(a + b + c - 2) - calc(a - 1) - calc(b - 1) - calc(c - 1));
	return 0;
}