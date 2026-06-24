#include<set>

#include<map>

#include<map>

#include<queue>

#include<stack>

#include<cstdio>

#include<cstdlib>

#include<vector>

#include<cstring>

#include<iostream>

#include<algorithm>

#define eps 1e-9

#define INF 1e9

#define hlq 100000007

#define MAXN 200000

using namespace std;



pair<int,int>q;

void get(int &v)

{

	char c;

	while((c=getchar())!=EOF&&isdigit(c)==0);

	v=c-'0';

	while((c=getchar())!=EOF&&isdigit(c))

		v=(v<<3)+(v<<1)+c-'0';

	return ;

}

int get()

{

	int v;

	char c;

	while((c=getchar())!=EOF&&isdigit(c)==0);

	v=c-'0';

	while((c=getchar())!=EOF&&isdigit(c))

		v=(v<<3)+(v<<1)+c-'0';

	return v;

}

int a[MAXN+70],n;

long long S[MAXN+70];

long long SS(int i,int j){return (S[i]-S[i-j-1])+(S[n]-S[n-j]);}

double mean(int i,int j){return SS(i,j)/((j<<1)+1.0);}

int binary_search(int pos,int l,int r)

{

	int mid;

	while(l<r)

	{

		mid=(l+r)>>1;

		if((SS(pos,mid)<<1)>(a[pos-mid-1]+a[n-mid])*(mid*2+1LL))

			r=mid;

		else

			l=mid+1;

	}

	return l;

}

int main()

{

	int i,p;

	double ans=0,t;

	q=make_pair(1,0);

	for(get(n),i=1;i<=n;i++)

		get(a[i]);

	sort(a+1,a+n+1);

	for(i=1;i<=n;i++)

		S[i]=S[i-1]+a[i];

	for(i=1;i<=n;i++)

	{

		p=binary_search(i,0,min(i-1,n-i));

		t=mean(i,p);

		if(ans<t-a[i])

			q=make_pair(i,p),ans=t-a[i];

		/*for(int j=1;1<=i-j&&i<=n-j;j++)

		{

			if((a[i-j]+a[n-j+1])<=mean*2)

			{

				if(ans<mean-a[i])

				{

					ans=mean-a[i];

					q=make_pair(i,j);

				}

					break;

			}

			mean=(mean*(j*2-1)+a[i-j]+a[n-j+1])/(j*2+1);

		}*/

	}

	printf("%d\n",q.second*2+1);

	for(i=q.second;i;i--)

		printf("%d ",a[q.first-i]);

	printf("%d",a[q.first]);

	for(i=q.second;i;i--)

		printf(" %d",a[n-i+1]);

	return 0;

}