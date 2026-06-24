#include<bits/stdc++.h>
using namespace std;

int main()
{
      int g;
      cin>>g;
      while(g--)
      {
            int a,b,c;
            cin>>a>>b>>c;
            if(a==b)
            {
              if(c%2==0)
              cout<<"Second"<<endl;
              if(c%2!=0)
              cout<<"First"<<endl;
            }
            if(a>b)
            cout<<"First"<<endl;
            if(b>a)
            cout<<"Second"<<endl;

      }
return 0;
}