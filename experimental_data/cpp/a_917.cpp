#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i, s, t) for(i = s; i <= t; ++i)
#define dep(i, s, t) for(i = s; i >= t; --i)

using namespace std;

int n, ans;
char s[5010];

int main() {
 int i, j, t1, t2;
 scanf("%s", s+1); n = strlen(s+1);
 rep(i, 1, n) {
  t1 = t2 = 0;
  rep(j, i, n) {
   if(s[j] == '(') ++t1, ++t2; else
   if(s[j] == '?') {++t1; if(t2) --t2;}
   else {
    if(t1) --t1; else break;
    if(t2) --t2;
   }
   if((j-i&1) && !t2) ++ans;
  }
 }
 printf("%d\n", ans);
 return 0;
}