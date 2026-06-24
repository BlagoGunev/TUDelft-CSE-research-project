#include <cstdio>

#include <algorithm>

using namespace std;



struct box

{

	int num;

	long long a,b;

};



int T,n;

box t[200010];



bool cmp(box x,box y)

{

	return x.a<y.a;

}



int main()

{

	scanf("%d",&T);

	for (int tt=1;tt<=T;tt++)

	{

		scanf("%d",&n);

		long long suma=0,sumb=0;

		for (int i=1;i<=2*n-1;i++)

		{

			scanf("%d%d",&t[i].a,&t[i].b);

			t[i].num=i;

			suma+=t[i].a; sumb+=t[i].b;

		}

		sort(t+1,t+(2*n-1)+1,cmp);

		long long sum1=0,sum2=0;

		for (int i=1;i<=n;i++)

		{

			sum1+=t[2*i-1].a; sum2+=t[2*i-1].b;

		}

		printf("YES\n");

		if (sum1*2>=suma && sum2*2>=sumb)

		{

			for (int i=1;i<n;i++)

			{

				printf("%d ",t[2*i-1].num);

			}

			printf("%d\n",t[2*n-1].num);

		}

		else if ((suma-sum1+t[2*n-1].a)*2>=suma && (sumb-sum2+t[2*n-1].b)*2>=sumb)

		{

			for (int i=1;i<n;i++)

			{

				printf("%d ",t[2*i].num);

			}

			printf("%d\n",t[2*n-1].num);

		}

		else printf("NO\n");

	}

	return 0;

}