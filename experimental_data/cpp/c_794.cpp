#include <cstdio>
#include <vector>
#include <algorithm>
#include "memory.h"
#include <string>
#include <set>

using namespace std;

char buf1[1000000], buf2[1000000];

int A[30], B[30];

int main() {
	scanf("%s%s", buf1, buf2);
	int n = strlen(buf1);
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	for(int i = 0; i < n; i++) { A[buf1[i] - 'a']++; B[buf2[i] - 'a']++; }
	A[28] = B[28] = 1;
	{
		int q = 27;
		while (A[q] == 0) q--;
		for(int i = (n+1)/2; i < n; i++) { A[q]--; while (A[q] == 0) q--; }
		q = 0;
		while (B[q] == 0) q++;
		for(int i = n/2; i < n; i++) { B[q]--; while (B[q] == 0) q++; }
		int n1 = 0, n2 = 0;
		for(int i = 0; i < 27; i++) n1 += A[i];
		for(int i = 0; i < 27; i++) n2 += B[i];
//		printf("%d %d %d\n", n, n1, n2);
	}
	int first = 0;
	while (A[first] == 0) first++;
	int last = 26;
	while (B[last] == 0) last--;
	B[0]++;
	string ans(n, ' ');
	int ansb = n-1;
	bool b = true;
	for(int i = 0; i < n; i++) {
		if (b && first < last) {
			if (i % 2 == 0) { ans[i] = first + 'a'; A[first]--; while (A[first] == 0) first++; }
			else { ans[i] = last + 'a'; B[last]--; while (B[last] == 0) last--; }
		} else {
			if (b) { B[0]--; A[0]++; last = 0; while (B[last] == 0) last++; first = 27; while (A[first] == 0) first--; b = false; }
//			printf("%d %d %d %d\n", i, ansb, first, last);
			if (i % 2 == 0) { ans[ansb] = first + 'a'; A[first]--; while (A[first] == 0) first--; }
			else { ans[ansb] = last + 'a'; B[last]--; while (B[last] == 0) last++; }
			ansb--;
		}
	}
	printf("%s\n", ans.c_str());
    return 0;
}