#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
 int t,n,k,a[205];
 scanf("%d",&t);
 while(t--)
 {
  int ans;
  scanf("%d%d",&n,&k);
  for(int i=0;i<k;i++)
   scanf("%d",&a[i]);
  sort(a,a+k);
  ans=max(a[0]-1,n-a[k-1]);
  for(int i=1;i<k;i++)
   ans=max(ans,(a[i]-a[i-1])/2);
  printf("%d\n",ans+1);
 } 
}