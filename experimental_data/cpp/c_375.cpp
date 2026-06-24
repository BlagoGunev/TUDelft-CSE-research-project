#include<iostream>
#include<queue>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<cstring>

const int maxn = 21, maxd = 9, maxs = 1 << maxd;
int n, m, d;
char map[maxn][maxn];
int turn[maxn][maxn];
int f[maxn][maxn][maxs];
bool used[maxn][maxn][maxs];
int data[maxd], sum[maxs];
int top,X[10],Y[10];
int px[] = {0, 1, 0, -1};
int py[] = {1, 0, -1, 0};

bool isok(int x, int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= m && map[x][y] == 0;
}
int DP(int x, int y)
{
	if(map[x][y] != 0)return 0;
	static queue<int> que;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++)
	       for(int s=0;s<=top;s++)
	           f[i][j][s]=100000000;
	memset(used, 0, sizeof(used));
	f[x][y][0] = 0;
	used[x][y][0] = 1;
	que.push(x);
	que.push(y);
	que.push(0);
	while(!que.empty())
	{
		int x, y, s, tx, ty, news;
		x = que.front();
		que.pop();
		y = que.front();
		que.pop();
		s = que.front();
		que.pop();
		for(int i = 0; i < 4; i++)
		{
			tx = x + px[i];
			ty = y + py[i];
			if(isok(tx, ty))
			{
				news = s;
				if(i == 1)news ^= turn[x][y];
				if(i == 3)news ^= turn[tx][ty];
				if(!used[tx][ty][news])
				{
					used[tx][ty][news] = 1;
					que.push(tx);
					que.push(ty);
					que.push(news);
					f[tx][ty][news] = f[x][y][s] + 1;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= top; i++)
		ans = max(ans, sum[i] - f[x][y][i]);
	return ans;
}
int main()
{
	//freopen("Circling Round Treasures.in", "r", stdin);
	//freopen("Circling Round Treasures.out", "w", stdout);

	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++)
	   {
            char c;
            do c=getchar(); while(c!='S'&&c!='B'&&c!='.'&&c!='#'&&!(c>='0'&&c<='9'));
            map[i][j]=c;
            if(map[i][j]=='S')
            {
                X[0]=i;Y[0]=j;map[i][j]=0;
            }else if(map[i][j]>='0'&&map[i][j]<='9')
            {
                d++;
                X[d]=i;Y[d]=j;map[i][j]-='0';
            }else if(map[i][j]=='.')map[i][j]=0;
        }
	for(int i = 1; i <= d; i++)
		scanf("%d", &data[i]);
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++)
	       if(map[i][j]=='B')
	       {
                d++;data[d]=-10000000;
                X[d]=i;Y[d]=j;
                map[i][j]=d;
            }
    top=(1<<d)-1;
	
	for(int i = 1; i <= top; i++)
	{
		for(int j = 1; j <= d; j++)
			if(i & (1 << (j - 1)))
				sum[i] += data[j];
    }
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			turn[i][j] = turn[i][j - 1];
			if(map[i][j - 1] > 0 && map[i][j-1]<9)turn[i][j] |= 1 << (map[i][j - 1] - 1);
		}
	cout << DP(X[0],Y[0]) << endl;
	return 0;
}