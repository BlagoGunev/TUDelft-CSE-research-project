#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e6 + 5;
int px[] = {0, 0, 1, -1};
int py[] = {1, -1, 0, 0};
int dp[505][505][25]; 
int d[505][505][4];
int n, m, t;
int dfs(int x, int y, int k)
{
//	cout << "B: " << dp[0][0][k] << endl;
	if(!k) return 0;
	if(dp[x][y][k]!=-1) return dp[x][y][k];
	int minv = INF; 
	for(int i=0; i<4; i++)
	{
		int rx = x + px[i];
		int ry = y + py[i];
		if(rx>=0 && rx<n && ry>=0 && ry<m)
			minv = min(minv, dfs(rx, ry, k-1)+d[x][y][i]);//, cout << "T: " << d[x][y][i] << " " << x << " " << y << " " << rx << " " << ry << " " << i <<  endl;
	} 
	return dp[x][y][k] = minv;
}
int Get(int x, int y, int k)
{
	if(k&1) return -1;
	else return dfs(x, y, k/2)*2;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> t;
	memset(dp, -1, sizeof(dp));
	for(int i=0; i<n; i++)
		for(int j=0; j<m-1; j++)
		{
			int x;
			cin >> x;
			d[i][j][0] = x;
			d[i][j+1][1] = x;
		}
	for(int i=0; i<n-1; i++)
		for(int j=0; j<m; j++)
		{
			int x;
			cin >> x;
			d[i][j][2] = x;
			d[i+1][j][3] = x;
		}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cout << Get(i, j, t) << " ";
		cout << endl;
	}
	return 0;
}