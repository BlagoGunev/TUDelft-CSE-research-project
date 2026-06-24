#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std; 
using namespace __gnu_pbds; 
#define all v.begin(),v.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// find_by_order(k) -  gives the index of k (0 indexed)
// order_of_key(k) - gives elements stricly less than k
// ordered_set pbds;
// string str=bitset<64>(num).to_string();
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
const ll mod=1e9 +7;
// Silly mistakes:
//While adding r-l+1 to ans, check if r>=l
//Don't use mod if not asked in the question
//In bit manipulation questions, use 1ll<<i
//Always check for the condition at the end in a 2 ptr question
//If making some constant size array for every t(test case), try to do it in the main function only single time
//Sigbart happens when solve func is ll instead of void
//In decimal BS use, r-l>=precision(use 1e-7 if given is 1e-6)


void solve(vector<ll> &v){
    ll n=v.size(),ans=0;
    for(int i=0;i<=n;i++){
        ll tans=0;
        for(int j=0;j<n;j++){
            if(v[j]>i) tans++;
        }
        if(tans==i){
            cout<<tans<<endl; return;
        }
    }
    cout<<-1<<endl;
}

int main(){
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n; vector<ll> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        solve(v);
    }
}