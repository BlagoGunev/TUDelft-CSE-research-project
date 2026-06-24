/* Online C++ Compiler and Editor */
#include <iostream>

using namespace std;

int main()
{
   int t,n,a,ans=0;
   cin>>t;
   while(t--){
       cin>>n;
       for(int i=0;i<n;i++){
           cin>>a;
           if(a&1)ans++;
       }if(ans&1)cout<<"NO\n";
       else cout<<"yes\n";
       ans=0;
   }
   
   return 0;
}