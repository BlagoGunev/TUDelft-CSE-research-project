#include<cstdio>

#include<cstring>

#include<iostream>



#define nn 1010

#define Mod 1000000007

using namespace std;



int f[nn][nn][2][2][2],n,m,g[nn],fec[nn],c[nn][nn];



int main()

{

	scanf("%d%d",&n,&m);

	

	f[1][0][0][0][0]=1;

	if(n>1)f[1][1][0][0][1]=1;

	

	for (int i=1;i<n;i++)

	for (int j=0;j<=i;j++)

	for (int A=0;A<=1;A++)

	for (int B=0;B<=1;B++)

	for (int C=0;C<=1;C++)if(f[i][j][A][B][C])

	{

		f[i+1][j][B][C][0]=(f[i+1][j][B][C][0]+f[i][j][A][B][C])%Mod;

		if (!B) f[i+1][j+1][1][C][0]=(f[i+1][j+1][1][C][0]+f[i][j][A][B][C])%Mod;

		if (i+1<n) f[i+1][j+1][B][C][1]=(f[i+1][j+1][B][C][1]+f[i][j][A][B][C])%Mod;

	}

	

	for (int i=0;i<=n;i++)

	for (int A=0;A<=1;A++)

	for (int B=0;B<=1;B++)

	for (int C=0;C<=1;C++) g[i]=(g[i]+f[n][i][A][B][C])%Mod;

	

	c[0][0]=1;

	for (int i=1;i<=n;i++){

		c[i][0]=1;

		for (int j=1;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%Mod;

	}

	

	fec[0]=1;

	for (int i=1;i<=n;i++) fec[i]=fec[i-1]*1ll*i%Mod;

	for (int i=0;i<=n;i++) g[i]=g[i]*1ll*fec[n-i]%Mod;

	for (int i=n-1;i>=m;i--)

	for (int j=i+1;j<=n;j++)

	g[i]=(g[i]+Mod-g[j]*1ll*c[j][i]%Mod)%Mod;

	printf("%d\n",g[m]);

}