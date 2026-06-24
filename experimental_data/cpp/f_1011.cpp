#include <bits/stdc++.h>
#define maxn 1000010
using namespace std;

inline int read(){
	int x=0,f=1;char cc=getchar();
	while(cc<'0' || cc>'9') {if(cc=='-') f=-1;cc=getchar();}
	while(cc>='0' && cc<='9') {x=x*10+cc-'0';cc=getchar();}
	return x*f;
}

int n,l[maxn],r[maxn],s[maxn],a[maxn],f[2][maxn];
char cc;

inline void dfs1(int k){
	if(l[k]>0) dfs1(l[k]);
	if(r[k]>0) dfs1(r[k]);
	if(s[k]=='N') a[k]=1-a[l[k]];
	if(s[k]=='X') a[k]=a[l[k]]^a[r[k]];
	if(s[k]=='O') a[k]=a[l[k]]|a[r[k]];
	if(s[k]=='A') a[k]=a[l[k]]&a[r[k]];
}

inline void dfs2(int k){
	if(s[k]=='N'){
		f[0][l[k]]=f[1][k];
		f[1][l[k]]=f[0][k];
	}
	if(s[k]=='X'){
		f[0][l[k]]=f[a[r[k]]][k];
		f[1][l[k]]=f[1-a[r[k]]][k];
		f[0][r[k]]=f[a[l[k]]][k];
		f[1][r[k]]=f[1-a[l[k]]][k];
	}
	if(s[k]=='O'){
		f[0][l[k]]=f[a[r[k]]][k];
		f[1][l[k]]=f[1][k];
		f[0][r[k]]=f[a[l[k]]][k];
		f[1][r[k]]=f[1][k];
	}
	if(s[k]=='A'){
		f[0][l[k]]=f[0][k];
		f[1][l[k]]=f[a[r[k]]][k];
		f[0][r[k]]=f[0][k];
		f[1][r[k]]=f[a[l[k]]][k];
	}
	if(l[k]>0) dfs2(l[k]);
	if(r[k]>0) dfs2(r[k]);
}

int main(){
	n=read();
	for(int i=1;i<=n;i++){
		s[i]=getchar();
		if(s[i]=='A'){
			l[i]=read();r[i]=read();
			continue;
		}
		if(s[i]=='X'){
			l[i]=read();r[i]=read();
			continue;
		}
		if(s[i]=='O'){
			l[i]=read();r[i]=read();
			continue;
		}
		if(s[i]=='N'){
			l[i]=read();
			continue;
		}
		if(s[i]=='I'){
			a[i]=read();
			continue;
		}
	}
	dfs1(1);
	f[0][1]=0;f[1][1]=1;
	dfs2(1);
	for(int i=1;i<=n;i++) if(s[i]=='I') printf("%d",f[1-a[i]][i]);
}