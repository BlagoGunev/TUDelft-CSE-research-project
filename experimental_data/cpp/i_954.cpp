#include<bits/stdc++.h>
using namespace std;
const int maxn=125011;
int nw[10],n,m; char S[maxn],s[maxn]; int ans[maxn];
void calc(int A){
	static int a[maxn],b[maxn],Next[maxn];
	for (int i=1;i<=n;++i) a[i]=nw[S[i]-'a'+1];
	for (int i=1;i<=m;++i) b[i]=nw[s[i]-'a'+1];
	Next[1]=0;
	for (int i=2,tmp=0;i<=m;++i){
		while (tmp && b[tmp+1]!=b[i]) tmp=Next[tmp];
		if (b[tmp+1]==b[i]) Next[i]=++tmp;else Next[i]=0;
	}
	for (int i=1,now=0;i<=n;++i){
		while (now && b[now+1]!=a[i]) now=Next[now];
		if (b[now+1]==a[i]) ++now;
		if (now==m) ans[i]=min(ans[i],A),now=Next[now];
	}
}
void dfs(int dep,int A){
	if (dep>6){calc(A); return;}
	for (int i=1;i<dep;++i) if (nw[i]==i){
		nw[dep]=i; dfs(dep+1,A+1);
	}
	nw[dep]=dep; dfs(dep+1,A);
}
int main(){
	memset(ans,63,sizeof(ans));
	scanf("%s%s",S+1,s+1); n=strlen(S+1); m=strlen(s+1); dfs(1,0);
	for (int i=m;i<=n;++i) printf("%d ",ans[i]);
}