#include <stdio.h>

#include <string.h>

#include <algorithm>

#include <math.h>

using namespace std;

#define LL long long

#define no {puts("No");return 0;}
LL a[100],n,k;
int main(){
 scanf("%lld%lld",&n,&k);
 if(k>42)no
 a[0]=1;
 for(int i=1;i<=42;i++){
  a[i]=a[i-1]*i/__gcd(1ll*i,a[i-1]);
 }
 if((n+1)%a[k])no
 puts("Yes");
}