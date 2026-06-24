#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#include <bitset>

template<class Num>void read(Num &x)
{
    char c; int flag = 1;
    while((c = getchar()) < '0' || c > '9')
        if(c == '-') flag *= -1;
    x = c - '0';
    while((c = getchar()) >= '0' && c <= '9')
        x = (x<<3) + (x<<1) + (c-'0');
    x *= flag;
}
template<class Num>void write(Num x)
{
    if(!x) {putchar('0');return;}
    if(x < 0) putchar('-'), x = -x;
    static char s[20];int sl = 0;
    while(x) s[sl++] = x%10 + '0',x /= 10;
    while(sl) putchar(s[--sl]);
}

const int maxn = 155, inf = 0x3f3f3f3f;
#define eu second.first
#define ev second.second
#define ew first

int n, m;
std::pair<int, std::pair<int,int> > edge[maxn];
std::bitset<maxn> map[maxn], trans[maxn];
int dist[maxn][maxn];
int ans = inf;

void mult(std::bitset<maxn> *a,std::bitset<maxn> *b)
{
 std::bitset<maxn> r[maxn];
 for(int i = 1; i <= n; i++)
  for(int j = 1; j <= n; j++)
   if(a[i][j]) r[i] |= b[j];
 for(int i = 1; i <= n; i++) a[i] = r[i];  
}
void trans_power(int k)
{
 static std::bitset<maxn> a[maxn];
 
 for(int i = 1; i <= n; i++)
  a[i] = trans[i];
  
 while(k)
 {
  if(k&1) mult(map, a);
  mult(a, a), k >>= 1;
 }
}
int main()
{
 int u, v, w;
 
#ifndef ONLINE_JUDGE
 freopen("576D.in","r",stdin);
 freopen("576D.out","w",stdout);
#endif 
 
 read(n), read(m);
 
 for(int i = 1; i <= n; i++)
  for(int j = 1; j <= n; j++)
  {
   if(i != j)
    dist[i][j] = inf;
   else
    dist[i][j] = 0;
    
   map[i][j] = i == j;
   trans[i][j] = false;
  }
 
 for(int i = 1; i <= m; i++)
 {
  read(u), read(v), read(w);
  edge[i] = std::make_pair(w, std::make_pair(u, v));
 } 
 
 std::sort(edge + 1, edge + m + 1);
 
 for(int i = 1, j = 1; i <= m; i = j)
 {
  while(j <= m && edge[i].ew == edge[j].ew)
  {
   u = edge[j].eu, v = edge[j].ev;
   
   for(int x = 1; x <= n; x++)
    for(int y = 1; y <= n; y++)
    {
     int l = dist[x][u] + dist[v][y] + 1;
     dist[x][y] = std::min(l, dist[x][y]);
    }
   j++; 
  }
  
  trans_power(edge[i].ew - edge[i - 1].ew);
  
  for(int x = 1; x <= n; x++)
   if(map[1][x] && dist[x][n] < inf)
    ans = std::min(edge[i].ew + dist[x][n], ans);
    
  for(int k = i; k < j; k++)
   trans[edge[k].eu][edge[k].ev] = true;
 }
 
 if(ans < inf) write(ans);
 else printf("Impossible");
 
#ifndef ONLINE_JUDGE 
 fclose(stdin);
 fclose(stdout);
#endif 
 return 0;
}