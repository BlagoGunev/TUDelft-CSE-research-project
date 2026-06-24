#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 100010
bool visit[MAX],mark[MAX];
int main()
{
	int t,i,j,in[MAX];
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&in[i]);
		if(!visit[in[i]])
		{
			mark[i]=true;
			visit[in[i]]=true;
		}
	}
	int min=1;
	for(i=1;i<=t;i++)
	{
		if(visit[in[i]])
		{
			if(!mark[i]||in[i]>t)
			{
				for(j=min;j<=t;j++)
				{
					if(!visit[j])
					{
						visit[j]=true;
						printf("%d ",j);
						if(min<j)
						min=j+1;
						break;
					}
				}
			}
			else
			printf("%d ",in[i]);
		}
	}
	return 0;
}