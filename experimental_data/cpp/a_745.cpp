#include<stdio.h>
int main()
{
	int n,i,ans=0,l,j,k;
	char s[100][100];
	scanf("%s",s[0]);
	for(i=0;s[0][i]!='\0';i++);
	l=i;
	for(i=1;i<l;i++)
	{
		s[i][0]=s[i-1][l-1];
		for(j=1;j<l;j++)
		{
			s[i][j]=s[i-1][j-1];
		}
		s[i][j]='\0';
		//printf("%s\n",s[i]);
	}
	int A[l];
	for(i=0;i<l;i++)		A[i]=0;
	ans=0;int t=0;
	for(i=0;i<l;i++)
	{
		int flag=0;
		for(j=0;j<l;j++)
		{
			if(j==i||A[i]==1);
			else
			{
				int f=0;
				for(k=0;k<l;k++)
				{
					if(s[i][k]!=s[j][k])
					{
						f=1;
						break;
					}
				}
				if(f==0)
				{
					A[j]=1;				
				}		
			}
		}
	}
	for(i=0;i<l;i++)
		if(A[i]==0)
			ans++;
	printf("%d",ans);		
		
}