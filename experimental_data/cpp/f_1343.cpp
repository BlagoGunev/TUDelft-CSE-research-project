#include<iostream>

#include<cstring>

#include<vector>

#include<set>

#include<queue>

#include<map>

using namespace std;

using LL = long long;

const int maxn = 205;



int main(){



#ifdef LOCAL

    freopen("data.in", "r", stdin);

    freopen("data.out", "w", stdout);

#endif



    cin.tie(0);

    cout.tie(0);

    ios::sync_with_stdio(0);



    int T;

    cin >> T;

    while(T--){

        int n;

        cin >> n;

        vector<vector<int> > seg(n - 1);

        vector<vector<int> > pos(n + 1);

        for(int i = 0; i < n - 1; i++){

            int cnt;

            cin >> cnt;

            seg[i].resize(cnt);

            for(int j = 0; j < cnt; j++)

                cin >> seg[i][j], pos[seg[i][j]].push_back(i);

        }



        auto check = [&](int x){

            vector<int> p(n + 1, 0), a(n + 1, 0);

            vector<int> d(n - 1);

            vector<pair<int, int> > rng(n - 1); 

            vector<bool> used(n + 1);

            for(int i = 0; i < n - 1; i++)

                d[i] = seg[i].size();

            vector<int> cand;

            cand.push_back(x);

            for(int i = 1; i <= n; i++){

                if (cand.size() != 1) return false;

                int x = cand[0];

                used[x] = true;

                cand.pop_back();

                p[i] = x;

                a[x] = i;

                for(auto u : pos[x]){

                    if (--d[u] == 1){

                        if (i + 2 - (int)seg[u].size() < 1) return false;

                        rng[u] = {i + 2 - seg[u].size(), i + 1};

                        for(auto j : seg[u]){

                            if (!used[j]){

                                cand.push_back(j);

                                break;

                            }

                        }

                    }

                }

            }

            for(int i = 0; i < n - 1; i++){

                auto [l, r] = rng[i];

                for(auto x : seg[i])

                    if (a[x] < l || a[x] > r) 

                        return false;

            }

            for(int i = 1; i <= n; i++)

                cout << p[i] << " \n"[i == n];

            return true;

        };



        for(int i = 1; i <= n; i++)

            if (check(i)) break;

    }



}