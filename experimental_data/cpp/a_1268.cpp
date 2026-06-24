#include<algorithm>
#include<cstring>
#include<cstdio>
#define MaxN 200050
using namespace std;
char s[MaxN];
int n,k,m1=1000000,m2=1000000;
int main()
{
  scanf("%d%d%s",&n,&k,s+1);
  for (int i=1;i<=n;i++)s[i]-='0';
  for (int i=1;i<=k;i++){
    int sav=0;
    for (int j=i;j<=n;j+=k)
      if (s[j]>s[i])m1=min(m1,j);
      else if (s[i]>s[j])m2=min(m2,j);
  }if (m1<m2){
    s[k]++;
    for (int i=k;i;i--)
      if (s[i]>=10){
        s[i]-=10;
        s[i-1]++;
      }
  }  
  for (int i=1;i<=n;i++)
    if (i+k<=n)s[i+k]=s[i];
  for (int i=1;i<=n;i++)s[i]+='0';
  printf("%d\n",n);
  puts(s+1);
  return 0;
}