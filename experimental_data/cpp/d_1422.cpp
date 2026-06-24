#include <bits/stdc++.h>

using namespace std;

#define int long long

#define fi first

#define se second



int t, n, m, k, sx, sy, fx, fy, kc[1000005], mod = 1e9 + 7;

string s;

vector<pair<int, int>> adj[1000005];

mt19937_64 rng;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;



void dijkstra(int u){

    kc[u] = 0; pq.push({kc[u], u});

    while(!pq.empty()){

        pair<int, int> p = pq.top();

        pq.pop();

        if(kc[p.se] < p.fi) continue;

        for(auto i: adj[p.se]){

            if(p.fi + i.se < kc[i.fi]){

                kc[i.fi] = p.fi + i.se;

                pq.push({kc[i.fi], i.fi});

            }

        }

    }

}



struct point{

    int x, y, index;

};



bool cmp1(point a, point b){

    return a.x < b.x;

}



point a[1000005], b[1000005];



bool cmp2(point a, point b){

    return a.y < b.y;

}



void solve(){

    int ans = 1e18; 

    sort(b + 1, b + m + 2, cmp1);

    for(int i = 2; i <= m + 1; i++){

        int w = min(abs(b[i].x - b[i - 1].x), abs(b[i].y - b[i - 1].y));

        adj[b[i].index].push_back({b[i - 1].index, w});

        adj[b[i - 1].index].push_back({b[i].index, w});

        // cout << b[i - 1].index <<" "<< b[i].index <<" "<< w << "\n";

    }

    for(int i = 1; i <= m + 1; i++) b[i] = a[i]; 

    sort(b + 1, b + m + 2, cmp2);

    for(int i = 2; i <= m + 1; i++){

        int w = min(abs(b[i].x - b[i - 1].x), abs(b[i].y - b[i - 1].y));

        adj[b[i].index].push_back({b[i - 1].index, w});

        adj[b[i - 1].index].push_back({b[i].index, w});

        // cout << b[i - 1].index <<" "<< b[i].index <<" "<< w << "\n";

    }

    for(int i = 1; i <= m + 1; i++) kc[i] = 1e18;

    dijkstra(m + 1);

    for(int i = 1; i <= m + 1; i++) ans = min(ans, kc[i] + abs(fx - a[i].x) + abs(fy - a[i].y));

    cout << ans;

}



signed main(){

    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);

    rng.seed((int)main ^ time(0));

    #ifdef Kawaii

        auto starttime = chrono::high_resolution_clock::now();

    #endif



    cin >> n >> m >> sx >> sy >> fx >> fy;

    for(int i = 1; i <= m; i++){

        cin >> a[i].x >> a[i].y; a[i].index = i;

        b[i] = a[i];

    }

    a[m + 1].x = sx; a[m + 1].y = sy; a[m + 1].index = m + 1; b[m + 1] = a[m + 1];

    solve();



    #ifdef Kawaii

        auto endtime = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::milliseconds>(endtime - starttime).count(); 

        cout << "\n=====" << "\nUsed: " << duration << " ms\n";

    #endif

}