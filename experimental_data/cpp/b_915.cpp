#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
const int INF=2147483647;
const int mod=1e9+7;

int main(){
 int n,p,l,r;
 scanf("%d%d%d%d",&n,&p,&l,&r);
 int sum1=0;
 int now=p;
 if(l>1){
  sum1+=(abs(now-l)+1);
  now=l;
 }
 if(r<n){
  sum1+=(abs(now-r)+1);
  now=r;
 }
 now=p;
 int sum2=0;
 if(r<n){
  sum2+=(abs(now-r)+1);
  now=r;
 }
 if(l>1){
  sum2+=(abs(now-l)+1);
  now=l;
 }
 printf("%d\n",min(sum1,sum2));
 return 0;
}