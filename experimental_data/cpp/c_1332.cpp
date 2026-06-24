#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#define LL long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dwn(i,x,y) for(int i=(x);i>=(y);--i)
#define view(u,k) for(int k=fir[u];~k;k=nxt[k])
using namespace std;
#define maxn 200007
int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
void write(int x)
{
	char ch[20];int f=0;
	if(!x){putchar('0'),putchar('\n');return;}
	if(x<0)putchar('-'),x=-x;
	while(x)ch[++f]=x%10+'0',x/=10;
	while(f)putchar(ch[f--]);
	putchar('\n');
}
int num[27],n,k,t,ans;
char s[maxn];
int gx(char c){return c-'a';}
int mo(int x){int p=x%k;if(!p)p=k;return p;}
int main()
{
	t=read();
	while(t--)
	{
		scanf("%d%d%s",&n,&k,s+1);ans=0;
		int li=k/2;
		rep(i,1,li)
		{
			int tmp=0,mx=0;
			for(int j=i;j<=n;j+=k)
			{
				int len=k*(int)ceil((double)j/(double)k);
				num[gx(s[j])]++,num[gx(s[len-mo(j)+1])]++,tmp+=2; 
			}
			rep(j,0,25)mx=max(mx,num[j]),num[j]=0;
			ans+=tmp-mx;//cout<<tmp<<" "<<mx<<endl;
		}
		if(k&1)
		{
			int tmp=0,mx=0;
			for(int j=li+1;j<=n;j+=k){num[gx(s[j])]++,tmp++;}
			rep(j,0,25)mx=max(mx,num[j]),num[j]=0;
			ans+=tmp-mx;//cout<<tmp<<" "<<mx<<endl;
		}
		write(ans);
	}
	return (~(0-0)+1);
}