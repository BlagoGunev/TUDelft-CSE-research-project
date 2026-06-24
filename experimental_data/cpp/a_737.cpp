#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
inline LL read() {
	LL x=0,s=1; char ch=getchar();
	while (ch<'0'||ch>'9') { if (ch=='-') s=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return s*x;
}

struct Data{
	LL c,v;
	bool operator <(const Data& B) const { return v<B.v; }
}A[200005];
LL n,m,s,t,g[200005],f[200005];
int main() {
	LL i,j,k,f1=0,f2=2147483647;
	n=read(); m=read(); s=read(); t=read();
	if (s>t) { printf("-1\n"); return 0; }
	for (i=1;i<=n;++i) { A[i].c=read(); A[i].v=read(); }
	for (i=1;i<=m;++i) g[i]=read();
	sort(g+1,g+1+m);
	g[0]=0; g[m+1]=s;
	for (i=m+1;i;--i) {
		g[i]-=g[i-1];
		f1=max(f1,g[i]);
	}
	sort(g+1,g+2+m);
	for (i=1;i<=m+1;++i) g[i]+=g[i-1];
	//for (i=1;i<=m+1;++i) cout<<g[i]<<' '; puts("");
	sort(A+1,A+1+n);
	for (i=1,j=k=0;i<=n;++i)
	if (A[i].v>=f1) {
		//cout<<A[i].v<<' '<<A[i].c<<endl;
		while (k<m+1&&(g[k+1]-g[k])*2<=A[i].v) ++k;
		LL tmp=s*2-(g[k]*2+A[i].v*(m+1-k)-s);
		//cout<<tmp<<endl;
		if (t>=tmp&&f2>A[i].c) { f2=A[i].c; j=i; }
	}
	if (f2==2147483647) printf("-1\n"); else cout<<A[j].c<<endl;
	
	return 0;
}

/*
3 1 8 10
10 8
5 7
11 9
3
2 2 10 18
10 4
20 6
5 3

*/