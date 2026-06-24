#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
#ifdef hk_cnyali
 freopen("C.in", "r", stdin);
 freopen("C.out", "w", stdout);
#endif
 scanf("%d", &N);
 int pre = -1;
 int now = 0;
 int sum = 0;
 for (int i = 1; i <= N; ++i)
 {
  int x; scanf("%d", &x);
  if (x == pre) ++sum;
  else 
  {
   if (now && sum != now)
   {
    cout<<"NO"<<endl;
    return 0;
   }
   now = sum;
   sum = 1;
  }
  pre = x;
 }
 if (now && sum != now)
 {
  cout<<"NO"<<endl;
  return 0;
 }
 cout<<"YES"<<endl;
 return 0;
}