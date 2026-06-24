#include <cstdio>
#include <cstdlib>
using namespace std;

int K,cnt=0,a[11];

void print(int tot)
{
 for(int i=1;i<=tot;i++)putchar(a[i]+'0');
 return ;
}

void search(int tot,int now,int less)
{
 if(now==tot){
  cnt++;
  if(cnt==K){print(tot);exit(0);}
  return ;
 }
 if(now==tot-1){a[tot]=less;search(tot,tot,0);return ;}
  for(int i=0;i<=less;i++){
   a[now+1]=i;
   search(tot,now+1,less-i);
  }
 return ;
}

int main()
{
 scanf("%d",&K);
 register int i,j;
  for(i=2;i<=10;i++){
   for(j=1;j<=9;j++){
    a[1]=j;
    search(i,1,10-j);
   }
  }
 return 0;
}