#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int a[6][200000],g[10],ans;
void check(int x,int y,int z)
{	
	int j,t1,t2,xx,zz;
	xx=zz=1;
	for(j=2;j<=g[y];j++)
	{
		t1=t2=0;
		while(xx<=g[x]&&a[x][xx]<a[y][j-1]) xx++;
		while(xx<=g[x]&&a[x][xx]<=a[y][j])
		{
			t1++; xx++;
		}
		while(zz<=g[z]&&a[z][zz]<a[y][j-1]) zz++;
		while(zz<=g[z]&&a[z][zz]<=a[y][j])
		{
			t2++; zz++;
		}
		if(t1!=t2) ans++;
	}
}
int main()
{
	int i,j,m,n,k,t,x,y,z,xx,yy,zz;
	scanf("%d",&n);
	if(n<=2) printf("0\n");
	else
	{
		for(i=0;i<=1;i++)
		{
			scanf("%d",&g[i]);
			for(j=1;j<=g[i];j++)
				scanf("%d",&a[i][j]);
			sort(a[i]+1,a[i]+g[i]+1);
		}
		g[4]=g[0];
		g[5]=g[1];
		memmove(a[4],a[0],sizeof(a[4]));
		memmove(a[5],a[1],sizeof(a[5]));
		x=2; y=0; z=1;
		for(i=3;i<=n;i++)
		{
			x=(x+1)%3;
			y=(y+1)%3;
			z=(z+1)%3;
			scanf("%d",&g[z]);
			for(j=1;j<=g[z];j++)
				scanf("%d",&a[z][j]);
			sort(a[z]+1,a[z]+g[z]+1);
			check(x,y,z);
		}
		check(5,4,z);
		check(4,z,y);
		printf("%d\n",ans);
	}
}