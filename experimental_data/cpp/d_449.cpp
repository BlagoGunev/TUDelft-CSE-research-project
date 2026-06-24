#include<cstdio>

#include<iostream>

#include<cstring>

const int maxn=1052333,modd=1000000007;

int f[maxn],a[maxn],two[maxn],n1[maxn];

int i,j,k,n,m;



int ra,fh;char rx;

inline int read(){

	rx=getchar(),ra=0,fh=1;

	while((rx<'0'||rx>'9')&&rx!='-')rx=getchar();

	if(rx=='-')fh=-1,rx=getchar();

	while(rx>='0'&&rx<='9')ra*=10,ra+=rx-48,rx=getchar();return ra*fh;

}

inline void MOD(int &x){

	if(x>=modd)x-=modd;else if(x<0)x+=modd;

}

int main(){

	n=read();int mx=(1<<20)-1;

	for(i=1;i<=n;i++)f[a[i]=read()]++,mx=a[i]>mx?a[i]:mx;

	for(i=two[0]=1;i<=n;i++)MOD(two[i]=two[i-1]<<1);

	for(i=19;i>=0;i--)

		for(j=0;j<=mx;j++)

			if(!((j>>i)&1))f[j]+=f[j|(1<<i)];

	int ans=0;

	for(i=0;i<=mx;i++){//printf("i:%d  f:%d\n",i,f[i]);

		n1[i]=n1[i>>1]+(i&1);

		if(n1[i]&1)MOD(ans-=two[f[i]]);else MOD(ans+=two[f[i]]);

	}

	printf("%d\n",ans);

}