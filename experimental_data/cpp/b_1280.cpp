#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<sstream>
#include<cctype>
#include<cmath>
#include<iomanip>
#include<map>
#include<stack>
#include<set>
#include<functional>
#define in(x) x=read()
#define qr read()
#define int ll
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
namespace fastIO
{
    #define BUF_SIZE 100000
    bool IOerror=0;
    inline char nc()
	{
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline ll read()
	{
        bool sign=0; char ch=nc();ll x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return 0;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
        return x;
    }
    #undef BUF_SIZE
};
using namespace fastIO;
int a[1010][1010];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int t=qr;
	while(t--)
	{
		int n=qr,m=qr;
		int f=1,g=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				a[i][j]=nc()=='A';
				f=f&&a[i][j];
				g=g||a[i][j];
			}nc();
		}
		if(f)
		{
			puts("0");
			continue;
		}
		if(!g)
		{
			puts("MORTAL");
			continue;
		}
		f=0;
			int h=1;
			for(int j=1;j<=m;j++)
			{
				if(a[1][j]==0)h=0;
			}
			if(h)f=1;h=1;
			for(int j=1;j<=m;j++)
			{
				if(a[n][j]==0)h=0;
			}
			if(h)f=1;h=1;
			for(int j=1;j<=n;j++)
			{
				if(a[j][1]==0)h=0;
			}
			if(h)f=1;h=1;
			for(int j=1;j<=n;j++)
			{
				if(a[j][m]==0)h=0;
			}
			if(h)f=1;
		if(f)
		{
			puts("1");
			continue;
		}
		f=0;
		for(int i=1;i<=n;i++)
		{
			int h=1;
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]==0)h=0;
			}
			if(h)f=1;
		}
		for(int i=1;i<=m;i++)
		{
			int h=1;
			for(int j=1;j<=n;j++)
			{
				if(a[j][i]==0)h=0;
			}
			if(h)f=1;
		}
		f=f||a[1][1],f=f||a[1][m],f=f||a[n][1],f=f||a[n][m];
		if(f)
		{
			puts("2");
			continue;
		}
		f=0;
		for(int i=1;i<=n;i++)
		{
			f=f||a[i][1],f=f||a[i][m];
		}
		for(int i=1;i<=m;i++)
		{
			f=f||a[1][i],f=f||a[n][i];
		}
		if(f)
		{
			puts("3");
			continue;
		}puts("4");
	}
	return 0;
}