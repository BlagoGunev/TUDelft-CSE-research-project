#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int ce = 0, co = 0;
	for(int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		if(x & 1) co++;
		else ce++;
	}
	int t = n - k ;
	if(t == 0)
	{
		if(co & 1) puts("Stannis");
		else puts("Daenerys");
	}
	else
	{
		if(ce <= t / 2)
		{
			co -= ce;
			t &= 1;
			if((co & 1)^t) puts("Stannis");
			else puts("Daenerys");
		}
		else if(co <= t / 2)
			puts("Daenerys");
		else if(t & 1) puts("Stannis");
		else puts("Daenerys");
	}
}