//                                        الله العزه

#include <iostream>

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define nd "\n"

#define all(x) (x).begin(), (x).end()

#define lol cout <<"i am here"<<nd;

#define py cout <<"YES"<<nd;

#define pp  cout <<"ppppppppppppppppp"<<nd;

#define pn cout <<"NO"<<nd;

#define ld long double

#define popcount(x)  __builtin_popcount(x)

#define clz(n) __builtin_clz(n)//31 -x

const  double PI = acos(-1.0);

double EPS = 1e-9;

#define print2(x , y) cout <<x<<' '<<y<<nd;

#define print3(x , y , z) cout <<x<<' '<<y<<' '<<z<<nd;

#define watch(x) cout << (#x) << " = " << x << nd;

#define ull unsigned long long

template<class container>

void print(container v) { for (auto& it : v) cout << it<< ' '; cout << '\n'; }



void printpr(priority_queue<ll>&arr){ while(!arr.empty()){ cout <<arr.top()<<" "; arr.pop();}cout <<nd;}

const int N = 1000+100;



// a few against many // 20 days of return can we? // 24 hours a day 7 days a week

ll fp(ll a , ll p){ if(!p) return 1; ll v = fp(a , p/2); v*=v;return p & 1 ? v*a : v;  }

ll  SEG = 2 << (int) ceil(log2(N)) ,  inf = 1e9;int t =1;



///template<typename T>

///vector<vector<T>>arr;

ll n , m; int vid;

char arr[N][N];

int dx [] {-1 , 1 , 0 , 0 };

int dy [] {0 , 0 , -1 , 1 };

int cost [N][N];



pair<ll,ll> bfs(int x , int y){

    for (int i = 0; i < n; ++i){

        for (int j = 0;j <m; ++j){

            cost[i][j] = inf;

        }

    }

    cost[x][y] = 0;

    auto valid=[&](int r , int c)->bool{

        return r>=0 && c>=0 && r < n && c < m;

    };

    if (arr[x][y]== 'B') return make_pair(x , y);

    deque<pair<ll,ll>>dq; dq.emplace_back(x , y);

    while (!dq.empty()){

        int r = dq.front().first , c = dq.front().second; dq.pop_front();

        for (int i = 0; i< 4; ++i){

            int nr = dx[i]+r , nc = dy[i]+c;

            if (valid(nr , nc)&& cost[nr][nc]> 1+ cost[r][c]){

                if (arr[nr][nc]== 'B') return make_pair(nr , nc);

                dq.emplace_back(nr , nc); cost[nr][nc]= 1+ cost[r][c];

            }

        }

    }

    return make_pair(0 , 0);

}

void solve(){



    cin >>n>>m;

    for (int i =0;i < n; ++i){

        for (int j = 0;j < m; ++j){

            cin >>arr[i][j];

        }

    }



    vector<pair<ll,ll>>hell;

    hell.emplace_back(bfs(0 , 0)); hell.emplace_back(bfs(n-1 , m-1)); hell.emplace_back(bfs(0 , m-1));

    hell.emplace_back(bfs(n-1 , 0));

  //  for (auto &i : hell) cout <<i.first<<' '<<i.second<<nd;

   // lol;

    auto kill=[&](int x , int y)->ll{

        ll mx = -1;

        for (auto &i : hell){

            mx = max(abs(i.first-x)+abs(i.second-y) , mx);

        }

        return mx;

    };

    ll mx = inf  , x , y;

    for (int i = 0; i < n; ++i){

        for (int j =0;j < m; ++j){

            ll ch = kill(i , j);

            if (mx > ch){

                mx = ch; x = i , y = j;

            }

        }

    }

    cout <<x+1<<' '<<y+1<<nd;















}





int main(){

    //create();

    ios_base::sync_with_stdio(0); cin.tie(0);

    //// freopen("input.txt","r",stdin);

    //  freopen("output.txt","w",stdout);

   cin >>t;

    while(t--)//while(t)//

        solve();

#ifndef ONLINE_JUDGE

    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";

#endif

    return 0;

}