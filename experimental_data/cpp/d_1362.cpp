#include<bits/stdc++.h>

using namespace std;

#define ll  long long

#define ull unsigned long long

#define ld long double

#define pii pair<int,int>

#define pll pair<ll,ll>

#define pvv pair<vector<int>, vector<int>>

#define tiii tuple<int,int,int>

#define pb push_back

#define f first

#define s second

#define mk make_pair

/*----------------------DEBUGGER---------------------------*/

#ifndef ONLINE_JUDGE

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

#else

#define debug(x)

#endif



void _print(ll t) {cerr << t;}

void _print(int t) {cerr << t;}

void _print(string t) {cerr << t;}

void _print(char t) {cerr << t;}

void _print(ld t) {cerr << t;}

void _print(double t) {cerr << t;}

void _print(ull t) {cerr << t;}



template <class T, class V> void _print(pair <T, V> p);

template <class T> void _print(vector <T> v);

template <class T> void _print(set <T> v);

template <class T, class V> void _print(map <T, V> v);

template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}

template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*----------------------DEBUGGER---------------------------*/



int main() {

  ios_base::sync_with_stdio(false);

  cin.tie(NULL);

#ifndef ONLINE_JUDGE

  freopen("input.txt", "r", stdin);

  freopen("output.txt", "w", stdout);

  freopen("error.txt", "w", stderr);

#endif

  int tc = 1;

  // cin >> tc;

  while (tc--) {

    int n, m;

    cin >> n >> m;



    vector<vector<int>> adj(n);

    for (int e = 0; e < m; e++) {

      int u, v;

      cin >> u >> v;

      u--; v--;

      adj[u].pb(v);

      adj[v].pb(u);

    }



    vector<vector<int>> topic(n + 1);

    for (int i = 0; i < n; i++) {

      int t;

      cin >> t;

      topic[t].pb(i);

    }



    bool pos = true;

    vector<int> assign(n);

    for (int t = 1; t <= n; t++) {

      for (auto node : topic[t]) {

        set<int> mex;

        for (auto child : adj[node])

          if (assign[child])

          mex.insert(assign[child]);

        int curr = 1;

        for (auto it: mex)

          if (it != curr) 

            break;

          else

            curr++;

        debug(node)

        debug(t)

        debug(mex)

        debug(curr)

        if (curr != t) {

          pos = false;

          break;

        }

        assign[node] = t;

      }

      if (!pos)

        break;

    }



    if (pos) {

      for (int t = 1; t <= n; t++) {

        for (auto node : topic[t])

          cout << node + 1 << " ";

      }

    } else

      cout << -1 << "\n";

  } //while

} //main