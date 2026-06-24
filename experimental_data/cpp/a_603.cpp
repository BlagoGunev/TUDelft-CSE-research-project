#include<stdio.h>

#define N 100005

char a[N];

int main()

{

	int n;

	int flagl1,flagr1,flagl0,flagr0,flag,ans,i;

	while(~scanf("%d",&n))

	{

		scanf("%s",a);

		flag = flagl1 = flagr1 = flagl0 = flagr0 = 0;

		char k = a[0];

		ans = 1;

		for(i = 1;i < n;i ++)

		{

			if(a[i] != k)

			{

				k = a[i];

				ans ++;

			}

		}

		for(i = 1;i < n;i ++)

		{

			if(a[i]==a[i-1]&&a[i]==a[i+1])

			{

				flag = 1;

				break;

			}

			if(a[i]==a[i-1]&&a[i]=='0'&&!flagl0)

			{

				flagl0 = i;

			}

			if(a[i]==a[i-1]&&a[i]=='0')

			{

				flagr0 = i;

			}

			if(a[i]==a[i-1]&&a[i]=='1'&&!flagl1)

			{

				flagl1 = i;

			}

			if(a[i]==a[i-1]&&a[i]=='1')

			{

				flagr1 = i;

			}

		}

		if(flag)

		{

			printf("%d\n",ans+2);

		}

		else if(flagl0&&flagl0!=flagr0)

		{

			printf("%d\n",ans+2);

		}

		else if(flagl1&&flagl1!=flagr1)

		{

			printf("%d\n",ans+2);

		}

		else if((flagl1||flagr1)&&(flagl0||flagr0))

		{

			printf("%d\n",ans+2);

		}

		else if(flagl1||flagr1||flagl0||flagr0)

		{

			printf("%d\n",ans+1);

		}

		else

		{

			printf("%d\n",ans);

		}

	}

	return 0;

}