#include<bits/stdc++.h>

using namespace std;



int n,m;

int c[100010],a1[100010],b1[100010],a2[100010],b2[100010];

int a3[100010],b3[100010],a4[100010],b4[100010];



void work()

{

	for (int i=n;i>=1;i--)

	{

		if (a1[i]<=c[i]&&c[i]<=b1[i]) 

		{

			a3[i]=a2[i];

			b3[i]=b2[i];

			if (c[i]<a4[i+1]||b4[i+1]<c[i])

			{

				a3[i]=max(a3[i],a3[i+1]);

				b3[i]=min(b3[i],b3[i+1]);

			}

		} 

		else 

		{

			a3[i]=m;

			b3[i]=0;

		}

		

		if (a2[i]<=c[i]&&c[i]<=b2[i]) 

		{

			a4[i]=a1[i];

			b4[i]=b1[i];

			if (c[i]<a3[i+1]||b3[i+1]<c[i])

			{

				a4[i]=max(a4[i],a4[i+1]);

				b4[i]=min(b4[i],b4[i+1]);

			}

		} 

		else

		{

			a4[i]=m;

			b4[i]=0;

		}

	}

}



int main() 

{

	scanf("%d%d",&n,&m);

	for (int i=1;i<=n;i++)

		scanf("%d%d%d%d%d",&c[i],&a1[i],&b1[i],&a2[i],&b2[i]);

	a3[n+1]=0;

	b3[n+1]=m;

	a4[n+1]=0;

	b4[n+1]=m;

	work();

	if (a3[1]>0&&a4[1]>0)

		puts("No");

	else

	{

	    

		puts("Yes");

		int s1=0,s2=0;

		for (int i=1;i<=n;i++) 

		{

			if (a3[i]<=s2&&s2<=b3[i])

			{

				s1=c[i];

				printf("0 ");

			}

			else if (a4[i]<=s1&&s1<=b4[i])

			{

				s2=c[i];

				printf("1 ");

			}

		}

	}

	return 0;

}