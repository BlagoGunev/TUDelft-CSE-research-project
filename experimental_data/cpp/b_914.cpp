#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
const int maxn=1e5+5;
int n,ai[maxn];
inline void read(int &now)
{
 char Cget;
 now=0;
 while(!isdigit(Cget=getchar()));
 while(isdigit(Cget))
 {
  now=now*10+Cget-'0';
  Cget=getchar();
 }
}
int main()
{
 read(n);
 for(int i=1,x;i<=n;i++)
 {
  read(x);
  ai[x]++;
 }
 for(int i=maxn-1;i>=0;i--)
  if(ai[i]%2)
  {
   puts("Conan");
   return 0;
  }
 puts("Agasa");
 return 0;
}