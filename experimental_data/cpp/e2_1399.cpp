#include <bits/stdc++.h>



using namespace std;



typedef long long ll;



const ll MOD = 1e9 + 7, inf = 1e18, N = 3e5 + 7;



ll n, s, ans;

vector<pair<ll, pair<ll, ll>>> adj[N];

multiset<pair<ll, ll>> pathOne, pathTwo;

vector<ll> A, B;

ll sz[N];



void dfs(ll node, ll p, ll w, ll c){

    sz[node] = 0;

    if(adj[node].size() == 1 && node != 1)

        sz[node] = 1;

    for(auto child : adj[node]){

        if(child.first == p)

            continue;

        dfs(child.first, node, child.second.first, child.second.second);

        sz[node] += sz[child.first];

    }

    ans += sz[node] * w;

    if(node != 1){

        if(c == 1){

            pathOne.insert({w, sz[node]});

        }

        else{

            pathTwo.insert({w, sz[node]});

        }

    }

}



void doWork(){

    cin >> n >> s;

    pathOne.clear();

    pathTwo.clear();

    A.clear();

    B.clear();

    ans = 0;

    for(ll i = 0; i <= n; i++)

        adj[i].clear();

    for(ll i = 0; i < n - 1; i++){

        ll u, v, w, c;

        cin >> u >> v >> w >> c;

        adj[u].push_back({v, {w, c}});

        adj[v].push_back({u, {w, c}});

    }

    dfs(1, 1, 0, 0);

    if(ans <= s){

        cout << 0 << '\n';

        return;

    }

    for(auto i : pathOne){

        while(i.first){

            A.push_back(i.second * (i.first / 2) - i.second * i.first);

            i.first /= 2;

        }

    }

    for(auto i : pathTwo){

        while(i.first){

            B.push_back(i.second * (i.first / 2) - i.second * i.first);

            i.first /= 2;

        }

    }

    ll cnt = inf;

    sort(A.begin(), A.end());

    sort(B.begin(), B.end());

    for(ll i = 1; i < B.size(); i++)

        B[i] += B[i - 1];

    if(B.empty()){

        B.push_back(0);

    }

    ll j = B.size() - 1;

    while(j >= 0 && B[j] + ans <= s){

        cnt = (j + 1) * 2;

        if(j > 0)

            j--;

        else

            break;

    }

    if(A.empty()){

        cout << cnt << '\n';

        return;

    }

    ll pre = 0;

    for(ll i = 0; i < A.size(); i++){

        pre += A[i];

        while(pre + B[j] + ans <= s){

            cnt = min(cnt, (j + 1) * 2 + i + 1);

            if(j > 0)

                j--;

            else

                break;

        }

        if(pre + ans <= s){

            cnt = min(cnt, i + 1);

        }

    }

    cout << cnt << '\n';

}



int main(){

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

#endif

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll T = 1;

    cin >> T;

    for(ll i = 1; i <= T; i++){

        doWork();

    }

}