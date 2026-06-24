#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x)
{
	x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
}
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	x*=f;
	return;
}	
template<typename T>
void write(T x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
	return;
}
const int MAXN=100010;
int n;
int tot=2;
int edge[MAXN*2],nxt[MAXN*2],hd[MAXN];
inline void add_edge(int u,int v)
{
	edge[tot]=v,nxt[tot]=hd[u],hd[u]=tot++;
}
int d[MAXN];
int ans[MAXN];
bool book[MAXN];
int main()
{
	read(n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		read(u),read(v);
		add_edge(u,v),add_edge(v,u);
		d[u]++,d[v]++;
	}
	for(int i=1;i<=n;i++)
	if(d[i]>=3)
	{
		int cnt=0;
		for(int j=hd[i];j;j=nxt[j])
		if(cnt>3) break;
		else ans[j/2]=cnt++,book[j/2]=1;
		for(int j=1;j<n;j++)
		if(!book[j]) ans[j]=cnt++;
		for(int j=1;j<n;j++) write(ans[j]),putchar('\n');
		return 0;
	}
	for(int i=1;i<n;i++) write(i-1),putchar('\n');
	return 0;
}