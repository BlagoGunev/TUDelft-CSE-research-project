#include "assert.h"
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

ll terms[50];

bool check(ll A, ll B, ll M) {
	ll origB = B;
	if (A > B) return false;
	if (A == B) {
		printf("1 %lld\n", A);
		return true;
	}

	int nterms = 1;
	ll top = A + 1;
	while (top <= B) {
		nterms++;
		top <<= 1;
	}
	// fprintf(stderr, "nterms = %d\n", nterms);
	B -= (top >> 1);
	assert(B >= 0);
	for (int i = 1; i < nterms; ++i) {
		int shift = max(0, nterms - i - 2);

		ll left = B / (1ULL << shift);
		ll added = min(left, M - 1);
		terms[i] = added;
		B -= added << shift;
		assert(B >= 0);
		// fprintf(stderr, "%d: %lld\n", i, added);
	}
	if (B != 0) return false;

	printf("%d %lld", nterms, A);
	ll sum = A, nxt;
	for (int i = 1; i < nterms; ++i) {
		assert(0 <= terms[i] && terms[i] < M);
		nxt = sum + terms[i] + 1;
		printf(" %lld", nxt);
		sum += nxt;
	}
	assert(nxt == origB);
	printf("\n");

	return true;
}

int main() {
	int Q;
	ll A, B, M;
	scanf("%d", &Q);
	for (int q = 0; q < Q; ++q) {
		scanf("%lld%lld%lld", &A, &B, &M);
		if (!check(A, B, M)) {
			printf("-1\n");
		}
	}
	return 0;
}