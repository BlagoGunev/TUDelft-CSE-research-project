#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n;
	for (scanf("%d",&n);n--;)
	{
		int t;
		scanf("%d",&t);
		int x=t%2020;
		if (x*2021+max((t/2020-x),0)*2020==t) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}