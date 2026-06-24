#include <cstdio>
#include <algorithm>

using namespace std;

int par, n, sol1, sol2;
bool inside = 0;
char S[256];

int main() {
	scanf("%d", &n);
	scanf("%s", S);

	for (int i = 0; S[i]; ++i) {
		if (S[i] == '(') {
			inside = 1;
		} else if (S[i] == ')') {
			inside = 0;
		} else {
			int cnt = 0;
			while ((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z')) {
				cnt++;
				i++;
			}
			if (cnt) i--;
			if (cnt && inside) sol2++;
			if (!inside) sol1 = max(sol1, cnt);
		}
	}

	printf("%d %d\n", sol1, sol2);
	return 0;
}