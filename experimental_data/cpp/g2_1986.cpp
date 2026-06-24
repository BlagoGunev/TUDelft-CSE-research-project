#include<bits/stdc++.h>
using namespace std;
// #define int long long

const int N=5e5+5;
vector<int> fact[N];
void solve(){
    int n;  cin>>n;
    vector<int> arr(n);
    for(auto &x:arr)    cin>>x;
    vector<int> adj[n+1];
    vector<int> wow[n+1];
    for(int i=1;i<=n;i++){
        int g=gcd(i,arr[i-1]);
        int num=arr[i-1]/g;
        int den=i/g;
        adj[den].push_back(num);
        wow[num].push_back(den);
    }
    long long start=adj[1].size();
    // int res=(start*(start-1))/2;
    vector<int> freq(n+1);
    long long res2=0;
    for(int i=1;i<=n;i++){
        if(adj[i].size()==0)    continue;
        for(int j=i;j<=n;j+=i){
            for(auto ele:wow[j]){
                freq[ele]++;
            }
        }
        for(auto ele:adj[i]){
            for(auto x:fact[ele]){
                res2+=freq[ele/x];
            }
        }
        for(int j=i;j<=n;j+=i){
            for(auto ele:wow[j]){
                freq[ele]--;
            }
        }
    }
    res2=res2-start;
    res2=res2/2;
    cout<<res2<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            fact[j].push_back(i);
        }
    }
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}