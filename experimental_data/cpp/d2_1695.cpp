#include<bits/stdc++.h>

using namespace std;

vector <int> g[200100];

int cnt[200100];

int n;

int p(int i,int pre){

    for (auto v:g[i]){

        if (v == pre)continue;

        return v;

    }

}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);

    int t;

    cin>>t;

    while (t--){

        cin>>n;

        for (int i = 1;i <= n;i ++){

            g[i].clear();cnt[i] = 0;

        }

        for (int i = 1;i < n;i ++){

            int u,v;

            cin>>u>>v;

            g[u].push_back(v);

            g[v].push_back(u);

        }

        bool ok = 1;

        for (int i = 1;i <= n;i ++){

            if (g[i].size() > 2)ok = 0;

        }

        if (ok){

            if (n == 1)cout<<0;

            else cout<<1;

            cout<<'\n';

            continue;

        }

        for (int i = 1;i <= n;i ++){

            if (g[i].size() == 1){

                int cur = g[i][0];

                int pre = i;

                while (g[cur].size() == 2){

                    int tmp = cur;

                    cur = p(cur,pre);

                    pre = tmp;

                }

                cnt[cur]++;

            }

        }

        int ans = 0;

        for (int i = 1;i <= n;i ++){

            ans += max(0,cnt[i] - 1);

        }

        cout<<ans<<'\n';

    }

    return 0;

}