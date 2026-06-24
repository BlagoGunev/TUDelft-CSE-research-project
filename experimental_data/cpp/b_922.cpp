#include<stdio.h>
int main()
{
 int n;
 scanf("%d",&n);
 int ans=0;
 for(int i=1;i<=n;i++)
  for(int j=i;j<=n;j++)
   if((i^j)<=n&&(i^j)>=j&&i+j>(i^j)&&i+(i^j)>j&&j+(i^j)>i)
    ans++;
 printf("%d\n",ans); 
}