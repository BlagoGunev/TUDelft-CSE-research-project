#pragma comment(linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

#define lld I64d

const int maxn = 1000010;
char s[maxn];

int main() {
#ifdef ONLINE_JUDGE
    //freopen("revolutions.in", "r", stdin);
    //freopen("revolutions.out", "w", stdout);
#endif
	int n;
	scanf("%s", s);
	n = strlen(s);
	int numb = 0;
	int pos = n - 1;
	while (pos >= 0 && s[pos] == 'M') {
		pos--;
	}
	while (pos >= 0 && s[pos] == 'F') {
		numb++;
		pos--;
	}
	if (pos == -1) {
		printf("0");
		return 0;
	}
	int ans = numb;
	int last_ans = 0;
	for (int i = pos - 1; i >= 0; i--) {
		if (s[i] == 'F') {
			numb++;
		} else {
			last_ans = max(0, last_ans + 2 - pos + i);
			ans = numb + last_ans;
			pos = i;
		}
	}
	printf("%d", ans);
	return 0;
}