#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
    cin>>arr[i];
    sort(arr.begin(),arr.end());
    int ans = 0;
    for(int i=1;i<n;i = i+2)
        ans = ans + (arr[i]-arr[i-1]);
    cout<<ans;
    return 0;
}