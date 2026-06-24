#include <iostream>

#include <cstdio>

#include <cmath>

#include <cstring>

#include <algorithm>

#include <vector>

#define N 300005

#define INF 0x7fffffff

using namespace std;

typedef long long ll;



int read()

{

    int x=0,f=1;char ch=getchar();

    while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}

    while(isdigit(ch)) {x=x*10+ch-'0';ch=getchar();}

    return x*f;

}



int n,m,ans,l,r,f;

int a[N],sum[N];



bool judge(int mid)

{

	for(int i=1;i+mid-1<=n;i++)

	{

		int tmp=sum[i+mid-1]-sum[i-1];

		if(tmp<=m){

			f=i;

			return true;

		}

	}

	return false;

}



int main()

{

    n=read(),m=read();

    for(int i=1;i<=n;i++)

    {

    	a[i]=read();

    	sum[i]=sum[i-1]+(a[i]==0);

	}

	r=n;

	while(l<=r)

	{

		int mid=l+r>>1;

		if(judge(mid)) ans=mid,l=mid+1;

		else r=mid-1;

	}

	printf("%d\n",ans);

	for(int i=1;i<=n;i++)

	{

		if(i<=f+ans-1&&i>=f)

			printf("1 ");

		else printf("%d ",a[i]);

	}

    return 0;

}