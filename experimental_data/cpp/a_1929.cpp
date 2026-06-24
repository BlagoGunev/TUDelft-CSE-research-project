#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        int sum=0;
        for(int i=0;i<n-1;i++)sum+=a[i+1]-a[i];
        cout<<sum<<endl;
    }
}