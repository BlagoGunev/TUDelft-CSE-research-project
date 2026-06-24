#include <bits/stdc++.h>

using namespace std;



int main()

{

	int n;

	scanf("%d",&n);

	int f = n/7-(n%7)%4;

	if (f < 0)

	{

		printf("-1\n");

		return 0;

	}

	for (int i = 0; i < ((n%7)%4)*2+(n%7>=4); i++) printf("4");

	for (int i = 0; i < f; i++) printf("7");

	printf("\n");

}