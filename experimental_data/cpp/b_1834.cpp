#include <bits/stdc++.h>
    #define pb push_back
    #define F first
    #define S second
    #define Ones(n) __builtin_popcountll(n)
    #define Gondozu ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
    #define endl '\n'

    using namespace std;
    using ll = long long;
    using pi = pair<int,int>;
    using vi = vector<int>;
    using vpi = vector<pair<int,int>>;
    using vvi = vector<vector<int>>;

    const int OO = 1e9+5;
    const int N = 2e5+5;

    void TC()
    {
        string l, r;
        cin >> l >> r;
        int n = r.size();
        while (l.size() < n)
            l = "0" + l;

        bool less = false;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if(less){
                ans += 9;
            } else {
                ans += r[i]-l[i];
                less = r[i] > l[i];
            }
        }
        cout << ans;
    }

    int32_t main()
    {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin); freopen("output.out", "w", stdout);
    #endif
        Gondozu
        int t = 1;
        cin >> t;
        while (t--)
        {
            TC();
            cout << '\n';
        }
        return 0;
    }