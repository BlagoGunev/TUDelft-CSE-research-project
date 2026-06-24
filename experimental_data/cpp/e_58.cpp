#include <bits/stdc++.h>
#include<iostream>

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#include<queue>

#include<vector>

#include<set>

#include<map>

#define ll long long 

#define dd double 

#define inf 0x3f3f3f3f

using namespace std;

inline int getint()

{

	int res=0,fh=1;char ch=getchar();

	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();

	if(ch=='-')fh=-1,ch=getchar();

	while(ch<='9'&&ch>='0')res=res*10+ch-'0',ch=getchar();

	return res*fh;

}

inline ll getll()

{

	ll res=0,fh=1;char ch=getchar();

	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();

	if(ch=='-')fh=-1,ch=getchar();

	while(ch<='9'&&ch>='0')res=res*10+ch-'0',ch=getchar();

	return res*fh;

}

ll ans=13;

ll sa,sb;

ll d[101];

ll a,b,c;

 void dfs(ll a,ll b,ll c,ll ga,ll gb,int jw,int dep,int step)

{

	if(step>=ans)return ;

	if(!a&&!b&&!c&&!jw)

	{

		if(step<ans)

		{

			ans=step;

			sa=ga;sb=gb;

		}

		return ;

	}

	if(!c)

	{

		int len=0;

		ll res=a+b+jw;

		while(res){len++;res/=10;}

		dfs(0,0,0,ga+d[dep]*a,gb+d[dep]*b,0,dep,step+len);

		return ;

	}

	if((a+b+jw)%10==c%10)

		dfs(a/10,b/10,c/10,ga+(a%10)*d[dep],gb+(b%10)*d[dep],(a%10+b%10+jw)/10,dep+1,step);

	else 

	{

		dfs(a*10+(c+10-b%10-jw)%10,b,c,ga,gb,jw,dep,step+1);

		dfs(a,b*10+(c+10-a%10-jw)%10,c,ga,gb,jw,dep,step+1);

		dfs(a,b,c*10+(a+b+jw)%10,ga,gb,jw,dep,step+1);

	}

}

int main()

{

	d[0]=1;

	for(int i=1;i<=10;i++)

		d[i]=d[i-1]*10;

	scanf("%lld+%lld=%lld",&a,&b,&c);

	dfs(a,b,c,0,0,0,0,0);

	printf("%lld+%lld=%lld",sa,sb,sa+sb);

	return 0;

}