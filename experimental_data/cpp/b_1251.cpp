#include <bits/stdc++.h>
using namespace std;

int q, num[55], num0, num1;
char s[55];

int main() {
	scanf("%d", &q);
	while(q--) {
		int n, cnt = 0;
		num0 = num1 = 0;
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%s", s+1);
			int m = strlen(s+1);
			num[++cnt] = m;
			for(int i = 1;i <= m; i++) {
				if(s[i] == '1') num1++;
				if(s[i] == '0') num0++;
			}
		}
		bool ok = 0;
		int i;
		for(i = 1;i <= cnt; i++) {
			if(num[i] % 2 == 1) ok = 1;
		}
		
		if(!ok) {
			if(num0 % 2 == 1 && num1 % 2 == 1) {
				printf("%d\n", n-1);
				continue;
			}
		}
		printf("%d\n", n);
	}
}