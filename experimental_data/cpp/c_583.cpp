//Copyright (c)2015 Liu chenrui
//This sourcecode is licensed under Dev c++ 5.4.0
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <map>
#include <vector>
using namespace std;
#define F first
#define S second
map<int,int>::iterator range;
map<int,int>Ginging;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
inline void check()
{
	if(range->S==0)Ginging.erase(range);
}
int getint()
{
    int _b=0;char _c;
    for (_c=getchar();_c<'0'||_c>'9';_c=getchar());
    for (;_c>='0'&&_c<='9';_c=getchar())
      {_b*=10;
       _b+=_c-'0';
      }
    return _b;  
}
void change(int a,int b)
{
	int gc=gcd(a,b);
	Ginging[gc]-=2;
	range=Ginging.find(gc);
	check();
}
int a[505*505];

int n;
vector<int> ans;

int main()
{
	//freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
	n=getint();
	for(int i=1;i<=n*n;++i)
	{
		a[i]=getint();
		Ginging[a[i]]++;
	}
	range=Ginging.end();
	range--;
	ans.push_back((*range).F);
	range->S--;
	check();
	for(int cur;ans.size()!=n;ans.push_back(cur))
	{
		range=Ginging.end();--range;
		cur=range->F;range->S--;
		check();
		for(int i=0;i<(int)ans.size();++i)change(cur,ans[i]);
	}
	for(int i=0;i<(int)ans.size();++i)
	{
		printf("%d ",ans[i]);
	}
}