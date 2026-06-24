#include <bits/stdc++.h>
using namespace std;
int N, M[17], R[17], d1, d2, maxi = 1e5;
int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &M[i]), maxi = max(maxi, M[i]);
	for(int i = 0; i < N; i++) scanf("%d", &R[i]);

	for(int D = 0; D < maxi; D++)
	{
		int ok = 0;
		for(int i = 0; i < N; i++)
		{
			if(D % M[i] == R[i]) ok = 1;
		}

		if(ok) d1++;
		else d2++;
	}

	double ans = (d1 * 100) / (double) (d1 + d2);
	ans = (ans / 100.0);
	printf("%7f", ans);
}