#include <bits/stdc++.h>
#define maxn 1009

using namespace std;

long long v[maxn];
int n, k;
long long d;

long long next(long long _d, long long i) {
	while (i < n && _d >= v[i]) {
		d = max(v[i], d);
		i++;
	}
	return i;
}

int main () {
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", v+i);
	}

	sort(v, v+n);
	long long cont = 0, i = 0;
	d = k;

	while (i < n) {
		//cout << v[i] << ' ' << 2*d << endl;
		while (2*d < v[i]) {
			cont++;
			d *= 2;
			//cout << "  " << v[i] << ' ' << d*2 << endl;
		}
		d = max(v[i], d);
		//cout << "d:" << v[i] << ' '<< d << endl;	
		i = next(2*d, i);
	}

	printf("%lld\n", cont);

	return 0;
}