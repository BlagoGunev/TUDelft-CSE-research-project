#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a,b,c,m,n,lk1=1,lk2=2,ans[200005];
bool used[200005],flag=true;
struct node {
	int x,d;
}f[200005];

bool cmp (node a,node b) {
	return a.x<b.x;
}

inline int getnum1 () {
	while (used[lk1]) lk1+=2;
	if (lk1>m) flag=false;
	ans[0]++; lk1+=2;
	return lk1-2;
}

inline int getnum2 () {
	while (used[lk2]) lk2+=2;
	if (lk2>m) flag=false;
	ans[0]++; lk2+=2;
	return lk2-2;
}

int main () {
	scanf ("%d %d",&n,&m);
	if (m>n) m=n;
	for (a=1;a<=n;a++) {
		scanf ("%d",&f[a].x); f[a].d=a;
		if (f[a].x<=m) used[f[a].x]=true;
	}
	sort (f+1,f+n+1,cmp);
	for (a=n;a>1;a--) {
		if (f[a].x==f[a-1].x)
			f[a].x=-1;
	}
	int n1=0,n2=0;
	for (a=1;a<=n;a++) {
		if (f[a].x==-1) continue;
		if (f[a].x&1) n1++; else n2++;
	}
	for (a=1;a<=n&&n1>n/2;a++) {
		if (f[a].x==-1) continue;
		if (f[a].x&1) f[a].x=-1,n1--;
	}
	for (a=1;a<=n&&n2>n/2;a++) {
		if (f[a].x==-1) continue;
		if (!(f[a].x&1)) f[a].x=-1,n2--;
	}
	a=1;
	while (n1<n/2) {
		while (f[a].x!=-1) a++;
		f[a].x=getnum1 (); n1++;
		if (!flag) {puts ("-1"); return 0;}
	}
	while (n2<n/2) {
		while (f[a].x!=-1) a++;
		f[a].x=getnum2 (); n2++;
		if (!flag) {puts ("-1"); return 0;}
	}
	for (a=1;a<=n;a++) ans[f[a].d]=f[a].x;
	printf ("%d\n",ans[0]);
	for (a=1;a<=n;a++)
		printf ("%d ",ans[a]);
	return 0;
}