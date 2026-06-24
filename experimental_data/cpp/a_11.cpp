#include <stdio.h>
#include <cstring>

int a[2010], n, d, k;

int main()
{
	while(scanf("%d%d", &n, &d) != EOF)
	{
		for(int i=0; i<n; ++i) scanf("%d", &a[i]);

		int ans = 0;
		for(int i=1; i<n; ++i)
		{
			if(a[i] <= a[i-1])
			{
				k = (a[i-1] - a[i]) / d + 1;
				a[i] = a[i] + d * k;
				ans += k;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}