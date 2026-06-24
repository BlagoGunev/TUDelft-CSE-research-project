#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int N=2e5+9;
const int mod=1e9+7;
int a[N];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    priority_queue<ll> q;
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]){
            q.push(a[i]);
        }else{
            if(q.size()){
                ans+=q.top();
                q.pop(); 
            }
        }
    }
    // while(!q.empty()){
    //     ans+=q.top();
    //     q.pop();
    // }
    cout<<ans<<'\n';
}
int main(){
    int q;
    cin>>q;
    while(q--){
        solve();
    }
    return 0;
}