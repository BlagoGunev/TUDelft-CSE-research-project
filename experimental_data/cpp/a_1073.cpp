#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
int x=0,j,n;
string s="";
void ReadInput()
{
   cin>>n;
   cin>>s;
   n=s.length();
   s.resize(n);
   for (int i=0;i<n-1;i++)
   {
       if (s[i]!=s[i+1])
       {
           x=1;
           cout<<"YES"<<endl<<s[i]<<s[i+1];
           break;
       }
   }
   if (x==0)
      cout<<"NO";
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    ReadInput();
}