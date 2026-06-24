#include <cstdio>

#include <cstring>

#include <cstdlib>

#include <cmath>

#include <algorithm>

using namespace std;



int c, d, n, m, k;



int main()

{

	scanf("%d%d", &c, &d);

	scanf("%d%d", &n, &m);

	scanf("%d", &k);

	int t = n * m - k;

	if(t < 0) printf("0\n");

	else

	{

		int ans1 = (t / n) * c;

		if(t % n) ans1 += c;

		int ans2 = t * d;

		int ans3 = (t / n) * c + (t % n) * d;

		printf("%d\n", min(ans1, min(ans2, ans3)));

	}

}