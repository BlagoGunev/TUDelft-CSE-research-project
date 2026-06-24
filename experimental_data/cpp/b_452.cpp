#include<bits/stdc++.h>//图、构造 

using namespace std;

typedef long long ll;

double dis(int x1, int y1, int x2, int y2)

{

	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

}

int main()

{

	int n, m;

	cin >> n >> m;

	if(n == 0)

	{

		printf("0 1\n");

		printf("0 %d\n", m);

		printf("0 0\n");

		printf("0 %d\n", m-1);

	}

	else if(m == 0)

	{

		printf("1 0\n");

		printf("%d 0\n", n);

		printf("0 0\n");

		printf("%d 0\n", n-1);

	}

	else

	{

		if(m > n)

		{

			if(dis(0, 0, n, m)+m >= 2*dis(0, 0, n-1, m))

			{

				printf("0 0\n");

		  	    printf("%d %d\n", n, m);

			    printf("%d 0\n", n);

			    printf("0 %d\n", m);

			}

			else

			{

				printf("1 0\n");

		  	    printf("%d %d\n", n, m);

			    printf("0 0\n");

			    printf("%d %d\n", n-1, m);

			}

		}

		else

		{

			if(dis(0, 0, n, m)+n >= 2*dis(0, 1, n, m))

			{

				printf("0 0\n");

			    printf("%d %d\n", n, m);

			    printf("0 %d\n", m);

		    	printf("%d 0\n", n);

			}

			else

			{

				printf("0 1\n");

		  	    printf("%d %d\n", n, m);

			    printf("0 0\n");

			    printf("%d %d\n", n, m-1);

			}

		}

	}

	return 0;

}