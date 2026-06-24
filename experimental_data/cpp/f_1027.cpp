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

const int N = 2000005;

int n,a[N],b[N];
int tot=0,num[N];
int fa[N];
int s1[N],s2[N],mx[N];
bool vis[N],ban[N];

inline int getfather(int x) {return (fa[x]==x)?x:(fa[x]=getfather(fa[x]));}

inline void Union(int x,int y) {
	int p=getfather(x),q=getfather(y);
	if (p==q) {s2[p]++; return;}
	fa[p]=q; s1[q]+=s1[p]; s2[q]+=s2[p]+1; mx[q]=max(mx[q],mx[p]);
}

int main() {

	#ifndef ONLINE_JUDGE
	//	freopen("data.in","r",stdin);
	//	freopen("data.out","w",stdout);
	#endif

	n=read(); rep(i,1,n) a[i]=read(),b[i]=read(),num[++tot]=a[i],num[++tot]=b[i];
	sort(num+1,num+tot+1); tot=unique(num+1,num+tot+1)-num-1;
	rep(i,1,n) a[i]=lower_bound(num+1,num+tot+1,a[i])-num,b[i]=lower_bound(num+1,num+tot+1,b[i])-num;
	rep(i,1,tot) fa[i]=i,mx[i]=i,s1[i]=1,s2[i]=0;
	rep(i,1,n) Union(a[i],b[i]);
	bool flag=1;
	rep(i,1,tot) {
		int f=getfather(i);
		if (vis[f]) continue;
		if (s2[f]>s1[f]) {flag=0; break;}
		if (s2[f]==s1[f]-1) ban[mx[f]]=1;
		vis[f]=1;
	}
	if (!flag) {puts("-1"); return 0;}
	per(i,tot,1) if (!ban[i]) {printf("%d\n",num[i]); break;}
	

	return 0;
	
}