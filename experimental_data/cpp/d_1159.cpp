#include <bits/stdc++.h>

using namespace std;

int main()
{
 ios_base::sync_with_stdio(0);
 int n,m;
 cin>>n>>m;
 if (n%2==0) {
    int k=0;
    while(m!=n)
     {m+=2;k++;}
    while(m>0)
     {
      for (int i=1;i<=k;i++)
       {cout<<'0';m--;if (m==0) break;}
      if (m==0) break;
      cout<<'1';m--;
     }
 }
 else{
    int k=0;
    while(m!=n)
     {m+=2;k++;}
    while(m>0)
     {
      for (int i=1;i<=k;i++)
       {cout<<'1';m--;if (m==0) break;}
      if (m==0) break;
      cout<<'0';m--;
     }
 }
}