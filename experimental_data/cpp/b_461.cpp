#include<cstdio>

#define ll long long

const int N=1e5+5,M=2*N,mo=1e9+7;

struct edge{int l,to;}e[M];

int n,i,et,he[N],f0[N],f1[N];

bool col[N];

int read(){

	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());

	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;

}

void dfs(int x,int fa){

	if (col[x]) f1[x]=1; else f0[x]=1;

	for (int i=he[x];i;i=e[i].l){

		int y=e[i].to;if (y==fa) continue;

		dfs(y,x);

		f1[x]=((ll)f1[x]*(f0[y]+f1[y])+(ll)f0[x]*f1[y])%mo;

		f0[x]=(ll)f0[x]*(f0[y]+f1[y])%mo;

	}

}

void line(int x,int y){

	e[++et].l=he[x];he[x]=et;e[et].to=y;

}

int main(){

	for (n=read(),i=2;i<=n;i++){

		int x=read()+1;

		line(i,x);line(x,i);

	}

	for (i=1;i<=n;i++) col[i]=read();

	dfs(1,0);

	printf("%d",f1[1]);

}