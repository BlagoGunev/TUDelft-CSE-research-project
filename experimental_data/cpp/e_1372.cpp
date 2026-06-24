// LUOGU_RID: 91853162
#include<iostream>

#include<cstdio>

using namespace std;

namespace code{

	inline int read(){

		int a=0,b=1;char s=getchar();

		while(s<48||s>57){if(s=='-'){b=-1;}s=getchar();}

		while(s>=48&&s<=57)a=(a<<1)+(a<<3)+s-48,s=getchar();

		return a*b;

	}

	int n,m,s[105][105][105],f[105][105];

	inline void main(){

		n=read(),m=read();

		for(int i=1;i<=n;i=-~i){

			int K=read();

			for(int j=1;j<=K;j=-~j){

				int l=read(),r=read();

				for(int k=l;k<=r;k=-~k)++s[k][l][r];

			}

		}

		for(int k=1;k<=m;k=-~k){

			for(int len=2;len<=m;len=-~len){

				for(int l=1,r=len;r<=m;l=-~l,r=-~r){

					s[k][l][r]+=s[k][l][r-1]+s[k][l+1][r]-s[k][l+1][r-1];

				}

			}

		}

		for(int len=1;len<=m;len=-~len){

			for(int l=1,r=len;r<=m;l=-~l,r=-~r){

				for(int k=l;k<=r;k=-~k){

					f[l][r]=max(f[l][r],f[l][k-1]+f[k+1][r]+s[k][l][r]*s[k][l][r]);

				}

			}

		}

		printf("%d\n",f[1][m]);

	}

}

int main(){return code::main(),0;}