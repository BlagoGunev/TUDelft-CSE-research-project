#include<cstdio>
const int MaxN=100000;
inline const void read(int &ans)
{
	ans=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
		ans=ans*10+c-48,c=getchar();
	return;
}
int n,cnt[MaxN+1],id[MaxN+2][4];
struct Node
{
	int x,y,z;
}node[MaxN+1];
int del[MaxN+1],ans[MaxN+1],ans2[MaxN+1];
int main()
{
	int i,nxt=0,last=0;
	read(n);
	for(i=1;i<=n-2;++i)
		read(node[i].x),read(node[i].y),read(node[i].z),
		id[node[i].x][++cnt[node[i].x]]=i,
			id[node[i].y][++cnt[node[i].y]]=i,
				id[node[i].z][++cnt[node[i].z]]=i;
	for(i=1;i<=n;++i)
		if(cnt[i]==1)
			if(!nxt)
				nxt=i;
			else
				last=i;
	int tot=0,now;
	while(++tot<n-2)
	{
		now=nxt,ans[now]=1,ans2[tot]=now;
		printf("%d ",now);
		for(i=1;i<=3;++i)
			if(id[now][i]&&!del[id[now][i]])
			{
				del[id[now][i]]=1;
				if(--cnt[node[id[now][i]].x]==1)
					nxt=node[id[now][i]].x;
				if(--cnt[node[id[now][i]].y]==1)
					nxt=node[id[now][i]].y;
				if(--cnt[node[id[now][i]].z]==1)
					nxt=node[id[now][i]].z;
			}
	}
	--tot;
	for(i=1;i<=3;++i)
		if(id[ans2[tot-1]][i])
		{
			if(!ans[node[id[ans2[tot-1]][i]].x])
			{
				ans[node[id[ans2[tot-1]][i]].x]=1;
				printf("%d ",node[id[ans2[tot-1]][i]].x);
				break;
			}
			if(!ans[node[id[ans2[tot-1]][i]].y])
			{
				ans[node[id[ans2[tot-1]][i]].y]=1;
				printf("%d ",node[id[ans2[tot-1]][i]].y);
				break;
			}
			if(!ans[node[id[ans2[tot-1]][i]].z])
			{
				ans[node[id[ans2[tot-1]][i]].z]=1;
				printf("%d ",node[id[ans2[tot-1]][i]].z);
				break;
			}
		}
	ans[last]=1;
	for(i=1;i<=n;++i)
		if(!ans[i])
			printf("%d ",i);
	printf("%d\n",last);
	return 0;
}