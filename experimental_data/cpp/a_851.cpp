#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

const int N = 1e5 + 5;
const int inf = 1791791791;

int main() {
	long long n, k, t;
	scanf("%lld %lld %lld", &n, &k, &t);
	if (t <= k) printf("%lld", t);
	else if (t >= n) printf("%lld", n+k-t);
	else printf("%lld", k);
	printf("\n");
    return 0;
}