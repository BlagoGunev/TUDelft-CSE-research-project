#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<algorithm>



using namespace std;



const int maxn=100010;



int n,m,cnt,z[maxn];



pair<int,int> y[maxn<<1];



int main()

{

	scanf("%d%d",&n,&m);

	for (int a=1;a<=m;a++)

		scanf("%d",&z[a]);

	long long sum=0;

	for (int a=2;a<=m;a++)

	{

		sum+=abs(z[a]-z[a-1]);

		if (z[a]==z[a-1]) continue;

		y[++cnt]=make_pair(z[a],z[a-1]);

		y[++cnt]=make_pair(z[a-1],z[a]);

	}

	sort(y+1,y+cnt+1);

	long long ans=sum;

	for (int a=1;a<=cnt;)

	{

		int b=a;

		while (b<=cnt && y[b].first==y[a].first)

			b++;

		long long delta=0;

		int mid=(a+b-1)>>1;

		for (int c=a;c<b;c++)

			delta+=abs(y[mid].second-(y[c].second==y[a].first ? y[mid].second : y[c].second))-abs(y[a].first-y[c].second);

		ans=min(ans,sum+delta);

		a=b;

	}

	printf("%I64d\n",ans); 



	return 0;

}