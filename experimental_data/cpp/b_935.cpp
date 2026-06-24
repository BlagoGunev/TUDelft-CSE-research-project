#include <stdio.h>
int main() {
 char dir;
 int n;
 while (scanf("%d",&n)!=EOF) {
  int u=0,r=0,tmp=0,res=0;
  getchar();
  for (int i=0; i<n; i++) {
   dir = getchar();
   if (dir=='U') {
    u++;
    if (u>r) {
     if (tmp==2) res++;
     tmp = 1;
    }
   } else {
    r++;
    if (u<r) {
     if (tmp==1) res++;
     tmp = 2;
    }
   }
  }
  printf("%d\n",res);
 }
 return 0;
}