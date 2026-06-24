// File Name: c.c
// Author: darkdream
// Created Time: 2013年03月01日 星期五 00时37分28秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

bool a[102][102] = {0};
int f[102];
int b[102] = {0};
int main(){

 //  freopen("input.txt","r",stdin);
 //  freopen("output.txt","w",stdout);
  int n , m , p  = 0;
  scanf("%d %d",&n,&m);
  for(int i = 1; i <= n; i++)
    {
      int  t;
      scanf("%d",&f[i]);
      if(f[i] == 0 )
      {  p++;
         b[i] = 1;
          
      }
      for (int j = 1 ; j <= f[i] ;j++)
      {
        int k ;
        scanf("%d",&k);
            a[i][k] = 1;
      }
    
    }
  for(int s = 1; s<= 3;s ++)
  for(int i = 1; i<= n; i++)
  {  if(!b[i])
      for(int j = i+1; j <= n ;j++)
      {
         for(int t = 1; t <= m ; t++)
             if(a[i][t] ==1 && a[j][t] == 1)
             {
              b[j] = 1 ;
               for (int k = 1; k <= m ;k ++)
                   a[i][k] = a[i][k] || a[j][k];
               break;
             }
      }
  }
  int sum = 0; 
  for(int i = 1; i <=  n; i++)
      if(b[i] == 0)
      { 
          sum++;
      }
  if(sum == 0)
      sum = 1;
  sum = sum-1 +p;
  printf("%d",sum );
return 0 ;
}