#include<cstdio>

const int N=2e5+5;

int n,m,i,f[N],r[N];

int read(){

	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());

	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;

}

int get(int x){return f[x]==x?x:f[x]=get(f[x]);}

int main(){

	n=read();m=read();

	for (i=1;i<=n;i++) f[i]=i,r[i]=i+1;

	for (;m--;){

		int opt=read(),x=read(),y=read();

		if (opt==1) f[get(x)]=get(y);

		if (opt==2)

			for (int fy=get(y);x<y;){

				f[get(x)]=fy;int xx=r[x];

				r[x]=r[y];x=xx;

			}

		if (opt==3) puts(get(x)==get(y)?"YES":"NO");

	}

}