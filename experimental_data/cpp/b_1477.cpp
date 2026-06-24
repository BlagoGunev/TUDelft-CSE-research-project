/*Dev Karan Singh Sisodia*/

#include <bits/stdc++.h>

 

#include<ext/pb_ds/assoc_container.hpp>

#include<ext/pb_ds/tree_policy.hpp>

 

using namespace std;

using namespace __gnu_pbds;

 

#define pyes cout << "YES" << "\n";

#define pno cout << "NO" << "\n";

#define br cout << "\n";

#define ff first

#define ss second

#define pb push_back

#define mod 998244353

#define mod1 998244353

#define inf 9223372036854775807

#define all(x) (x).begin(),(x).end()

 

typedef long long ll;

typedef unsigned long long ull;

typedef long double lld;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

 

#ifndef ONLINE_JUDGE

#define debug(x) cerr << #x << " -> "; _print(x); cerr << endl;

#else

#define debug(x)

#endif

 

void _print(ll t) {cerr << t;}

void _print(int t) {cerr << t;}

void _print(string t) {cerr << t;}

void _print(char t) {cerr << t;}

void _print(lld t) {cerr << t;}

void _print(double t) {cerr << t;}

void _print(ull t) {cerr << t;}

 

template <class T, class V> void _print(pair <T, V> p);

template <class T> void _print(vector <T> v);

template <class T> void _print(set <T> v);

template <class T, class V> void _print(map <T, V> v);

template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}

template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

 

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

ll gcd(ll a, ll b){ if (a == 0ll) { return b;} return gcd(b % a, a);}



class segTree{

    vector<int> seg, lazy;

public:

    segTree(int n){

        seg.resize(4*n + 1, 0);

        lazy.resize(4*n + 1, -1);

    }

public:

    void build(int ind, int low, int high, int arr[]){

        if(low == high){

            seg[ind] = arr[low];

            return;

        }

        int mid = (high + low) >> 1;

        build(2*ind + 1, low, mid, arr);

        build(2*ind + 2, mid + 1, high, arr);

        seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];

    }

public:

    int answer(int ind, int low, int high, int l, int r){

        if(lazy[ind] != -1){

            seg[ind] = (high - low + 1) * lazy[ind];

            if(high != low){

                lazy[2*ind + 1] = lazy[ind];

                lazy[2*ind + 2] = lazy[ind];

            }

            lazy[ind] = -1;

        }

        if(low >= l && high <= r){

            return seg[ind];

        }

        if(low > r || high < l){

            return 0;

        }

        int mid = (low + high) >> 1;

        return answer(2*ind + 1, low, mid, l, r) + answer(2*ind + 2, mid + 1, high, l, r);

    }

public:

    void update(int ind, int low, int high, int l, int r, int val){

        if(lazy[ind] != -1){

            seg[ind] = (high - low + 1) * lazy[ind];

            if(high != low){

                lazy[2*ind + 1] = lazy[ind];

                lazy[2*ind + 2] = lazy[ind];

            }

            lazy[ind] = -1;

        }

        if(low >= l && high <= r){

            seg[ind] = (high - low + 1) * val;

            if(high != low){

                lazy[2*ind + 1] = val;

                lazy[2*ind + 2] = val;

            }

            return;

        }

        if(low > r || high < l){

            return;

        }

        int mid = (low + high) >> 1;

        update(2*ind + 1, low, mid, l, r, val);

        update(2*ind + 2, mid + 1, high, l, r, val);

        seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];

    }

};



void solve(){

    int n, q;

    cin >> n >> q;

    string a, b;

    cin >> a >> b;

    int arr[n];

    for(int i = 0; i < n; i++){

        arr[i] = b[i] == '1';

    }

    segTree st(n);

    st.build(0, 0, n-1, arr);

    stack<pair<int, int>> sta;

    while(q--){

        int l, r;

        cin >> l >> r;

        l--;

        r--;

        sta.push({l, r});

    }

    while(sta.empty() == false){

        int l = sta.top().ff;

        int r = sta.top().ss;

        sta.pop();

        int sum = st.answer(0, 0, n-1, l, r);

        if(sum < ceil_div(r-l+1, 2)){

            st.update(0, 0, n-1, l, r, 0);

        }else if(r-l+1 - sum < ceil_div(r-l+1, 2)){

            st.update(0, 0, n-1, l, r, 1);

        }else{

            pno

            return;

        }

    }

    for(int i = 0; i < n; i++){

        if(st.answer(0, 0, n-1, i, i) != a[i] - '0'){

            pno

            return;

        }

    }

    pyes

}

 

int main(){

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    freopen("Error.txt", "w", stderr);

#endif // ONLINE_JUDGE

 

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

 

    //code here

    int t;

    cin >> t;

    for(int i = 1; i <= t; i++){

        // cout << "Case #" << i << ": ";

        solve();

    }

    //end

 

    return 0;

 

}