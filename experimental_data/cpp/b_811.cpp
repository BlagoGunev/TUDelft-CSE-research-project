#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef long long LL;
#define R register
inline int read()
{
	int x=0;bool f=0;char c=getchar();
	for (;c<'0'||c>'9';c=getchar()) f=c=='-'?1:0;
	for (;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return f?-x:x;
}
const int N=10005;
int n,m,q=0,A[N],ans[N],ss[N],di[N];
struct na{int x,a,id,ty;}e[N*2];
inline bool cmp (const na &a,const na &b){
	return a.x<b.x;
}

inline void add(R int x){
	for (;x<=n;x+=x&-x) ss[x]++;
}
inline int cal(R int x){
	R int r=0;
	for (;x;x-=x&-x) r+=ss[x];
	return r;
}

int main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++) A[i]=read();
	for (int i=1,l,r,x;i<=m;i++){
		l=read(),r=read(),x=read();
		di[i]=x-l+1;
		e[++q]=(na){r,A[x],i,1};
		if (l-1) e[++q]=(na){l-1,A[x],i,-1};
	}
	sort(e+1,e+q+1,cmp);
	for (int i=1,j=1;i<=n;i++){
		add(A[i]);
		while (e[j].x==i) 
			ans[e[j].id]+=e[j].ty*cal(e[j].a),j++;
	}
	for (int i=1;i<=m;i++){
		if (ans[i]==di[i]) puts("Yes");
		else puts("No");
	}
	return 0;
}