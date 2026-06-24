#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#define MAXN 200005
#define MAXM 200005
using namespace std;
int N,M,D[MAXN],Ans[MAXN];

int en[MAXM],las[MAXN],nex[MAXM],tot;
void ADD(int x,int y)
{
	en[++tot]=y;
	nex[tot]=las[x];
	las[x]=tot;
}

int main()
{
	int i,x,y,j;
	priority_queue<int>Q;
	
	scanf("%d%d",&N,&M);
	for(i=1;i<=M;i++)
	{
		scanf("%d%d",&x,&y);
		D[x]++;
		ADD(y,x);
	}
	
	for(i=1;i<=N;i++)if(D[i]==0)Q.push(i);
	
	j=N;
	while(Q.size())
	{
		x=Q.top();Q.pop();
		Ans[x]=j--;
		for(i=las[x];i;i=nex[i])
		{
			y=en[i];
			if(D[y]>0)
			{
				D[y]--;
				if(D[y]==0)Q.push(y);
			}
		}
	}
	
	for(i=1;i<=N;i++)printf("%d ",Ans[i]);
}