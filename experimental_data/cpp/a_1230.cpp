#include <bits/stdc++.h>
using namespace std;
int main() 
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
       if(a+b==c+d || b+c==a+d || a+c==b+d )
       {
       	cout<<"YES";
       	exit(0);
       }
       if(a==b+c+d || b==a+c+d || c==a+b+d || d==a+b+c)
       {
       	cout<<"YES";
       	exit(0);
       }
       else cout<<"NO";
    exit(0);
}