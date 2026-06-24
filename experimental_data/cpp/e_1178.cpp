#include <bits/stdc++.h>
using namespace std;


// xx...yy
// ..x(xy)y..

char s[1000006];
char t[1000005];
int main()
{
	scanf("%s", s);
	int n = strlen(s);
	int i = 0;
	int j = n-2;
	int cnt = 0;
	while (i+1 < j) {
		if (s[i] == s[j] || s[i] == s[j+1]) {
			t[cnt++] = s[i];
		} else {
			t[cnt++] = s[i+1];
		}
		i += 2;
		j-=2;
	}
	int rev = cnt;
	if (j+1 >= i) {
		t[cnt++] = s[i];
	}
	for (int i = 0; i < rev; i++) {
		t[cnt++] = t[rev-1-i];
	}
	t[cnt] = 0;
	printf("%s\n", t);
}