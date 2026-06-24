#include <bits/stdc++.h>

using namespace std;

#include<stdio.h>
int main()
{
 long long a,b;
 long long sum=1;
 scanf("%lld %lld",&a,&b);
 if(a>=b||a>63) printf("%lld\n",b);
 else
 {
  for(long long i=0;i<a;i++)
  {
   sum*=2; 
  } 
  printf("%lld\n",b%sum);
 }
 
 return 0;
}