#include<stdio.h>

int n,x,y,c,k,q[400][400];

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)for (int j=0;j<n;j++)scanf("%d",&q[i][j]);
	scanf("%d",&k);
	for (int t=0;t<k;t++){
		scanf("%d%d%d",&x,&y,&c);
		x--;
		y--;
		for (int i=0;i<n;i++)for (int j=0;j<n;j++)
		if (q[i][x]+q[y][j]+c<q[i][j])q[i][j]=q[i][x]+q[y][j]+c;
		for (int i=0;i<n;i++)for (int j=0;j<n;j++)
		if (q[i][y]+q[x][j]+c<q[i][j])q[i][j]=q[i][y]+q[x][j]+c;
		long long ans=0;
		for (int i=0;i<n;i++)for (int j=i+1;j<n;j++)ans+=q[i][j];
		printf("%I64d\n",ans);
		if (t==n-1)puts("");else printf(" ");
	}
	return 0;
}