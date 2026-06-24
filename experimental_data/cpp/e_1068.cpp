#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read() {
	int tot=0,fh=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') fh=-1;c=getchar();}
	while (c>='0'&&c<='9') {tot=tot*10+c-'0';c=getchar();}
	return tot*fh;
}
void getstr(char *a) {
	char ch=getchar();int len=0;
	while (ch<'A'||ch>'Z') ch=getchar();
	while (ch>='A'&&ch<='Z') {a[++len]=ch;ch=getchar();}
}
const int maxn=2e5+100;
struct compass {
	int nxt,dat;
} p[maxn*2];
int tot,head[maxn],n,k,q[maxn*2],ti[maxn],tag[maxn],du[maxn],ans,num,vis[maxn];
bool flag[maxn];
void connect(int x,int y) {
	tot++;
	p[tot].nxt=head[x];
	p[tot].dat=y;
	head[x]=tot;
}
int main() {
	n=read();k=read();
	for (int i=1;i<n;i++) {
		int x=read(),y=read();
		du[x]++;du[y]++;
		connect(x,y);
		connect(y,x);
	}
	for (int i=1;i<=n;i++) tag[i]=-1;
	int l=1,r=0;
	for (int i=1;i<=n;i++) 
		if (du[i]==1) {
			q[++r]=i;
			tag[i]=0;
			flag[i]=true;
		}
	while (l<=r) {
		if (!flag[q[l]]) {
			cout<<"NO"<<"\n";
			return 0;
		}
		for (int i=head[q[l]];i;i=p[i].nxt) {
			int now=p[i].dat;
			if (vis[now]==-1) continue;
			if (tag[now]==-1) {
				tag[now]=tag[q[l]]+1;
				q[++r]=now;
				ti[now]++;
			} else {
				if (tag[now]==tag[q[l]]+1) {
					ti[now]++;
					if (ti[now]==3) flag[now]=true;
				} else {
					cout<<"NO"<<"\n";
					return 0;
				}
			}
		}
		vis[q[l]]=-1;
		l++;
	}
	for (int i=1;i<=n;i++)
		if (!flag[i]) {
			cout<<"NO"<<"\n";
			return 0;
		}
	for (int i=1;i<=n;i++) {
		if (tag[i]>ans) {ans=tag[i];num=0;}
		if (tag[i]==ans) num++;
	}
	if (ans==k&&num==1) cout<<"YES"<<"\n";else cout<<"NO"<<"\n";
	return 0;
}