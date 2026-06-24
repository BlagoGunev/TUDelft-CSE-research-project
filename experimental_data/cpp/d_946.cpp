#include <bits/stdc++.h>
#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<iostream>  
#include<cstdio>  
#include<fstream>  
#include<iomanip>
#include<algorithm>  
#include<cmath>  
#include<deque>  
#include<vector>
#include<bitset>
#include<queue>  
#include<string>  
#include<cstring>  
#include<map>  
#include<stack>  
#include<set>
#include<functional>
#define pii pair<int, int>
#define mod 1000000007
#define mp make_pair
#define pi acos(-1)
#define eps 0.00000001
#define mst(a,i) memset(a,i,sizeof(a))
#define all(n) n.begin(),n.end()
#define lson(x) ((x<<1))  
#define rson(x) ((x<<1)|1) 
#define inf 0x3f3f3f3f
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn = 505 + 5;
string a[maxn];
vector<int>tt[maxn], sub[maxn];
int dp[maxn][maxn];
int main()
{
 ios::sync_with_stdio(false);
 cin.tie(0); cout.tie(0);
 int i, j, k, m, n;
 cin >> n >> m >> k;
 for (int i = 1; i <= n; ++i)cin >> a[i];
 for (int i = 1; i <= n; ++i)a[i] = '0' + a[i];
 for (int i = 1; i <= n; ++i)
 {
  for (int j = 1; j <= m; ++j)if (a[i][j] == '1')tt[i].push_back(j);
  int l = 0, r = tt[i].size() - 1;
  sub[i].push_back(0);
  if (tt[i].size() == 0)continue;
  int tpsum = *tt[i].rbegin() - *tt[i].begin() + 1;
  for (int j = 1; j < tt[i].size(); ++j)
  {
   int minans = inf;
   for (int ll = 0; ll <= j; ++ll)
   {
    int rr = j - ll;
    minans = min(minans, tt[i][tt[i].size() - rr - 1] - tt[i][ll] + 1);
   }
   sub[i].push_back(tpsum - minans);
  }
  sub[i].push_back(tpsum);

 }
 int sumles = 0;
 for (int i = 1; i <= n; ++i)
 {
  if (tt[i].size() == 0)continue;
  else
   sumles += *tt[i].rbegin() - *tt[i].begin() + 1;
 }

 for (int i = 1; i <= n; ++i)
 {
  for (int num = 0; num < sub[i].size(); ++num)
  {
   for (int j = num; j <= k; ++j)
   {
    dp[i][j] = max(dp[i][j], dp[i - 1][j - num] + sub[i][num]);
   }
  }
 }
 cout<<sumles-dp[n][k]<<endl;
 return 0;
}