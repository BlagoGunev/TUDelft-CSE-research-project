#include<iostream>
using namespace std;
int main()
{
    int a,b,c,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if(a%2!=0 && b%2!=0)
        cout<<"NO\n";
        if(a%2==0 && b%2==0)
        cout<<"YES\n";
        
        else if(a%2==0 || b%2==0)
       {
           if(a%2==0)
           {
               a/=2;
               if(a==b)
               cout<<"NO\n";
               else
               cout<<"YES\n";
           }
           else
           {
               b/=2;
               if(b==a)
               cout<<"NO\n";
               else
               cout<<"YES\n";
           }
       }
                   
    }
}