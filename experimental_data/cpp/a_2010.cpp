#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define boAshraf ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define sz(s) (int)(s).size()
#define endl "\n"
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;

void File();
void sol();

int main() {
    boAshraf
    File();
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}

void sol() {
    int n;cin>>n;
    int sum=0;
    int mul=1;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        sum+=mul*x;
        mul*=-1;
    }
    cout<<sum<<'\n';
}

void File() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}