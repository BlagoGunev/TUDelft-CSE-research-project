#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int a,b,c,d,e,f;
    cin>>a>>b>>c>>d;
    //e=((a*b)*4)-abs(a*b);
   // f=((c*d)*4)-abs(a*b);
   e=b+d;
   f=max(a,c);

    //cout<<e+f<<endl;
    cout<<((e+2)*2)+(f+f)<<endl;

}