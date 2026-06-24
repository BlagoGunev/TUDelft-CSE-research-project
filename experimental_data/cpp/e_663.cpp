#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <list>
#include <numeric>
#include <cassert>

using namespace std;

using intl = long long;
using ll = long long;

const int mxn = 100006;
const int mxl = 1 << 20;

int n, m;
char s[mxn];
int t[mxn];

ll a[mxl];
ll b[mxl];
ll c[mxl];

void fwt(ll *a, int n) {
	for(int i = 2; i <= n; i <<= 1)
		for(int j = 0; j < n; j += i) {
			ll *l = a + j, *r = a + j + (i >> 1);
			for(int k = 0; k < (i >> 1); k ++)
				*l += *r, *r = *l - (*r << 1), ++l, ++r;
}}

void multi(intl a[], intl b[], intl c[], int n)
{
	fwt(a, n);
	fwt(b, n);
	for(int i = 0; i < n; i ++)
		c[i] = a[i] * b[i];
	fwt(c, n);
	for(int i = 0; i < n; i ++)
		c[i] = c[i] / n;
}

void EXEC() {
	cin >> m >> n;
	for (int i = 0; i < m; ++i) {
		scanf("%s", s);
		for (int j = 0; j < n; ++j)
			t[j] |= (s[j] - '0') << i;
	}
	
	for (int i = 0; i < n; ++i)
		++a[t[i]];
	
	int l = 1 << m;
	for (int i = 0; i < l; ++i)
		b[i] = min(__builtin_popcount(i), m - __builtin_popcount(i));
	
	multi(a, b, c, l);
	
	printf("%lld\n", *min_element(c, c + l));
}

int main() {
	EXEC();
	return 0;
}