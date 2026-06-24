#include<bits/stdc++.h>

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define MOD 1000000007

#define MOD1 998244353

#define inf 1e17

#define pb push_back

#define ff first

#define ss second

#define vpll vector<pair<int,int>>

#define vll vector<int>

#define all(x) (x).begin(), (x).end()

#define rep(i,a,b) for (int i=a;i<b;i++)

#define line(x) cout<<x<<"\n"

#define yes                          cout << "YES" << endl;

#define no                           cout << "NO"  << endl;

#define mapp map<int,int>

#define int long long

const int largen = INT_MIN;

using namespace std;





// Operator overloads

template<typename T> // cin >> vector<T>

istream& operator>>(istream &istream, vector<T> &v) {for (auto &it : v)cin >> it; return istream;}

template<typename T> // cout << vector<T>

ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }



// Utility function

template<typename T>

int sumvec(vector<T>v) {int n = v.size(); int s = 0; rep(i, 0, n)s += v[i]; return s;}

int n, m, x, k, l, r, c, i, j, y, q, max1, min1;

vll adjList[100001];

vll ans(100001, 0), vis(100001, 0);

void dfs(int node, int val) {

    // cout << node << " ";

    vis[node] = 1;

    ans[node] = val * adjList[node].size();

    for (auto t : adjList[node]) {

        if (!vis[t]) {

            dfs(t, -val);

        }

    }

}



void solve()

{

    max1 = largen;

    min1 = inf;

    c = 0;

    string s1;

    cin >> n;

    rep(i, 1, n + 1) {

        adjList[i].clear();

        vis[i] = 0;

        ans[i] = 0;

    }

    rep(i, 1, n) {

        cin >> x >> y;

        adjList[x].pb(y);

        adjList[y].pb(x);

    }

    dfs(1, 1);

    rep(i, 1, n + 1) {

        cout << ans[i] << " ";

    }

    cout << endl;



}



signed main() {

    fastio();

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE

    int t = 1;

    cin >> t;

    while (t--)

        solve();

    return 0;

}