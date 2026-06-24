// LUOGU_RID: 98184623
#include<bits/stdc++.h>

using namespace std;

const int maxn=5005;

int n,k;

double ans;

double f[maxn];

struct acid{

	int x,w,c;

}a[maxn];

inline int cmp(acid a,acid b){

	return a.x<b.x;

}

int main(){

	scanf("%d%d",&n,&k);

	for(int i=1;i<=n;i++)

		scanf("%d%d%d",&a[i].x,&a[i].w,&a[i].c);

	sort(a+1,a+1+n,cmp);

	for(int i=1;i<=n;i++){

		f[i]=-a[i].w;

		for(int j=1;j<i;j++)

			f[i]=max(f[i],f[j]+1.0*(a[i].c+a[j].c)/2.0*(a[i].x-a[j].x)/100.0*k-a[i].w);

		ans=max(ans,f[i]);

	}

	printf("%.10lf\n",ans);

	return 0;

}