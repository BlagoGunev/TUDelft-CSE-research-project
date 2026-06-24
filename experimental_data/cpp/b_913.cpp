#include<stdio.h>
int son[1005];
int fa[1005];
int fi[1005];
int n,i,m;
int flag;
int main(void)
{
 scanf("%d",&n);
 flag=0;
 for(i=1;i<n;i++)
 {
  scanf("%d",&m);
  fa[i+1]=m;
  son[m]++;
 }
 for(i=1;i<=n;i++)
 {
  if(son[i]==0)
  {
   fi[fa[i]]++;
  }
 }
 for(i=1;i<=n;i++)
 {
  if(son[i]!=0)
  {
   if(fi[i]==0)
   flag=1;
  }
 }
 for(i=1;i<=n;i++)
 {
  if(fi[i]==0||fi[i]>=3)
  continue;
  flag=1;
 }
 if(flag==1)
 printf("No\n");
 else
 printf("Yes\n");
 return 0;
}