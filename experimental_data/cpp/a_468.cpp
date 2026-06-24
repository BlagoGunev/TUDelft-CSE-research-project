#include<bits/stdc++.h>

using namespace std;



main()

{

	

	int n;

	

	scanf("%d",&n);

	

	if(n < 4)

	  printf("NO");

	else if(n == 4)

	{

		

		printf("YES\n");

		printf("2 * 3 = 6\n");

		printf("6 * 4 = 24\n");

		printf("24 * 1 = 24\n");

		

	}

	else if (n == 5)

	{

		

		printf("YES\n");

		printf("5 - 1 = 4\n");

		printf("4 - 2 = 2\n");

		printf("2 * 3 = 6\n");

		printf("6 * 4 = 24\n");

		

	}

	else

	{

		

		printf("YES\n");

		

		printf("2 * 3 = 6\n");

		printf("6 * 4 = 24\n");

		

		printf("%d - %d = 1\n",n,n-1);

		printf("1 - 1 = 0\n");

		for(int i = 5;i < n - 1;i++)

		  printf("%d * 0 = 0\n",i);

		printf("24 + 0 = 24");

		

	}

	

}