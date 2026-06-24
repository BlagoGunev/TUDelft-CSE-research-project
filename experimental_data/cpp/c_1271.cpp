#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
inline int Get_Int()
{
	char x=getchar();
	int num=0,bj=1;
	while(x<'0'||x>'9')
	{
		if(x=='-') bj=-1;
		x=getchar();
	}
	while(x>='0'&&x<='9')
	{
		num=num*10+x-'0';
		x=getchar();
	}
	return num*bj;

 }

int n,x,y,nx,ny,i,j,k,S[5],L[5];
int main()
{ 
    n=Get_Int();
    nx=Get_Int();ny=Get_Int();
    for(i=1;i<=n;i++)
    {
    	x=Get_Int();y=Get_Int();
    	if(y==ny)
    	{
    		if(x<nx) L[3]++;
    		else L[1]++; 
		}
		else if(x==nx)
		{
			if(y<ny) L[4]++;
			else L[2]++;
		}
		else {
			if(x<nx&&y<ny) S[3]++;
			else if(x>nx&&y>ny) S[1]++;
			else if(x<nx&&y>ny) S[2]++;
			else if(x>nx&&y<ny) S[4]++;
		}
	}
	int G[5];
	G[1]=S[1]+S[4]+L[1];
	G[2]=S[1]+S[2]+L[2];
	G[3]=S[2]+S[3]+L[3];
	G[4]=S[3]+S[4]+L[4];
	int ans=max(max(G[1],G[2]),max(G[4],G[3]));
	printf("%d\n",ans); 
	if(ans==G[1])
	{
		printf("%d %d",nx+1,ny);
	}
	else if(ans==G[2])
	{
		printf("%d %d",nx,ny+1); 
	}
	else if(ans==G[3])
	{
		printf("%d %d",nx-1,ny);
	 } 
	 else if(ans==G[4])
	 {
	 	printf("%d %d",nx,ny-1);
	 }
	return 0;
}