#include<bits/stdc++.h>
using namespace std;
int n,m,a[300001];

inline int read()
{
	int num=0, fl=1;
	char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') fl=-1;ch=getchar();}
	while (isdigit(ch)){num=num*10+ch-'0'; ch=getchar();}
	return num*fl;
}

inline int f(int x,int d,int y)
{
    if(x<=y&&x+d>=y)return y;
    if(x+d>=m&&x+d-m>=y)return y;
    if(x+d<y)return -1;
    return x;
}
bool check(int x)
{
    int y=0;
	for(int t,i=1;i<=n;++i)
	{
        t=f(a[i],x,y);
        if(t==-1) return false;
        y=t;
    }
    return true;
}

inline void work()
{
	int l=0,r,mid;
    n=read(), m=read();
	r=m-1;
    for(int i=1;i<=n;++i)a[i]=read();
    while(l<r)
	{
        mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l;
}
int main()
{
    work();
    return 0;
}