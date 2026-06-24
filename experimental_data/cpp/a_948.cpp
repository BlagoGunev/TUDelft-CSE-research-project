#include<bits/stdc++.h>
using namespace std;
char mp[505][505];
bool pl(int x,int y)
{
 if(mp[x][y]=='W')
  return false;
 else if(mp[x][y]=='.')
  mp[x][y]='D';
 return true;
}
int main()
{
 int r,c;
 scanf("%d%d",&r,&c);
 for(int i=0;i<r;i++)
  scanf("%s",mp[i]);
 bool flag=true;
 for(int i=0;i<r;i++)
 {
  for(int j=0;j<c;j++)
  {
   if(mp[i][j]=='S')
   {
    if(i>0)
     flag&=pl(i-1,j);
    if(j>0)
     flag&=pl(i,j-1);
    if(i<r-1)
     flag&=pl(i+1,j);
    if(j<c-1)
     flag&=pl(i,j+1);
   }
   if(!flag)
   {
    puts("No");
    return 0;
   }
  }
 }
 puts("Yes");
 for(int i=0;i<r;i++)
  printf("%s\n",mp[i]);
 return 0;
}