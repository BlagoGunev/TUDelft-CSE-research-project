#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
   int a1, a2, a3, a4;
   scanf("%d%d%d%d", &a1, &a2, &a3, &a4);
   if(a1 >= max(a3,a4) && a2 >= max(a3,a4) && min(a3,a4) >= max(a3,a4)-1) {
      if(a3 > a4 || (a3 == a4 && a1 >= a3+1)) {
         putchar('4');
         for(int i = 0; i < a1-a3 + ((a3==a4)?(-1):0); i++)
            putchar('4');
         putchar('7');
         for(int i = 0; i < a3-1; i++) {
            putchar('4');
            putchar('7');
         }
         for(int i = 0; i < a2-a3; i++)
            putchar('7');
         if(a3 == a4)
            putchar('4');
      } else if(a4 > a3 || (a3 == a4 && a2 >= a4 + 1)){
        for(int i = 0; i < a4; i++) {
           putchar('7');
            if(a4 > a3 && i == a4-1)
               for(int i = 0; i < a2-a4; i++)
                  putchar('7');
           putchar('4');
           if(i == 0)
              for(int i = 0; i < a1-a4; i++)
                 putchar('4');
        }
        if(a3 == a4) {
           for(int i = 0; i < a2-a4; ++i)
              putchar('7');
        }
      } else {
         printf("-1");
      }
   } else {
      printf("-1"); 
   }
   putchar('\n');
 }