#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
//Zachary_260325の代码起手式 (可能借鉴了yyf巨佬的) 
#define int long long
#define rint register int
#define pqueue priority_queue
#define file(); freopen("test.in","r",stdin);freopen("test.out","w",stdout);
#define endl() putchar('\n')
typedef long long ll;
typedef unsigned long long ull;
int read()
{
    int k=0,flag=1;
    char tmp=getchar();
    while('0'>tmp||'9'<tmp)
    {
        if(tmp=='-')
            flag=-1;
        tmp=getchar();
    }
    while('0'<=tmp&&'9'>=tmp)
    {
        k=10*k+tmp-'0';
        tmp=getchar();
    }
    return flag*k;
}
int a[200005];
int n,k;
bool get(int now,int f)
{
	int delta=a[now+1]-a[now];
	if(!delta)
		return 1;
	int plus=delta*f;
	if(k>plus)
	{
		k-=plus;
		return 1;
	}
	a[now]+=k/f;
	return 0;
}
signed main()
{
    //Good luck & high rating!
    //file();
    n=read(),k=read();
    for(int i=1;i<=n;++i)
    	a[i]=read();
    std::sort(a+1,a+1+n);
    a[n+1]=2000000000; 
    int x=n/2+1,f=1;
    while(get(x,f))
    	f++,x++;
    printf("%d",a[x]);
    return 0;
}