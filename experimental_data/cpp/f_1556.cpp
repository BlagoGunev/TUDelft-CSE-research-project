#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

#include<map>

#include<vector>

#include<numeric>

#include<cmath>

using namespace std;

#define ll long long

#define ge getchar 

#define pun putchar('\n')

#define pu putchar

#define puk putchar(' ')

const int p=1e9+7;

int f[15][15],a[15],n,r[1<<14],yi[1<<14],g[15][1<<14];

int mi(int x,int n){int a=1;

	while(n){

		if(n&1)a=(ll)a*x%p;

		x=(ll)x*x%p;n>>=1;

	}return a;

}

int nymi(int x){return mi(x,p-2);}

int mo(int x){return x+(x>>31&p);}

int main(){

	//freopen("1.in","r",stdin);

	//freopen("1.out","w",stdout);

	scanf("%d",&n);

	/*if(n<=2){

		puts("1");

		return 0;

	}*/

	for(int i=1;i<=n;i++)scanf("%d",&a[i]);

	for(int i=1;i<=n;i++)

		for(int j=1;j<=n;j++)f[i][j]=(ll)a[i]*nymi(a[i]+a[j])%p;

	int zt=1<<n;

	for(int i=1;i<=n;i++)yi[1<<(i-1)]=i;

	for(int u=1;u<=n;u++){g[u][0]=1;

		for(int i=1;i<zt;i++){

			int w=i&-i;

			g[u][i]=(ll)g[u][i^w]*f[u][yi[w]]%p;

		}

	}

	int m=zt-1,cx=0;

	for(int i=1;i<zt;i++){//i is win scc

		r[i]=1;

		for(int s=(i-1)&i;s;s=(s-1)&i){

			int v=r[s];

			int t=i^s;

			for(int j=s;j;){

				int w=j&-j;j^=w;

				v=(ll)v*g[yi[w]][t]%p;

			}

			r[i]=mo(r[i]-v);

		}

		int v=r[i];

		int t=m^i;

		int h=0;

		for(int j=i;j;){

			int w=j&-j;j^=w;h++;

			v=(ll)v*g[yi[w]][t]%p;

		}

		cx=(cx+(ll)v*h)%p;

	}

	printf("%d\n",cx);

    return 0;

}