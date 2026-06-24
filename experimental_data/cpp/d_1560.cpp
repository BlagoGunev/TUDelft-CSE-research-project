#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;

struct data {
	int num[25], len;
	data () {
		memset(num, 0, sizeof num);
		len = 0;
	}
}a, Pow[100];

int t, n, ans;

int main() {
	for(LL i = 1, x, j = 0; j <= 60; i <<= 1, j++) {
		x = i;
		while(x) {
			Pow[j].num[++Pow[j].len] = x % 10;
			x /= 10;
		}
		reverse(Pow[j].num + 1, Pow[j].num + 1 + Pow[j].len);
	}
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= a.len; i++) a.num[i] = 0;
		a.len = 0;
		while(n) {
			a.num[++a.len] = n % 10;
			n /= 10;
		}
		reverse(a.num + 1, a.num + 1 + a.len);
		ans = 0x3f741ae9;
		for(int i = 0; i <= 60; i++) {
			for(int j = 1, k = 1; j <= Pow[i].len; j++) {
				int f = 0;
				for(; k <= a.len; k++)
					if(a.num[k] == Pow[i].num[j]) {
						f = 1, k++; break;
					}
				if(!f) {
					ans = min(ans, a.len + Pow[i].len - ((j - 1) << 1));
					break;
				}
				if(f && j == Pow[i].len)
					ans = min(ans, a.len + Pow[i].len - (j << 1));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}