#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,a,b;
        cin>>n>>a>>b;
        if(abs(a-b)%2==1){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
}