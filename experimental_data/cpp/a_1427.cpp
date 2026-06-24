#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define pb push_back
#define F first
#define S second
#define ld long double
#define ll int64_t
#define endl '\n'
#define pll pair <ll,ll>
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
mt19937_64 gen(time(NULL));
typedef tree <ll,null_type,less <ll>,rb_tree_tag,tree_order_statistics_node_update> orduk;
typedef tree <pll,null_type,less <pll>,rb_tree_tag,tree_order_statistics_node_update> orduk2;
//typedef tree <vector <orduk2>,null_type,less <>,rb_tree_tag,tree_order_statistics_node_update> orduk2;
ll n;
vector <ll> a;
void init() {
    cin>>n;
    a.resize(n);
    for (int i = 0;i < n;i++)
        cin>>a[i];
}
vector <ll> ans;
void output() {
    if (!ans.size()) {
        cout<<"NO"<<'\n';
        return;
    }
    cout<<"YES"<<'\n';
    for (int i = 0;i < n;i++)
        cout<<ans[i]<<" ";
    cout<<'\n';
}
void solve() {
    ans.clear();
    sort(a.begin(),a.end());
    ll ss = 0;
    bool can1 = true;
    for (int i = 0;i < n;i++)
    {
        ss+=a[i];
        if (ss==0) {
            can1 = false;
            break;
        }
    }
    if (can1==true) {
    ans.resize(n);
    ans = a;
    return;
    }
    sort(a.rbegin(),a.rend());
    ss = 0;
    can1 = true;
    for (int i = 0;i < n;i++)
    {
        ss+=a[i];
        if (ss==0) {
            can1 = false;
            break;
        }
    }
    if (can1==false) return;
    ans.resize(n);
    ans = a;
}
int main() {
    //freopen("party.in","r",stdin);
    //freopen("party.out","w",stdout);
IOS;
srand(time(NULL));
ll m;
cin>>m;
while (m--)
{
    init();
    solve();
    output();
}
return 0;
}