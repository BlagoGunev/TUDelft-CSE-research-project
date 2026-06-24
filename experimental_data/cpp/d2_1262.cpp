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
#define maxn 200007 
#define pii pair<int,int>
#define fi first
#define se second
#define ppi pair<pii ,int>
#define mp make_pair
using namespace std;
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
LL s[maxn];
int ans[maxn];//[i,n],have j
int n,a[maxn],m,tr[maxn];
pii b[maxn];
ppi qu[maxn];
int lt(int x){return x&(-x);}
void add(int x,int k){for(;x<=n;x+=lt(x))tr[x]+=k;return;}
int ask(int x){int k=0;for(;x;x-=lt(x))k+=tr[x];return k;}
int main()
{
	n=read();
	rep(i,1,n)a[i]=read(),b[i].fi=-a[i],b[i].se=i;
	sort(b+1,b+n+1);
	rep(i,1,n)b[i].fi=-b[i].fi,s[i]=s[i-1]+b[i].fi;
	m=read();
	rep(i,1,m){int x=read(),y=read();qu[i]=mp(mp(x,y),i);}
	sort(qu+1,qu+m+1);
	int now=0;
	rep(i,1,m)
	{
		while(now<qu[i].fi.fi)now++,add(b[now].se,1);
		int L=0,R=n-1;ans[qu[i].se]=-1;
		while(L<=R)
		{
			int mid=(L+R)>>1,f=ask(mid);
			if(f<qu[i].fi.se)ans[qu[i].se]=max(ans[qu[i].se],mid+1),L=mid+1;
			else R=mid-1;
		}
	}
	rep(i,1,m)write(a[ans[i]]);
	return (~(0-0)+1);
}