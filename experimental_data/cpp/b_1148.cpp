#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return x*f;
}
const int N=2e5+10,INF=0x7f7f7f7f;
int a[N],b[N],n,m,k,ta,tb;
int solve(){
	int mx=0;
	for (int x=0;x<=n&&x<=k;++x){
		int y=k-x;
		y=min(y,m);
		if (x==n)
		return -1;
		if (x<n){
			int to=a[x+1]+ta;
			int ty=lower_bound(b+1,b+m+1,to)-b;
			ty=ty+y;
			if (ty>m)
			return -1;
			mx=max(b[ty]+tb,mx);
		}
	}
	return mx;
}
int main(){
	n=read(),m=read(),ta=read(),tb=read(),k=read();
	for (int i=1;i<=n;++i) a[i]=read();
	for (int i=1;i<=m;++i) b[i]=read();
	printf("%d\n",solve());
	return 0;
}