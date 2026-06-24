#include<stdio.h>
int cost,h,m;
int y(int a)
{
 while(a)
 {
  if(a%10==7)
  return 1;
  a/=10;
 }
 return 0;
}
int solve()
{
 int o=0;
 if(y(h)||y(m))
 return 1;
 else
 {
  m-=cost;
  if(m<0)
  {
   h--;
   m+=60;
  }
  if(h<0)
  h=23;
 }
 return 0;
}
int main()
{
 scanf("%d",&cost);
 scanf("%d%d",&h,&m);
 int cnt=0;
 while(solve()!=1)
 {
  cnt++;
 }
 printf("%d\n",cnt);
 return 0;
 }