#include<cstdio>

const int N=505,mo=1e9+7;

int n,m,T,i,x1,y1,x2,y2,f[N][N],ans;

char a[N][N];

int main(){

	scanf("%d%d",&n,&m);T=n+m-2>>1;

	for (i=1;i<=n;i++) scanf("%s",a[i]+1);

	if (a[1][1]!=a[n][m]) return puts("0"),0;

	f[1][n]=1;

	for (int step=1;step<=T;step++){

		int re=step-(m-1);if (re<0) re=0;

		int s1=1+re,t1=(1+step<n)?1+step:n;

		for (x1=t1;x1>=s1;x1--){

			y1=1+step-(x1-1);

			int t2=n-re,s2=(1>n-step)?1:n-step;

			for (x2=s2;x2<=t2;x2++){

				y2=m-(step-(n-x2));

				if (a[x1][y1]!=a[x2][y2]){f[x1][x2]=0;continue;}

				if (!(y1&&y2<m)) f[x1][x2]=0;

				if (y1&&x2<n) f[x1][x2]=(f[x1][x2]+f[x1][x2+1])%mo;

				if (x1&&y2<m) f[x1][x2]=(f[x1][x2]+f[x1-1][x2])%mo;

				if (x1&&x2<n) f[x1][x2]=(f[x1][x2]+f[x1-1][x2+1])%mo;

			}

		}

	}

	int s=1+T-(m-1);if (s<1) s=1;

	int t=1+T<n?1+T:n;

	if ((n+m-1)&1){

		for (i=s;i<=t;i++) ans=(ans+f[i][i])%mo;

	}

	else{

		for (i=s;i<=t;i++){

			if (n-i<=T) ans=(ans+f[i][i])%mo;

			if (i<n) ans=(ans+f[i][i+1])%mo;

		}

	}

	printf("%d",ans);

}