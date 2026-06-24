// The code snippet of Rain Sure

#pragma GCC optimize(2)

#pragma GCC optimize(3)

#include<iostream>

#include<cstring>

#include<algorithm>

#include<vector>

#include<queue>

#include<set>

#include<map>

#include<unordered_map>

#include<unordered_set>

using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);

#define x first

#define y second

#define int long long

#define endl '\n' 

const int inf = 1e9 + 10;

const int maxn = 100010, M = 2000010;

const int mod = 1e9 + 7;

typedef pair<int,int> PII;

typedef long long LL;

typedef unsigned long long ULL;

typedef long double LD;

int h[maxn], e[M], w[M], ne[M], idx;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int cnt;

void add(int a, int b, int c)

{

    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;

}

void add(int a, int b)

{

    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;

}

int qmi(int a,int b){int res=1%mod; a%=mod;while(b) { if(b&1) res=res*a%mod; a=a*a%mod;b>>=1;}return res;}

int gcd(int a,int b) { return b?gcd(b,a%b):a;}

// head

signed main()

{

    IOS;

    int n, q; cin >> n >> q;

    vector<int> a(n + 1);

    for(int i = 1; i <= n; i ++) cin >> a[i];

    vector<int> s1(n + 1, 0), s2(n + 1, 0);

    map<int, vector<int>> mp1, mp2;

    for(int i = 1; i <= n; i ++) {

        s1[i] = s1[i - 1] + a[i];

        s2[i] = s2[i - 1] ^ a[i];  

        if(i % 2) mp1[s2[i]].push_back(i);

        else mp2[s2[i]].push_back(i);

    }

    while(q -- ) {

        int l, r; cin >> l >> r;

        if((s2[r] ^ s2[l - 1]) != 0) cout << -1 << "\n";

        else {

            if(s1[r] == s1[l - 1]) cout << 0 << '\n';

            else if((r - l + 1) % 2) cout << 1 << "\n";

            else if(a[l] == 0 || a[r] == 0) cout << 1 << "\n";

            else {

                if((l - 1) % 2 == 0) {

                    auto it = lower_bound(mp1[s2[l - 1]].begin(), mp1[s2[l - 1]].end(), l - 1);

                    if(it != mp1[s2[l - 1]].end() && *it < r) {

                        cout << 2 << "\n";

                    }else cout << -1 << "\n";

                }else {

                    auto it = lower_bound(mp2[s2[l - 1]].begin(), mp2[s2[l - 1]].end(), l - 1);

                    if(it != mp2[s2[l - 1]].end() && *it < r) {

                        cout << 2 << "\n";

                    }else cout << -1 << "\n";

                }

            }

        }

    }

    return 0;

}