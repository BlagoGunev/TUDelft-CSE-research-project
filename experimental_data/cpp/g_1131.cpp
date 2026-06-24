#include <stdlib.h>
#include <time.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <deque>
using namespace std;
typedef long long int ll;
const int M=10000000+10;

int n,m;
const int E = 300000 + 10;
vector<pair<int,ll> > a[M];

struct STR{
      int h;
      ll cost;
}str[M];

int le[M],ri[M];
int stk[M];
int top = 0;
void solvel() {
      top = 0;
      le[1] = 1;
      stk[top++] = 1;
      for(int i = 2; i <= m; i++) {
            int ans = i;
            int t = i - str[i].h + 1;
            t = max(t, 1);
            while(top > 0 && stk[top - 1] >= t) {
                   ans = min(ans, le[stk[top - 1]]);
                   top--;
            }
            stk[top++] = i; le[i] = ans;
      }
}

void solver() {
      top = 0;
      ri[m] = m;
      stk[top++] = m;
      for(int i = m - 1; i >= 1; i--) {
            int ans = i;
            int t = i + str[i].h - 1;
            t = min(m, t);
            while(top > 0 && stk[top - 1] <= t) {
                   ans = max(ans, ri[stk[top - 1]]);
                   top--;
            }
            stk[top++] = i; ri[i] = ans;
      }
}
ll dp[M];
void solve() {
     dp[1] = str[1].cost;
     top = 0;
     stk[top++] = 1;
     for(int i = 2; i <= m; i++) {
           int t = le[i];
           dp[i] = str[i].cost + dp[t - 1];
           ll v1 = str[i].cost + dp[i - 1];
           dp[i] = min(v1, dp[i]);
           while(top > 0 && ri[stk[top - 1]] < i) {
                 top--;
           }
           if(top == 0) {
                  stk[top++] = i;
           } else {
                 int id = stk[top - 1];
                 v1 = str[id].cost + dp[id - 1];
                 dp[i] = min(v1, dp[i]);
                 //if(dp[stk[top - 1]] > dp[i]) stk[top++] = i;
                 if(dp[stk[top - 1] - 1] + str[stk[top - 1]].cost > dp[i - 1] + str[i].cost) stk[top++] = i;
               
           }
     }
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
  cin>>n>>m;
  for(int in = 1; in <= n; in++) {
       int ki; cin>>ki;
       for(int i = 0; i < ki; i++) {
            int h; cin>>h; a[in].push_back(make_pair(h, 0));
       }
       for(int i = 0; i < ki; i++) {
            int h; cin>>h; a[in][i].second = h;
       }
  }

   int q; cin>>q; int p = 0;
   for(int iq = 1; iq <= q; iq++) {
         int id,mul;
         cin>>id>>mul;
         for(int i = 0; i < a[id].size(); i++) {
               ++p;
               str[p].h = a[id][i].first; str[p].cost = a[id][i].second * mul;
         }
   }

  solvel(); solver();
  solve();
  ll ans = dp[m];
  cout<<ans<<endl;
  
	return 0;
}