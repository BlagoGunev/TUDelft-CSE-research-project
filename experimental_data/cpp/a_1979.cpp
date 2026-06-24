/**
 *    hello
 *    author:  N29
 *    created: 2024-06-06 19:33:16
**/
#include<bits/stdc++.h>
using namespace std;
#ifndef BADGNU
#pragma GCC target("sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif
#pragma GCC optimize("Ofast,unroll-loops,fast-math,O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ll long long
#define int ll
#define ld long double
#define y1 cheza
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=1e5+100;
const int M=5001;
const int B=447;
const int mod=998244353;
const ll INF=1e18;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
const double eps=1e-6;
int n;
int a[N];
void test(){
    cin>>n;
    int ans=INF;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        ans=min(ans,max(a[i],a[i+1])-1);
    }
    cout<<ans<<'\n';

}



/*

*/
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    int t2=1;
    cin>>t2;
    for(int i=1;i<=t2;i++){
        test();
    }
}