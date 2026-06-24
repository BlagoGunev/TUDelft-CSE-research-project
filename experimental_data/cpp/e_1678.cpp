#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define all(v) (v).begin(), (v).end()

#define popcountll(x) __builtin_popcountll(x)

#define pb push_back

#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())



#ifdef LOCAL

template<typename T>    void LOG(vector<T> v) 

{cerr << "[ ";for (auto i : v) {cerr << i << " ";}cerr << "]" << endl;}

template<typename T>    void LOG(set<T> v) 

{cerr << "{ ";for (auto i : v) {cerr << i << " ";}cerr << "}" << endl;}

template<typename T,typename V>    void LOG(map<T,V> v) 

{cerr << "[ ";for (auto [a,b] : v) {cerr << "(" << a << ", " << b << "), ";}cerr << "] << endl";}

#else

#define LOG(...)

#endif // LOCAL

// 双排列 -> 环 环上相邻元素之差绝对值 最大

// 奇环 -> 一半大数 * 2, 一半小数 / 2, 中间有个0贡献

// 偶环 -> 一半大数 * 2, 一半小数 / 2



void solve()

{

    int n;  cin >> n;

    vector<int> a(n + 1), b(n + 1), p(n + 1);

    for (int i = 1; i <= n; ++ i)   cin >> a[i];

    for (int i = 1; i <= n; ++ i)   

    {

        cin >> b[i];

        p[b[i]] = a[i];

    }



    vector<bool> st(n + 1);

    int tot = 0;

    for (int i = 1; i <= n; ++ i)

    {

        if (st[b[i]])  continue;



        int len = 0;

        for (int j = b[i]; !st[j]; j = p[j])

            ++ len, st[j] = true;

        tot += len / 2;

    }



    int ans = 0;

    for (int i = 1; i <= tot; ++ i)     // [n 1] [n-1 2]首尾

        ans += n - 2 * i + 1;

    ans *= 2;

    cout << ans << endl;

}

signed main()

{

    ios::sync_with_stdio(false), cin.tie(0);

    #ifdef LOCAL

    freopen("sample.in", "r", stdin);

    freopen("sample.out", "w", stdout);

    #endif

    int tt; cin >> tt;

    while (tt--)        solve();

    return 0;

}