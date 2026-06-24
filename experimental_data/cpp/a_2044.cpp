#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define gamestart {ios::sync_with_stdio(false);}
#define apt {cin.tie(0);cout.tie(0);}
#define fix(a) cout<<setprecision(a)<<fixed
#define ll long long
#define dd long double
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define LSOne(S) ((S)&-(S))
#define vvi vector<vector<int>>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<long long, long long>
#define read(a) for(auto&b:a) cin>>b;
#define rep for(int i=0;i<n;i++)
#define SUM(a) accumulate((a).begin(),(a).end(),0LL)
#define SORT(a) sort(a.begin(),a.end())
#define UNIQUE(a) sort(a.begin(),a.end());a.erase(unique(a.begin(),a.end()),a.end()); // sorting included
#define MAX(a) *max_element(a.begin(),a.end())
#define MIN(a) *min_element(a.begin(),a.end())
#define sz size()
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define anslol cout<<ans<<"\n"
#define all(x) x.begin(),x.end()
#define newline cout<<endl
#define debug(v) cout<<"Line(" << __LINE__ << ") -> "<<#v<<" = "<<(v)<<"\n";
template <typename T> using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order kth element iterator, order_of_key (number of elements<x)
template <typename T>void print(const vector<T>&v){for (const T&x:v)cout<<x<<" ";cout<<"\n";}template<class T> using maxheap=priority_queue<T>;template<class T> using minheap=priority_queue<T,vector<T>,greater<T>>;

const int MOD=1000000007;

void solve() {
    int n;
    cin>>n;
    cout<<n-1<<"\n";
}

int main() {
    gamestart apt int tc=1; cin>>tc; // rmb to delete for interactive problems
    while (tc--) {
        solve();
    }
    return 0;
}