#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define int long long

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        vector<int>arr(3);
        for(int i=0;i<=2;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        if((arr[0]+arr[1]+arr[2])&1){
            cout<<-1<<endl;
        }
        else {
            if(arr[0]+arr[1]>arr[2]){
                cout<<(arr[0]+arr[1]+arr[2])/2<<endl;
            }
            else {
                cout<<arr[0]+arr[1]<<endl;
            }
        }
    }
    return 0;
}