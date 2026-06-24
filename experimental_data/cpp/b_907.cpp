#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int x,y;
char st[20][10][10];
int main()
{
	scanf("%s",st[1][1]+1);
	scanf("%s",st[2][1]+1);
	scanf("%s",st[3][1]+1);
	scanf("%s",st[1][2]+1);
	scanf("%s",st[2][2]+1);
	scanf("%s",st[3][2]+1);
	scanf("%s",st[1][3]+1);
	scanf("%s",st[2][3]+1);
	scanf("%s",st[3][3]+1);
	scanf("%s",st[4][1]+1);
	scanf("%s",st[5][1]+1);
	scanf("%s",st[6][1]+1);
	scanf("%s",st[4][2]+1);
	scanf("%s",st[5][2]+1);
	scanf("%s",st[6][2]+1);
	scanf("%s",st[4][3]+1);
	scanf("%s",st[5][3]+1);
	scanf("%s",st[6][3]+1);
	scanf("%s",st[7][1]+1);
	scanf("%s",st[8][1]+1);
	scanf("%s",st[9][1]+1);
	scanf("%s",st[7][2]+1);
	scanf("%s",st[8][2]+1);
	scanf("%s",st[9][2]+1);
	scanf("%s",st[7][3]+1);
	scanf("%s",st[8][3]+1);
	scanf("%s",st[9][3]+1);
	scanf("%d%d",&x,&y);
	int nx=x/3;
	if (x%3!=0) nx++;
	int ny=y/3;
	if (y%3!=0) ny++;
	x-=(nx-1)*3;
	y-=(ny-1)*3;
	int tmp=(x-1)*3+y;
	bool flag=0;
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
		{
			if (st[tmp][i][j]=='.') flag=1;
		}
	if (!flag)
	{
		for (int i=1;i<=9;i++)
			for (int j=1;j<=3;j++)
				for (int k=1;k<=3;k++)
					if (st[i][j][k]=='.') st[i][j][k]='!';
	}
	else
	{
		for (int i=1;i<=3;i++)
			for (int j=1;j<=3;j++)
			{
			if (st[tmp][i][j]=='.') st[tmp][i][j]='!';
			}
	}
	putchar(st[1][1][1]);
	putchar(st[1][1][2]);
	putchar(st[1][1][3]);
	putchar(' ');
	putchar(st[2][1][1]);
	putchar(st[2][1][2]);
	putchar(st[2][1][3]);
	putchar(' ');
	putchar(st[3][1][1]);
	putchar(st[3][1][2]);
	putchar(st[3][1][3]);
	putchar('\n');
	putchar(st[1][2][1]);
	putchar(st[1][2][2]);
	putchar(st[1][2][3]);
	putchar(' ');
	putchar(st[2][2][1]);
	putchar(st[2][2][2]);
	putchar(st[2][2][3]);
	putchar(' ');
	putchar(st[3][2][1]);
	putchar(st[3][2][2]);
	putchar(st[3][2][3]);
	putchar('\n');
	putchar(st[1][3][1]);
	putchar(st[1][3][2]);
	putchar(st[1][3][3]);
	putchar(' ');
	putchar(st[2][3][1]);
	putchar(st[2][3][2]);
	putchar(st[2][3][3]);
	putchar(' ');
	putchar(st[3][3][1]);
	putchar(st[3][3][2]);
	putchar(st[3][3][3]);
	putchar('\n');
	putchar('\n');
	putchar(st[4][1][1]);
	putchar(st[4][1][2]);
	putchar(st[4][1][3]);
	putchar(' ');
	putchar(st[5][1][1]);
	putchar(st[5][1][2]);
	putchar(st[5][1][3]);
	putchar(' ');
	putchar(st[6][1][1]);
	putchar(st[6][1][2]);
	putchar(st[6][1][3]);
	putchar('\n');
	putchar(st[4][2][1]);
	putchar(st[4][2][2]);
	putchar(st[4][2][3]);
	putchar(' ');
	putchar(st[5][2][1]);
	putchar(st[5][2][2]);
	putchar(st[5][2][3]);
	putchar(' ');
	putchar(st[6][2][1]);
	putchar(st[6][2][2]);
	putchar(st[6][2][3]);
	putchar('\n');
	putchar(st[4][3][1]);
	putchar(st[4][3][2]);
	putchar(st[4][3][3]);
	putchar(' ');
	putchar(st[5][3][1]);
	putchar(st[5][3][2]);
	putchar(st[5][3][3]);
	putchar(' ');
	putchar(st[6][3][1]);
	putchar(st[6][3][2]);
	putchar(st[6][3][3]);
	putchar('\n');
	putchar('\n');
	putchar(st[7][1][1]);
	putchar(st[7][1][2]);
	putchar(st[7][1][3]);
	putchar(' ');
	putchar(st[8][1][1]);
	putchar(st[8][1][2]);
	putchar(st[8][1][3]);
	putchar(' ');
	putchar(st[9][1][1]);
	putchar(st[9][1][2]);
	putchar(st[9][1][3]);
	putchar('\n');
	putchar(st[7][2][1]);
	putchar(st[7][2][2]);
	putchar(st[7][2][3]);
	putchar(' ');
	putchar(st[8][2][1]);
	putchar(st[8][2][2]);
	putchar(st[8][2][3]);
	putchar(' ');
	putchar(st[9][2][1]);
	putchar(st[9][2][2]);
	putchar(st[9][2][3]);
	putchar('\n');
	putchar(st[7][3][1]);
	putchar(st[7][3][2]);
	putchar(st[7][3][3]);
	putchar(' ');
	putchar(st[8][3][1]);
	putchar(st[8][3][2]);
	putchar(st[8][3][3]);
	putchar(' ');
	putchar(st[9][3][1]);
	putchar(st[9][3][2]);
	putchar(st[9][3][3]);
	putchar('\n');
	return 0;
}