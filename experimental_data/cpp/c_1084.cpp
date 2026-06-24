#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+69;
char s[MAXN];
using ll = long long int;
const ll MOD = 1e9+7;
ll w = 0;
int main() {
	scanf("%s", s);
	int c = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == 'a') {
			c++;
			// printf("'a' %d\n", c);
		} else if (s[i] == 'b') {
			// printf("'b' %d w=%lld\n", c, w);
			if (c) {
				w *= c+1;
				w %= MOD;
				w += c;
				w %= MOD;
				c = 0;
			}
		}
	}
	if (c) {
		w *= c+1;
		w %= MOD;
		w += c;
		w %= MOD;
		c = 0;
	}
	printf("%lld\n", w);
}