#include <bits/stdc++.h>

#include <ext/pb_ds/detail/standard_policies.hpp>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

 

#define pb push_back

#define F first

#define S second

#define ll long long

#define ull unsigned long long

#define ld long double

#define endl '\n'

#define TIME 1.0*clock()/CLOCKS_PER_SEC

#define pii pair < int , int >

#define Endl '\n'

 

#pragma GCC optimize("Ofast")

 

using namespace std;

using namespace __gnu_pbds;

 

template <typename T> using ordered_set = tree <T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

 

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

 

const int mod = 1e9 + 7;

const int FFTM = 998244353;

 

const int SX[4] = {0 , 1 , -1 , 0};

const int SY[4] = {1 , 0 , 0 , -1};

const int rx[8] = {1, -1, 0, 0, 1, 1, -1, -1};

const int ry[8] = {0, 0, 1, -1, 1, -1, 1, -1};

const int kx[8] = {1, 1, -1, -1, 2, 2, -2, -2};

const int ky[8] = {2, -2, 2, -2, 1, -1, 1, -1};

 

typedef cc_hash_table< int, int, hash<int>, equal_to<int>, direct_mask_range_hashing<int>, hash_standard_resize_policy<hash_exponential_size_policy<>, hash_load_check_resize_trigger<true>, true>> ht;

 

 

void solve(){

    int n, x, y;

    cin >> n >> x >> y;

 

    if (x > y){

        cout << "NO" << endl;

        return;

    }

 

    vector < bool > use(n, 0);

 

    vector < vector < int > > all(n + 2);

    vector < int > ans(n, 0);

    vector < int > b(n);

    for (int i = 0;i < n; ++i){

        cin >> b[i];

        all[b[i]].pb(i);

    }

    int unuse_color = -1;

    priority_queue < pair < int, int > > q;

    for (int i = 1;i <= n + 1; ++i){

        if (all[i].size() == 0)unuse_color = i;

        else q.push({all[i].size(), i});

    }

    bool ok = 1;

    for (int i = 0;i < x; ++i){

        if (!q.size()){

            ok = 0;

            break;

        }

        int sz = q.top().F;

        int color = q.top().S;

        q.pop();

 

        int pos = all[color].back();

        all[color].pop_back();

 

        ans[pos] = color;

        use[pos] = 1;

 

        if (sz > 1)q.push({sz - 1, color});

    }

    if (!ok){

        cout << "NO" << endl;

        return;

    }

    if (q.size()){

        deque < int > poses;

        int sz = q.top().F;

        int color = q.top().S;

        q.pop();

 

        for (auto to : all[color])poses.pb(to);

 

        while(!q.empty()){

            int nsz = q.top().F;

            int ncolor = q.top().S;

            q.pop();

 

            for (int i = 0;i < nsz; ++i){

                int pos = poses.front();

                poses.pop_front();

 

                ans[pos] = ncolor;

 

                poses.push_back(all[ncolor][i]);

            }

        }

 

        for (int i = 0;i < sz; ++i){

            int pos = poses.front();

            poses.pop_front();

 

            ans[pos] = color;

        }

 

    }

 

    int need_unusecolor = n - y;

    for (int i = 0;i < n; ++i){

        if (ans[i] == b[i] && !use[i]){

            ans[i] = unuse_color;

            need_unusecolor--;

        }

    }

    if (need_unusecolor < 0){

        cout << "NO" << endl;

        return;

    }

    for (int i = 0;i < n; ++i){

        if (!need_unusecolor)break;

        if (!use[i] && ans[i] != unuse_color)ans[i] = unuse_color, need_unusecolor--;

    }

    if (need_unusecolor != 0){

        cout << "NO" << endl;

        return;

    }

    cout << "YES" << endl;

    for (auto to : ans)cout << to << " ";

    cout << endl;

}

 

int32_t main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

#ifdef LOCAL

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#else

//    freopen("gotham.in", "r", stdin);

//    freopen("gotham.out", "w", stdout);

#endif

    int t;

    cin >> t;

    while(t --> 0)solve();

    return 0;

}