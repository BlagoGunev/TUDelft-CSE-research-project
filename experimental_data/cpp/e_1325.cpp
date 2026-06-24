#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back

const int MN=8e4; 

int N, at=170, dist[MN], ans = MN; bool pvis[1001], vis[MN]; 

set<int> start; vector<int> prime, vals, adj[MN];

unordered_map<int, int> ind; // (value, index it maps to)

queue<pair<int, pair<int, int> > > next1; // (distance, (node, parent)) 

void bfs(int j){ memset(vis, 0, sizeof(vis)); next1.push({0, {j, j}});

    while (!next1.empty()) { int d = next1.front().first;

        int x = next1.front().second.first; int p = next1.front().second.second;

        next1.pop(); if(adj[x].size()<=1 || vis[x]) continue;

        vis[x]=1; dist[x] = d; bool skip=0;

        for (int i: adj[x]) 

            if (i != p || skip) 

                { if (vis[i]) ans = min(ans, dist[i] + dist[x] + 1);                   

                  else next1.push({d + 1, {i, x}}); }

            else skip = 1;

	}

	adj[j].clear();

}

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    prime.reserve(170); prime.pb(1); 

	for(int i=2;i<=1e3;i++) { if(pvis[i]) continue; prime.pb(i);

		for(int j=i*i;j<=1e3;j+=i) pvis[j]=1; } 

	cin >> N; int x; for (int i=0; i<N; i++) { vals.clear(); cin >> x;

        for (int j=1; j<prime.size() && prime[j] * prime[j] <= x; j++) { int cnt = 0;

            while (x%prime[j] == 0) { x /= prime[j]; cnt++; }

            if (cnt%2 == 1) vals.pb(prime[j]); }

        if (vals.empty() && x == 1) { cout << 1 <<'\n'; return 0; }

        vals.pb(x); if (vals.size() == 1) vals.pb(1); 

        for (int k: vals) if (ind.count(k) == 0)  

			{ if (k > 1e3) ind[k] = at++;				

			  else { int t=lower_bound(prime.begin(),prime.end(),k)-prime.begin();

				     ind[k]=t; start.insert(t); } }        	

		adj[ind[vals[0]]].pb(ind[vals[1]]);

        adj[ind[vals[1]]].pb(ind[vals[0]]);         

    }  

    for (int j: start) bfs(j);

    cout << (ans == MN ? -1 : ans) <<'\n';

}