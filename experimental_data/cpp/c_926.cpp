#include<stdio.h>
#include<set>

using namespace std;

signed main() {
 int n; scanf("%d", &n);
 set<int> zero, one;
 int z = 0, o = 0;
 for(int i = 0; i < n; ++i) {
  int t; scanf("%d", &t);
  if(t) {
   if(z) zero.insert(z), z = 0;
   ++o;
  }
  else {
   if(o) one.insert(o), o = 0;
   ++z;
  }
 }
 if(z) zero.insert(z);
 if(o) one.insert(o);
 if((zero.size() == 1 && one.size() == 1 && *zero.begin() == *one.begin()) || *one.begin() == n || *zero.begin() == n) {
  puts("YES");
 }
 else puts("NO");
}