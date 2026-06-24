#include<cstdio>
#include<algorithm>
using namespace std;
int n,i,j,Case,f[11111];
int main(){
  for(i=1;i<=1000;i++)f[i]=1000000;
  for(i=0;i<=1000;i++)for(j=2;j<=7;j++)f[i+j]=min(f[i+j],f[i]+1);
  scanf("%d",&Case);
  while(Case--)scanf("%d",&n),printf("%d\n",f[n]);
}