#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define inf ((int)2e9 + 10)
#define nl '\n'
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define PI acos(-1)
#define ordered_set tree<ll ,  null_type ,  less_equal<> ,  rb_tree_tag ,  tree_order_statistics_node_update>

vector <int> dx {0, 0, 1, -1, 1, 1, -1, -1}, dy {1, -1, 0, 0, 1, -1, 1, -1};
//vector<int> dx{1, 1, -1, -1, 2, 2, -2, -2}, dy{2, -2, 2, -2, 1, -1, 1, -1};

void file_fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 3e5 + 5;
ll dp[N][11], arr[N];
int n, k;

ll solve(int i, int cnt){
    if(i >= n)
        return 0;

    ll& ret = dp[i][cnt];
    if(~ret) return ret;

    ret = 1e18;

    ll mn = arr[i];
    for(int j = 0; j <= cnt && i + j < n; j++){
        mn = min(mn, arr[i + j]);
        ret = min(ret, solve(i + j + 1, cnt - j) + mn * (j + 1));
    }

    return ret;
}

void some_code(){
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= k; j++)
            dp[i][j] = -1;

    cout << solve(0, k);
}

int main(){
    file_fastIO();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int TC = 1;

    cin >> TC;

    for(int i = 1; i <= TC; i++){
//        cout << "Case " << i << ": ";
        some_code();
        cout << nl;
    }

    return 0;
}