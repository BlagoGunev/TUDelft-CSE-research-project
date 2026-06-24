#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first

#define se second

#define pb push_back

#define pii pair<int,int>

const int N = 2e5 + 10;

void solve(){

    int n;

    cin >> n;

    vector<int> a(n), c(n);

    for(int i = 0; i < n; i++ ){

        cin >> a[i];

        a[i]--;

    }

    for(int i = 0; i < n; i++ ){

        cin >> c[i];

    }



    vector<int> vis(n);

    int ans = 1e9;

    for(int i = 0; i < n; i++ ){

        if(!vis[i]){

            vector<int> d;

            for(int j = i; !vis[j]; j = a[j]){

                vis[j] = 1;

                d.emplace_back(j);

            }

            int m = (int)d.size();

            auto check = [&](int x){

                for(int j = 0; j < x; j++ ){

                    int ok = 1;

                    for(int k = j; k + x < m; k += x ){

                        if(c[d[k]] != c[d[k + x]]){

                            ok = 0;

                        }

                    }

                    if(ok) return true;

                }

                return false;

            };

            for(int i = 1; i <= m / i; i++ ){

                if(m % i == 0){

                    if(check(i)) ans = min(ans, i);

                    if(check(m / i)) ans = min(ans, m / i);

                }

            }

        }

    }

    cout << ans << "\n";

}

int main() 

{

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int T;

    cin >> T;

    while(T--){

        solve();

    }

    return 0;

}