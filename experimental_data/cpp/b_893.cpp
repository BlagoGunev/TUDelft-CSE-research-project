#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   int n,i;
   while(cin>>n)
   {

      vector<int>v;
      v.push_back(1);
      v.push_back(6);
       v.push_back(28);
      v.push_back(120);
      v.push_back(496);
      v.push_back(2016);
       v.push_back(8128);
      v.push_back(32640);

       for(i=v.size()-1;i>=0;i--)
       {
           if(n%v[i]==0)
           {
                 cout<<v[i]<<endl;
                 break;
           }
       }
   }
}