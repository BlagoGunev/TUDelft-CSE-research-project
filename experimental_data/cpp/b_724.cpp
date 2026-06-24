#include<stdio.h>

int a[25][25];

int b[25][25];

int n,m;

int check()

{

	int i,j;

	int f;

	for(i = 1;i <= n;i ++)

	{

		f = 0;

		for(j = 1;j <= m;j ++)

		{

			if(b[i][j]!=j)

			{

				f++;

			}

		}

		if(f > 2)

		{

			return 0;

		}

	}

	return 1;

}

void vv(int x,int y)

{

	int i,j;

	for(i = 1;i <= n;i ++)

	{

		for(j = 1;j <= m;j ++)

		{

			if(j==x)

			{

				b[i][j] = a[i][y];

			}

			else if(j==y)

			{

				b[i][j] = a[i][x];

			}

			else

			{

				b[i][j] = a[i][j];

			}

		}

	}

}

int main()

{

	int i,j,k;

	int f;

	while(~scanf("%d %d",&n,&m))

	{

		f = 0;

		for(i = 1;i <= n;i ++)

		{

			for(j = 1;j <= m;j ++)

			{

				scanf("%d",&a[i][j]);

			}

		}

		vv(0,0);

		if(check())f = 1;

		for(i = 1;i <= m;i++)

		{

			for(j = i+1;j <= m;j ++)

			{

				vv(i,j);

				if(check())

				{

					f = 1;

					break;

				}

			}

			if(f)break;

		}

		puts(f?"YES":"NO");

		

	}

	return 0;

}