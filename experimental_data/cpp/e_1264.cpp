#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int n,ans,z,px[11000],py[11000];
int mp[110][110],hw[110];
int calc()
{
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=hw[i]*(hw[i]-1)/2;
	return sum;
}
int id[11000];
void init()
{
	for(int i=1;i<=z;i++)id[i]=i;
	random_shuffle(id+1,id+z+1);
	for(int i=1;i<=z;i++)
	{
		int u=id[i];
		if(hw[px[u]]<=hw[py[u]])
			hw[px[u]]++, mp[px[u]][py[u]]=1, mp[py[u]][px[u]]=0;
		else 
			hw[py[u]]++, mp[px[u]][py[u]]=0, mp[py[u]][px[u]]=1;
	}
}

//---------------------------------------------------------------------------------

vector<int>vec[110]; int tim,v[110];
bool gofind(int x,int d)
{
	v[x]=tim;
	for(int i=0;i<vec[x].size();i++)
	{
		int y=vec[x][i];
		if(mp[x][y]==1&&v[y]!=tim)
		{
			if(d-hw[y]>=2)
			{
				mp[x][y]=0,mp[y][x]=1;
				ans+=hw[y],hw[y]++;
				return true;
			}
			else if(gofind(y,d))
			{
				mp[x][y]=0,mp[y][x]=1;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	srand(264742); int m;
	scanf("%d%d",&n,&m); z=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)mp[i][j]=2;
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		mp[x][y]=1;mp[y][x]=0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i>=j)continue;
				 if(mp[i][j]==1)hw[i]++;
			else if(mp[i][j]==0)hw[j]++;
			else 
			{
				z++;px[z]=i,py[z]=j;
				vec[i].push_back(j),vec[j].push_back(i);
			}
		}
	init();ans=calc();
	bool bk=true;
	while(bk)
	{
		bk=false;
		for(int x=1;x<=n;x++)
		{
			tim++;
			if(gofind(x,hw[x])==true)
			{
				hw[x]--;ans-=hw[x];
				bk=true;break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)printf("%d",mp[i][j]);
		printf("%d\n",mp[i][n]);
	}
	
    return 0;
}