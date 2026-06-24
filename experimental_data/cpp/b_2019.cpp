#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
int n,m;
int a[N];
int q[N];
int b[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        map<int,int>mp;
        for(int i=1;i<=m;i++)cin>>q[i];
        for(int i=1;i<=n-1;i++){
            mp[i*(n-i)]+=a[i+1]-a[i]-1;
        }
        for(int i=1;i<=n;i++){
            int x=(i-1)*(n-i+1)+n-i;
            mp[x]+=1;
        }
        for(int i=1;i<=m;i++){
            cout<<mp[q[i]]<<' ';
        }
        cout<<'\n';
    }
}