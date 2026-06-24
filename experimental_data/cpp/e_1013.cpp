#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

void write(long long x);

inline long long read()
{
    char c;
    long long out=0,f=1;
    for (c=getchar();(c<'0'||c>'9')&&c!='-';c=getchar());
    if (c=='-')
    {
    	f=-1;
    	c=getchar();
	}
    for (;c>='0'&&c<='9';c=getchar())
    {
        out=out*10+c-'0';
    }
    return out*f;
}

long long n,f[2510][3],a[5010];

int main()
{
	int i,j;
	
	n=read();
	
	for (i=1;i<=n;++i)
	{
		a[i]=read();
	}
	
	a[0]=1;
	
	for (j=(n+1)/2;j>=0;--j)
	{
		for (i=0;i<=2;++i)
		{
			f[j][i]=0x7ffffffffffffffll;
		}
	}
	
	f[0][0]=f[1][1]=0;
	
	for (i=2;i<=n;++i)
	{
		for (j=(i+1)/2;j>=1;--j)
		{
			f[j][0]=min(f[j][0],f[j][2]);
			f[j][2]=f[j][1]+max(0ll,a[i]-a[i-1]+1);
			f[j][1]=min(f[j-1][0]+max(0ll,a[i-1]-a[i]+1),f[j-1][2]+max(0ll,min(a[i-1],a[i-2]-1)-a[i]+1));
		}
	}
	
	for (j=1;j<=(n+1)/2;++j)
	{
		cout<<min(f[j][0],min(f[j][1],f[j][2]))<<' ';
	}
	
	return 0;
}

void write(long long x)
{
	if (x<0)
	{
		putchar('-');
		write(-x);
		return;
	}
    if (x>9)
    {
        write(x/10);
    }
    putchar(x%10+'0');
}