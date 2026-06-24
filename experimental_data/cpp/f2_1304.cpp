#include<bits/stdc++.h>
using namespace std;
const int N=52;
const int M=2e4+4;

int a[N][M],s[N][M],f[N][M];
int pr[M],sf[M],st[M],hd,tl;

int main()
{
	int n,m,q,i,j;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]),
			s[i][j]=s[i][j-1]+a[i][j];
	for(j=1;j<=m+1-q;j++)f[1][j]=s[1][j+q-1]-s[1][j-1];
	for(i=2;i<=n+1;i++){
		for(j=1;j<=m+1-q;j++)
			f[i][j]=f[i-1][j]+s[i][j+q-1]-s[i][j-1];
		for(j=1;j<=m+1-q;j++)
			pr[j]=max(pr[j-1],f[i-1][j]+s[i][j+q-1]-s[i][j-1]);
		for(j=m+1-q;j;j--)
			sf[j]=max(sf[j+1],f[i-1][j]+s[i][j+q-1]-s[i][j-1]);
		for(j=1;j<=m+1-q;j++){
			if(j>q)f[i][j]=max(f[i][j],pr[j-q]+s[i][j+q-1]-s[i][j-1]);
			f[i][j]=max(f[i][j],sf[j+q]+s[i][j+q-1]-s[i][j-1]);
		}
		for(j=1;j<=m+1-q;j++)
			pr[j]=f[i-1][j]-s[i][j-1],
			sf[j]=f[i-1][j]+s[i][j+q-1];
		hd=tl=0;
		for(j=1;j<=m+1-q;j++){
			while(hd<tl&&st[hd]<=j-q)++hd;
			if(hd<tl)f[i][j]=max(f[i][j],pr[st[hd]]+s[i][j+q-1]);
			while(hd<tl&&pr[st[tl-1]]<=pr[j])--tl;
			st[tl]=j;++tl;
		}
		hd=tl=0;
		for(j=m+1-q;j;j--){
			while(hd<tl&&st[hd]>=j+q)++hd;
			if(hd<tl)f[i][j]=max(f[i][j],sf[st[hd]]-s[i][j-1]);
			while(hd<tl&&sf[st[tl-1]]<=sf[j])--tl;
			st[tl]=j;++tl;
		}
	}
	printf("%d",f[n+1][1]);
	return 0;
}