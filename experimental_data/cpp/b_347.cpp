#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a[100005];

int main()
{
  int n ;
  scanf("%d",&n);
  int ok = 0 ;
  int sum = 0;
  for(int i = 0 ;i <n ;i ++)
  {
     scanf("%d",&a[i]);
     if(a[i] == i)
         sum ++;
  }
 // printf("%d\n",sum);
  for(int i = 0; i < n;i  ++)
  {
      if(a[i] != i && a[a[i]] == i)
          ok = 1;
        
  }
  if(ok)
      sum +=2;
  else if(sum != n)
      sum ++;
  printf("%d\n",sum);
  return 0;
}