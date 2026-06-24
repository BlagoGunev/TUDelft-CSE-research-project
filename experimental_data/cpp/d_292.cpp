#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <vector>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <set>
using namespace std;
typedef long long ll;

const int maxn = 20005;

struct line
{
  int fr, to;       
}a[maxn];

struct range
{
  int l, r, n;     
}r[maxn];

int n, m, k, ans[maxn], fa[505], t[505]; 

bool cmp(range a, range b) { return a.l < b.l; }
bool cmp2(range a, range b) { return a.r > b.r; }

int getfa(int a)
{
  return (!fa[a]) ? a : (fa[a] = getfa(fa[a]));    
}

int getfa2(int a)
{
  return (!t[a]) ? a : (t[a] = getfa2(t[a]));    
}

void deal(range k, int be, int tot)
{
  for (int i = 1; i <= n; ++i) t[i] = fa[i];
  
  for (int i = be; i < k.l; ++i)
    if (getfa2(a[i].fr) != getfa2(a[i].to))
      {
        --tot;
        t[getfa2(a[i].fr)] = getfa2(a[i].to);                   
      }
      
  ans[k.n] = tot;
}

int main()
{
  //freopen("input.in","r",stdin);
  //freopen("output.out","w",stdout);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i)
    scanf("%d%d", &a[i].fr, &a[i].to);
  scanf("%d", &k);
  for (int i = 0; i < k; ++i)
  {
    scanf("%d%d", &r[i].l, &r[i].r);
    r[i].n = i;
  }
  sort(r, r + k, cmp);
  int p = (int)floor(sqrt((double)m));
  int la = 0;
  for (int i = 1; i <= m; i += p)
  {
    int j = la;
    while (j < k && r[j].l < i + p) ++j;
    sort(r + la, r + j, cmp2);
    memset(fa, 0, sizeof(fa));
    int tot = n;
    for (int q = 1; q < i; ++ q)
      if (getfa(a[q].fr) != getfa(a[q].to))
      {
        --tot;
        fa[getfa(a[q].fr)] = getfa(a[q].to);                   
      }
    for (int q = m + 1; q >= 1; --q)
    {
      if (q != m + 1)
        if (getfa(a[q].fr) != getfa(a[q].to))
        {
          --tot;
          fa[getfa(a[q].fr)] = getfa(a[q].to);                   
        }
        
      while (la < j && r[la].r == q - 1)
      {
        deal(r[la], i, tot);
        ++la;
      }   
    }
  }
  for (int i = 0; i < k; ++i) printf("%d\n", ans[i]);
 // fclose(stdin);fclose(stdout);    
}