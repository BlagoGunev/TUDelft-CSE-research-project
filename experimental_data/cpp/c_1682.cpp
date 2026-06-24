//#define LOCAL

//O(n)的算法能解决的数据范围在n < 10^8。
//
//O(n *logn)的算法能解决的数据范围在n <= 10^6。
//
//O(n*sqrt(n) )的算法能解决的数据范围在n < 10^5。
//
//O(n^2)的算法能解决的数据范围在n<5000。
//
//O(n^3)的算法能解决的数据范围在n <300。
//
//O(2^n)的算法能解决的数据范围在n < 25。
//
//O(n!)的算法能解决的数据范围在n < 11。

#include<bits/stdc++.h>

#define int        long long
#define yes        cout<<"YES"<<'\n'
#define no         cout<<"NO"<<'\n'
#define print(x)   cout<<(x)<<'\n'
#define forn(i, n) for(long long i=0; i<n; i++)

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

using namespace std;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-4;
const double PI = acos(-1);
const int MAXN = 2e5 + 5;

int an[MAXN];
int bn[MAXN];
int cn[MAXN];
int dn[205][205];

int n, m, e, tt;

struct node {
    int id, v;
};
node nodes[MAXN];

struct cmp {
    bool operator()(int a, int b) const {
        return a >= b;
    }
};

//int ans = 0;

signed main() {
#ifdef LOCAL
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tt;
//    tt = 1;

    for (int _i = 0; _i < tt; ++_i) {
        cin >> n;
        map<int, int> mp;
        forn(i, n) {
            cin >> an[i];
            mp[an[i]]++;
        }

        int doble = 0, singl = 0;
        for (auto &[k, v]: mp) {
            if (v > 1)doble++;
            else singl++;
        }

        print(doble + (singl + 1) / 2);

    }
}