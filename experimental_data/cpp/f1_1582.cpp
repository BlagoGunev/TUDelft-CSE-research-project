#include<iostream>

#include<cstring>

#include<algorithm>

#include<set>

#include<deque>

#include<queue>

#include<map>

#include<vector>

using namespace std;

#define endl '\n'

#define fi first

#define se second

#define all(v) v.begin(), v.end()

#define int long long

typedef pair<int, int> PII;



const int N = 100005;

int a[N], dp[520];



void solve(){

    int n;

    cin >> n;

    for(int i = 1; i <= n; ++ i)cin >> a[i];

    

    for(int i = 1; i <= 515; ++ i)dp[i] = 1000;

    dp[0] = 0;

    for(int i = 1; i <= n; ++ i){

        for(int j = 0; j <= 515; ++ j){

            if(dp[j] < a[i]){

                dp[j ^ a[i]] = min(dp[j ^ a[i]], a[i]);

            }

        }

    }

    

    vector<int> ans;

    for(int i = 0; i <= 515; ++ i){

        if(dp[i] != 1000)ans.push_back(i);

    }

    cout << ans.size() << endl;

    for(auto it : ans)cout << it << ' ';

    cout << endl;

}

 

 

signed main(){

    ios::sync_with_stdio(false);

    cin.tie(0), cout.tie(0);

    

    solve();

    return 0;

}