#include <iostream>

#include <cstdio>

#include <cstring>

#include <stack>

#include <vector>

#include <algorithm>

#define N 200005

#define INF 1000000001

using namespace std;

typedef long long ll;

int read()

{

    int x=0,f=1;char ch=getchar();

    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}

    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}

    return x*f;

}



int n,top;

int a[N];

int ans[N];

int s[N],l[N],r[N];



int main()

{

    n=read();

    for(int i=1;i<=n;i++) a[i]=read();

    for(int i=1;i<=n;i++)

    {

    	while(top&&a[s[top]]>=a[i])

    		top--;

    	l[i]=(top==0?1:s[top]+1);

    	s[++top]=i;

	}

	top=0;

	for(int i=n;i;i--)

	{

		while(top&&a[s[top]]>=a[i])

			top--;

		r[i]=(top==0?n:s[top]-1);

		s[++top]=i;

	}

	for(int i=1;i<=n;i++)

	{

		int len=r[i]-l[i]+1;

		ans[len]=max(ans[len],a[i]);

	}

	for(int i=n;i;i--) ans[i]=max(ans[i],ans[i+1]);

	for(int i=1;i<=n;i++) printf("%d ",ans[i]);

    return 0;

}