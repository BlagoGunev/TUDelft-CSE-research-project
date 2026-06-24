#include<iostream>
#include<set>
#include<climits>
#include<vector>

using namespace std;

const int N = 1e5+5, inf = 1e9;
vector<int> child[N];
int dp[N][2];
string s;

void dfs(int v, int p = 0)
{
  for(int u : child[v])
  {
      dfs(u, v);
  }
  
  if(s[v - 1] == 'P' || s[v-1] == 'C')
  {
    int cnt = 0;
    for(int u : child[v])
        cnt = min(cnt + min(dp[u][0] + 1, dp[u][1]), inf);
    dp[v][1] = cnt;
  }
  
  if(s[v - 1] == 'S' || s[v - 1] == 'C')
  {
    int cnt = 0;
    for(int u : child[v])
    {
        cnt = min(cnt + min(dp[u][0], dp[u][1] + 1), inf);
    }
    dp[v][0] = cnt;
  }
  
}

void solve()
{
  int n;
  cin >> n;
  child[1].clear();
  for(int i = 2; i <= n; i ++)
  {
    int p;
    cin >> p;
    child[p].push_back(i);
    child[i].clear();
  }
  cin >> s;
  for(int i = 1; i <= n; i++)
  {
    dp[i][0] = dp[i][1] = inf;
  }
  
  dfs(1);
  cout << min(dp[1][0], dp[1][1]) << endl;
  
}

int main()
{
  int t;
  cin >> t;

  while(t--)
  {
   solve();
    
  }
  return 0;
}