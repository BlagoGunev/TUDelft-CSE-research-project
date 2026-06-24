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

template<typename T>    void LOG(multiset<T> v) 

{cerr << "{ ";for (auto i : v) {cerr << i << " ";}cerr << "}" << endl;}

template<typename T,typename V>    void LOG(map<T,V> v) 

{cerr << "[ ";for (auto [a,b] : v) {cerr << "(" << a << ", " << b << "), ";}cerr << "]" << endl;}

#else

#define LOG(...)

#endif // LOCAL



// multiset 直接删int x 会导致全部的x都被删除

// 应该删 find(x)



void solve()

{

    int n, x;   cin >> n >> x;

    vector<int> a(n);

    multiset<int> mset;

    for (int i = 0; i < n; ++ i)   cin >> a[i], mset.insert(a[i]);

    LOG(a);



    int ans = 0;

    while (mset.size())

    {

        int t = *mset.begin();

        if (mset.find(t * x) != mset.end())

        {

            mset.erase(mset.begin());

            mset.erase(mset.find(t * x));

        }

        else

        {

            mset.erase(mset.begin());

            ++ ans;

        }

    }

    cout << ans << endl;

    // LOG(mst);

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