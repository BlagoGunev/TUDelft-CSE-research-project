#include <bits/stdc++.h>

using namespace std;

#include <cstdio>

#include <cstring>



struct matrix

{

	long long g[3][3];

};



matrix first,basic,empty,result;



long long i,k,l,m,n,s,t1,t2;



inline long long power(long long x,long long y)

{

	if (y==0) return 1;

	long long t=power(x,y/2);

	t=t*t%m;

	if (y&1) t=t*x%m;

	return t;

}



inline void buildfirstmatrix()

{

	empty.g[1][1]=1,empty.g[1][2]=0,empty.g[2][1]=0,empty.g[2][2]=1;

	first.g[1][1]=1,first.g[1][2]=1,first.g[2][1]=0,first.g[2][2]=0;

	basic.g[1][1]=0,basic.g[1][2]=1,basic.g[2][1]=1,basic.g[2][2]=1;

	return;

}



inline matrix matrixmultiplication(matrix x,matrix y)

{

	matrix z;

	memset(z.g,0,sizeof(z.g));

	for (int i=1;i<=2;i++)

		for (int j=1;j<=2;j++)

			for (int k=1;k<=2;k++)

				z.g[i][j]=z.g[i][j]+x.g[i][k]*y.g[k][j];

	for (int i=1;i<=2;i++)

		for (int j=1;j<=2;j++)

			z.g[i][j]=z.g[i][j]%m;

	return z;

}



inline void matrixpowersum(long long x)

{

	if (x==0) { result=empty; return; }

	matrixpowersum(x/2);

	result=matrixmultiplication(result,result);

	if (x&1) result=matrixmultiplication(result,basic);

	return;

}



inline long long getfib(long long x)

{

	buildfirstmatrix();

	matrixpowersum(x);

	result=matrixmultiplication(first,result);

	return result.g[1][1];

}



int main()

{

	scanf("%lld%lld%lld%lld",&n,&k,&l,&m);

	if ((l<=60) && ((1LL<<l)<=k)) { puts("0"); return 0; }

	t2=getfib(n+1),t1=(power(2,n)-t2+m)%m,s=1%m;

	for (i=0;i<l;i++) if (k&(1LL<<i)) s=s*t1%m; else s=s*t2%m;

	printf("%lld",s);

	return 0;

}