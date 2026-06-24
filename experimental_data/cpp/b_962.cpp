#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
char p[201000];
int n, A, B, r;
int main() {
	int i;
	scanf("%d%d%d", &n, &A, &B);
	scanf("%s", p);
	int s = 0;
	p[n] = '*';
	for (i = 0; i <= n; i++) {
		if (p[i] == '*') {
			if (A > B)swap(A, B);
			int tB = min(B, (s + 1) / 2);
			int tA = min(A, s / 2);
			B -= tB, A -= tA;
			r += tA + tB;
			s = 0;
		}
		else {
			s++;
		}
	}
	printf("%d\n", r);
}