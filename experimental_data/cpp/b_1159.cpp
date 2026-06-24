#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans,a,i;
    cin>>n;
    scanf("%d",&a);
    ans=a/(n-1);
    for(i=1;i<n-1;i++){
    scanf("%d",&a);
    ans=min(ans,a/i);
    ans=min(ans,a/(n-i-1));
    }
scanf("%d",&a);
ans=min(ans,a/(n-1));
cout<<ans;
}