#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

inline int read() {
    int x=0,f=1; char ch=getchar();
    while (!(ch>='0'&&ch<='9')) {if (ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

const int N = 200005;

int n,m,d,id=0;
int a[N],b[N];
int ans[N];
int q[N][2],head=0,tail=0;

inline bool cmp(int x,int y) {
	return a[x]<a[y];
}

int main() {

	#ifndef ONLINE_JUDGE
	//	freopen("data.in","r",stdin);
	//	freopen("data.out","w",stdout);
	#endif

	n=read(),m=read(),d=read();
	rep(i,1,n) a[i]=read(); rep(i,1,n) b[i]=i; sort(b+1,b+n+1,cmp);
	q[tail][0]=a[b[1]]; ans[b[1]]=++id; q[tail++][1]=id;
	rep(i,2,n) {
		if (a[b[i]]-q[head][0]>d) {
			q[tail][0]=a[b[i]],q[tail][1]=q[head][1];
			ans[b[i]]=q[head][1];
			head++; tail++;
		} else {
			q[tail][0]=a[b[i]],q[tail][1]=++id;
			ans[b[i]]=id;
			tail++;
		}
	}
	printf("%d\n",id);
	rep(i,1,n-1) printf("%d ",ans[i]); printf("%d\n",ans[n]);

	return 0;
	
}