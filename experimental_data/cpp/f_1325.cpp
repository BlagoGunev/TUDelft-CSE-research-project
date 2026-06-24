#include<iostream>

#include <bits/stdc++.h>

using namespace std;

template<class container> void print(container v) { for (auto& it : v) cout << it << ' ' ;cout <<endl;}

using ll = long long;

using ull = unsigned long long;

using ld = long double;

#define nd "\n"

#define all(x) (x).begin(), (x).end()

#define popcount(x)  __builtin_popcount(x)

const ll N = 1e5+50 , LOG = 22 , inf = 1e8 , SQ= 550 , mod = 1e9+7;

#define py cout <<"YES";

#define pn cout <<"NO";

#define pp  cout <<"ppppppppppppppppp"<<nd;

#define lol cout <<"i am here"<<nd;

const  double PI = acos(-1.0);



const int MX = 1e4+100;





template <typename T> using min_heap = priority_queue<T , vector <T > , greater <T >  >;

vector< vector <int > > g(N);

vector <bool> mark(N);

vector <int > vis(N);

int sq;

vector<int > st;

vector <int > depth(N);

void dfs(int node , int par){

    vis[node] = 1;

    st.emplace_back(node);

    depth[node]  = 1 + depth[par];

    for (auto &ch : g[node]){

        if (ch == par) continue;

        if (!vis[ch]) dfs(ch , node);

        else if (vis[ch]){

            if (depth[node] - depth[ch]+1 >= sq){

                vector<int > ans;

                int i = (int)st.size()-1;

                while (1){

                    ans.emplace_back(st[i]);

                    if (st[i--] == ch) break;

                }

                reverse(all(ans));

                cout << 2 << nd;

                cout << (int)ans.size()<<nd;

                for (auto &v : ans) cout << v<<" ";

                exit(0);

            }

        }

    }

    if (!mark[node])

        for (auto &ch : g[node]) mark[ch] = 1;

    st.pop_back();

}

void hi(){

  ll n , m , u , v; cin >> n >> m;

  sq = sqrtl(n-1); while (sq* sq < n)++sq;



  for (int i = 1; i <= m; ++i){

      cin >> u >> v;

      g[u].emplace_back(v);

      g[v].emplace_back(u);

  }

  dfs(1 , 1);





  cout << 1 << nd;

  for (int i = 1; sq; ++i){

      if (!mark[i])

          --sq , cout << i <<" ";

  }

















}



int main(){

     ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    int tt = 1 , tc = 0;

  //  cin >> tt;

    while(tt--) hi();

    return 0;

}