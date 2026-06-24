#include<bits/stdc++.h>
using namespace std;
long long x,k,pos,dem;
vector<int>res;
int main()
{
     cin>>x;
     while(true)
     {
         bool g=true;
         pos=0;
         for(k=28;k>=0;k--)
        {
         if((x>>k&1)==1) pos++;
         if((x>>k&1)==0&&pos!=0)
         {
             g=false;
             x=x^((1<<(k+1))-1);
             res.push_back(k+1);
             dem++;
             break;
         }
        }
        if(g) break;
        g=true;
         pos=0;
         for(k=28;k>=0;k--)
        {
         if((x>>k&1)==1) pos++;
         if((x>>k&1)==0&&pos!=0) g=false;
        }
        if(g) break;
        dem++;
        x++;
     }
     cout<<dem<<'\n';
     for(auto&x:res) cout<<x<<' ';
}