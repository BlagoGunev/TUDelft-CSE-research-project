#include<bits/stdc++.h>
using namespace std;
int n,m;
int bia[3011],pre[5011],v[5011],num;
void addedge(int l,int r)
{
	++num;
	v[num]=r;pre[num]=bia[l];bia[l]=num;
}
int d[3011][3011];
int sp[100011];
int inx[3011][2],iny[3011][2];
int outx[3011][2],outy[3011][2];
void spfa(int st)
{
	int q,p,l,r;
	q=0;p=1;l=st;
	sp[1]=st;
	while (q<p)
	{
		l=sp[++q];
		for (int i=bia[l];i!=0;i=pre[i])
		{
			r=v[i];
			if (r==st) continue;
			if (d[st][r]==0||d[st][r]>d[st][l]+1)
			{
				d[st][r]=d[st][l]+1;
				sp[++p]=r;
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	int l,r;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		addedge(l,r);
	}
	for (int i=1;i<=n;i++) spfa(i);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (i==j||d[i][j]==0) continue;
			if (inx[j][1]<d[i][j])
			{
				inx[j][1]=d[i][j];
				iny[j][1]=i;
				if (inx[j][0]<inx[j][1])
				{
					swap(inx[j][0],inx[j][1]);
					swap(iny[j][0],iny[j][1]);
				}
			}
			
			if (outx[i][1]<d[i][j])
			{
				outx[i][1]=d[i][j];
				outy[i][1]=j;
				if (outx[i][0]<outx[i][1])
				{
					swap(outx[i][0],outx[i][1]);
					swap(outy[i][0],outy[i][1]);
				}
			}
			
		}
	}
	int ans=0;
	
	int aa,ab,ac,ad;
	
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (i==j||d[i][j]==0) continue;
			
				if (iny[i][0]!=outy[j][0]&&iny[i][0]!=0&&outy[j][0]!=0&&iny[i][0]!=j&&outy[j][0]!=i)
				if (ans<inx[i][0]+d[i][j]+outx[j][0])
				{
					ans=inx[i][0]+d[i][j]+outx[j][0];
					aa=iny[i][0];ab=i;ac=j;ad=outy[j][0];
				}
			
				if (iny[i][1]!=outy[j][0]&&iny[i][1]!=0&&outy[j][0]!=0&&iny[i][1]!=j&&outy[j][0]!=i)
				if (ans<inx[i][1]+d[i][j]+outx[j][0])
				{
					ans=inx[i][1]+d[i][j]+outx[j][0];
					aa=iny[i][1];ab=i;ac=j;ad=outy[j][0];
				}
				
				
				if (iny[i][0]!=outy[j][1]&&iny[i][0]!=0&&outy[j][1]!=0&&iny[i][0]!=j&&outy[j][1]!=i)
				if (ans<inx[i][0]+d[i][j]+outx[j][1])
				{
					ans=inx[i][0]+d[i][j]+outx[j][1];
					aa=iny[i][0];ab=i;ac=j;ad=outy[j][1];
				}
				
				
				
				if (iny[i][1]!=outy[j][1]&&iny[i][1]!=0&&outy[j][1]!=0&&iny[i][1]!=j&&outy[j][1]!=i)
				if (ans<inx[i][1]+d[i][j]+outx[j][1])
				{
					ans=inx[i][1]+d[i][j]+outx[j][1];
					aa=iny[i][1];ab=i;ac=j;ad=outy[j][1];
				}
			
		}
	}
	cout<<aa<<" "<<ab<<" "<<ac<<" "<<ad;
}