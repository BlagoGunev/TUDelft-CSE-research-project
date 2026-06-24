//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<ctime> 
#include<cstring>
#include<string>
#include<ctime>
#include<cctype>
#include<cstdio>
#include<utility>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<set>
#include<bitset>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
char buf[1<<15],*fs,*ft;
inline char getc()
{
	return (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),fs==ft))?0:*fs++;
}
inline int read()
{
	int x=0,f=1;char ch=getc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getc();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getc();}
	return x*f;
}
const int MAXN=150010;
int n,ans;
int a[MAXN],w[MAXN];
int main()
{
	//freopen("1.in","r",stdin);
	n=read();w[0]=-1;
	for(int i=1;i<=n;++i)++a[read()];
	for(int i=150000;i;--i)
	{
		while(a[i])
		{
			if(w[i+1]!=-1)
			{
				w[i+1]=-1;++ans;
				--a[i];
				continue;
			}
			if(w[i]!=-1)
			{
				w[i]=-1;++ans;
				--a[i];
				continue;
			}
			if(w[i-1]!=-1)
			{
				w[i-1]=-1;++ans;
				--a[i];
				continue;
			}
			a[i]=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}