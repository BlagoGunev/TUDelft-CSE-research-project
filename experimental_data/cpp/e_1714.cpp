#include<bits/stdc++.h>

using namespace std;

#define int long long

#define rep(i,a,b) for(int i=a;i<=b;++i)

inline int read(){

	int x=0,f=1;char ch=getchar();

	while(!isdigit(ch)){if(ch=='-')f=0;ch=getchar();}

	while(isdigit(ch)){x=x*10+(ch^48);ch=getchar();}

	return f?x:-x;

}

int n,a[205202];

void deal()

{

	n=read();

	rep(i,1,n)a[i]=read();

	rep(i,1,n)

	{

		if(a[i]&1)a[i]+=a[i]%10;

	}

	int t=0,t2=0;

	rep(i,1,n)

	{

		if(!(a[i]%10))t++;

		else t2++;

	}

	if(t&&t2)

	{

		puts("NO");

		return ;

	}

	if(t&&!t2)

	{

		rep(i,2,n)

		{

			if(a[i]!=a[i-1]) 

			{

			puts("NO");

			return ;

			}

		}

		puts("YES");

		return ;

	}

	rep(i,1,n)

	{

		while(a[i]%10!=2)a[i]+=a[i]%10;

	}

	sort(a+1,a+1+n);

	rep(i,2,n)

	{

		if((a[i]-a[i-1])%20)

		{

				puts("NO");

		return ;

		}

	}

		puts("YES");

}

signed main()

{

	int T=read();

	while(T--) deal();

	return 0;

}