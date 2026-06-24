#include <iostream>
#include<algorithm>
using namespace std;

int main()
{   int n,k,ans=0;
    int a[2205];

    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }


   sort(a,a+n);
   for(int i=0;i<k;i++){
    
    ans+=a[i];
   }
    cout<<ans<<endl;
    return 0;
}