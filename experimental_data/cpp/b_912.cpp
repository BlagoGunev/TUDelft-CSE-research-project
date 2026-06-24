#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL calcule(LL n,LL k)
{
 LL p=0;
 LL i=0;
 if (k==1) return n;
 
 while(p<n)
 { 
  p=2*p+1;
 }
  
  return p;
  
}
 
 
int main() {
 LL n,k;
 
 cin>>n>>k;
 cout<<calcule(n,k);
 return 0;
}