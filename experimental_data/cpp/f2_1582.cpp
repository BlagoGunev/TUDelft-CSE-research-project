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

//#define int long long

typedef pair<int, int> PII;



const int N = 1000005;

int a[N], dp[5005][10005];

vector<int> id[5005];



void solve(){

    int n;

    cin >> n;

    

    for(int i = 1; i <= n; ++ i){

        cin >> a[i];

        id[a[i]].push_back(i);

    }

    

    for(int i = 0; i <= 5e3; ++ i){

        for(int j = 0; j <= 10000; ++ j)dp[i][j] = 1e9;

    }

    dp[0][0] = 0;

    

    for(int i = 1; i <= 5000; ++ i){

        for(int j = 0; j <= 10000; ++ j){

            dp[i][j] = dp[i - 1][j];

            if(!id[i].size())continue;

            if((j ^ i) > 10000)continue;

            

            auto t = lower_bound(all(id[i]), dp[i - 1][j ^ i]);

            //cout << i << ' ' << *t << endl;

            if(t != id[i].end()){

                dp[i][j] = min(dp[i][j], *t);

            }

        }

    }

    

    vector<int> ans;

    for(int j = 0; j <= 10000; ++ j){

        if(dp[5000][j] != 1e9)ans.push_back(j);

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