// In the name of GOD!
// 13 / 11 / 2016
// 1395/ 08 / 23

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   int n, dp0 = 0, dpg = 0, dpc = 0;

   cin >> n;
   for(int i = 0; i < n; i++)
   {
      int a, g = dpg, c = dpc;
      
      cin >> a;
      
      if(a == 1)
         dpg = max(dp0, dpc) + 1;
      if(a == 2)
         dpc = max(dp0, dpg) + 1;
      if(a == 3)
      {
         a = dpg;
         dpg = max(dp0, dpc) + 1;
         dpc = max(dp0, a) + 1;
      }
      
      dp0 = max(dp0, max(g, c));
   }

   cout << n - max(dp0, max(dpg, dpc)) << '\n';

   return 0;
}