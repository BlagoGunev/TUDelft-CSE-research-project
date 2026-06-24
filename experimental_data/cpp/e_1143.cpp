#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+1;

int read(){
	int x=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}

int n,m,q;
int p[maxn],a[maxn],id[maxn];
int f[18][maxn],pos[maxn];
int s[maxn];

int main(){
	n=read(),m=read(),q=read();
	for (int i=1;i<=n;++i)
	p[i]=read(),id[p[i]]=i;
	p[0]=p[n];
	for (int i=1;i<=m;++i){
		a[i]=read();
		f[0][i]=pos[p[id[a[i]]-1]];
		pos[a[i]]=i;
		for (int j=1;j<18;++j)
		f[j][i]=f[j-1][f[j-1][i]];
	}
	for (int i=1;i<=m;++i){
		int u=i;
		for (int j=17;~j;--j)
		if ((n-1)&(1<<j)) u=f[j][u];
		s[i]=max(s[i-1],u);
	}
	for (int i=1;i<=q;++i){
		int l=read(),r=read();
		putchar('0'+(s[r]>=l));
	}
	
}