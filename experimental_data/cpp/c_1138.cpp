#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[1200][1200];
int mn_x[1200][1200],mn_y[1200][1200],xx[1200],yy[1200];
//xx行上总数,小：xx[i]-mn_x[i][j]
struct node {
	int w,at;
} q[1200];
bool cmp(node a,node b) {
	return a.w<b.w;
}
inline int read() {
	int x=0;
	char ch=getchar();
	while(!(ch>='0' && ch<='9')) ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
inline void write(int x) {
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
signed main() {
	cin>>n>>m;
	for(register int i=1;i<=n;i++) for(register int j=1;j<=m;j++) a[i][j]=read();
	for(register int i=1;i<=n;i++) {
		cnt=0;
		for(int j=1;j<=m;j++) q[++cnt]=(node) {a[i][j],j};
		sort(q+1,q+cnt+1,cmp);
		int val=0,at=0;
		for(register int j=1;j<=m;j=at+1) {
			val++;
			while(at<m && q[j].w==q[at+1].w) {
				at++;
				mn_x[i][q[at].at]=val;
			}
		}
		xx[i]=val;
	}
	for(register int i=1;i<=m;i++) {
		cnt=0;
		for(register int j=1;j<=n;j++) q[++cnt]=(node) {a[j][i],j};
		sort(q+1,q+cnt+1,cmp);
		int val=0,at=0;
		for(register int j=1;j<=n;j=at+1) {
			val++;
			while(at<n && q[j].w==q[at+1].w) {
				at++;
				mn_y[q[at].at][i]=val;
			}
		}
		yy[i]=val;
	}
	for(register int i=1;i<=n;i++) {
		for(register int j=1;j<=m;j++) {
			write(max(max(xx[i],yy[j]),max(mn_x[i][j]+yy[j]-mn_y[i][j],mn_y[i][j]+xx[i]-mn_x[i][j])));
			putchar(' ');
		}
		puts("");
	}
	return 0;
}