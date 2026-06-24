#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
#define REP(i, a, b) for(int i = int(a); i <= int(b); i++)
#define LOOP(i, v) for(int i = 0; i < v.size(); i++)
#define EPS 1e-9
#define INF 1e12
#define debug(x) cerr << "DEBUG : " << (#x) << " => " << (x) << endl

int dad[5010];
vi fils[5010];
int a, b, c, d;
int comp[4];
int found;

int dp(int x)
{
  if(x == a || x == b || x == c || x == d) found = x;
  int ans = 0;
  LOOP(i, fils[x])
  {
    ans += dp(fils[x][i]);
  }
  if(fils[x].size() == 0) ans++;
  return ans;
}

vector<int> others;

int main()
{
  int n;
  
  scanf("%d", &n);
  scanf("%d %d %d %d", &a, &b, &c, &d);
  REP(i, 2, n)
  {
    scanf("%d", &dad[i]);
    fils[dad[i]].push_back(i);
  }
  
  int tot = 0;
  
  LOOP(i, fils[1])
  {
    int f = fils[1][i];
    found = -1;
    int p = dp(f);
    if(found == -1) others.push_back(p);
    else if(found == a) comp[0] = p;
    else if(found == b) comp[1] = p;
    else if(found == c) comp[2] = p;
    else if(found == d) comp[3] = p;
    tot += p;
  }
  
  /*
  printf("%d %d %d %d\n", comp[0], comp[1], comp[2], comp[3]);
  LOOP(i, others) printf("%d ", others[i]);
  printf("\n");
  */
  
  bool ok = true;
  
  if(tot % 2 == 1) ok = false;
  else
  {
    int obj = tot/2-1; // On doit en mettre obj entre comp[0] et comp[2], et idem entre comp[1] et comp[3]
    
    //printf("obj = %d\n", obj);
    
    bool cando[3000];
    REP(i, 0, obj) cando[i] = false;
    cando[0] = true;
    LOOP(j, others)
    {
      for(int i = obj-others[j]; i >= 0; i--)
      {
        if(cando[i]) cando[i+others[j]] = true;
      }
    }
    
    /*
    printf("cando = ");
    REP(i, 0, obj) printf("%d", cando[i]);
    printf("\n");
    */
    
    int maxi = obj - comp[1];
    int mini = obj - comp[1] - (comp[0]-1) - (comp[2]-1);
    mini = max(mini, 0);
    
    //printf("[%d %d]\n", mini, maxi);
    
    if(maxi < 0) ok = false;
    else
    {
      bool whynot = false;
      REP(i, mini, maxi)
      {
        if(cando[i]) whynot = true;
      }
      if(!whynot) ok = false;
    }
    
    
    maxi = obj - comp[2];
    mini = obj - comp[2] - (comp[1]-1) - (comp[3]-1);
    mini = max(mini, 0);
    
    //printf("[%d %d]\n", mini, maxi);
    
    if(maxi < 0) ok = false;
    else
    {
      bool whynot = false;
      REP(i, mini, maxi)
      {
        if(cando[i]) whynot = true;
      }
      if(!whynot) ok = false;
    }
  }
  
  if(ok) printf("YES\n");
  else printf("NO\n");


  return 0;
}