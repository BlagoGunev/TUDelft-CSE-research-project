#include <bits/stdc++.h>
#include <set>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
set <int> H,V;
set <int>::iterator iter,l,r;
int n,m,temp,maxh,maxv,ansv,ansh,h[200020],v[200020];
bool flag; 
long long ans;
char ch;
int  read()
{
	flag=false;
	while(ch=getchar(),ch!='-'&&(ch<'0'||ch>'9'));
	if(ch=='-'){flag=1; temp=0;} else temp=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9') temp=temp*10+ch-'0';
	return flag?-temp:temp;
}
int main()
{
	maxv=read(); maxh=read(); n=read(); 
	ansh=maxh;ansv=maxv; h[maxh]=1; v[maxv]=1;
	H.insert(0); H.insert(maxh);
	V.insert(0); V.insert(maxv);
	for(int i=1;i<=n;++i)
	{
		while(ch=getchar(),ch!='H'&&ch!='V'); 
		if(ch=='H')
		{m=read();
			H.insert(m);
			iter=H.find(m);
			l=iter;
			r=l;
			l--;
			r++;
			h[(*r)-(*l)]--;
			h[(*r)-(*iter)]++;
			h[(*iter)-(*l)]++;
			while(!h[ansh]) ansh--;
			ans=(long long)ansh*ansv;
			printf("%lld\n",ans);
		}
		else
		{
			m=read();
			V.insert(m);
			iter=V.find(m);
			l=iter;
			r=l;
			l--;
			r++;
			v[(*r)-(*l)]--;
			v[(*r)-(*iter)]++;
			v[(*iter)-(*l)]++;
			while(!v[ansv]) ansv--;
			ans=(long long)ansh*ansv;
			printf("%lld\n",ans);
		}
	}
	return 0;
}