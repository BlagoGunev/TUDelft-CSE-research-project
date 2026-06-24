#include <bits/stdc++.h>
#define maxn 200020
using namespace std;

inline int read(){
	int x=0,f=1;char cc=getchar();
	while(cc<'0' || cc>'9') {if(cc=='-') f=-1;cc=getchar();}
	while(cc>='0' && cc<='9') {x=x*10+cc-'0';cc=getchar();}
	return x*f;
}

int n,c[maxn],a[maxn],d[maxn],dnum,v[maxn],flag,ans;

inline void dfs(int k){
	if(v[k]==2){
		flag=1;for(int i=1;i<=dnum;i++) v[d[i]]=2;return;
	}
	if(v[k]==1){
		int tmp=100000;
		for(int i=dnum;i;i--){
			tmp=min(tmp,c[d[i]]);
			if(d[i]==k) break;
		}
		ans+=tmp;
		for(int i=1;i<=dnum;i++) v[d[i]]=2;
		flag=1;return;
	}
	v[k]=1;dnum++;d[dnum]=k;dfs(a[k]);
}

int main(){
	n=read();
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		flag=0;dnum=0;
		dfs(i);
	}
	printf("%d",ans);
}