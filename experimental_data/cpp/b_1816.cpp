#include<bits/stdc++.h>
using namespace std;
int a[3][200010];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int l=1,r=n+1;
		a[1][1]=2*n;
		int i=2,j=1,c=1;
		while(i<=n)
		{
			if(c%2)
			{
				a[2][j++]=l++;
				a[1][i++]=l++;
			}
			else
			{
				a[2][j++]=r++;
				a[1][i++]=r++;	
			}
			c++;
		}
		a[2][n]=r;
		for(int i=1;i<=2;i++)
		{
			for(int j=1;j<=n;j++) printf("%d ",a[i][j]);
			printf("\n");
		}
	}
}