#include <bits/stdc++.h>

using namespace std;

#define ln '\n'

#define fast cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);

#define all(v) v.begin(), v.end()

#define yes cout << "YES\n"

#define no cout << "NO\n"

#define ll long long



const int N = 2e5+1;



struct Node{

    int id;

    int color = -1;

    vector<Node*>neighbours;

    Node(int _id) : id(_id) {}

};



void BFS(vector<Node*>& nodes, queue<int>& q){

    while (!q.empty()){

        int x = q.front();

        q.pop();

        for(auto neighbour : nodes[x]->neighbours){

            if(neighbour->color == -1){

                neighbour->color = nodes[x]->color;

                q.push(neighbour->id);

            }

        }

    }

}



void solve(){

    int n, k; cin >> n >> k;

    int x, u, v;

    vector<Node*>nodes(n);

    for (int i = 0; i < n; ++i)

        nodes[i] = new Node(i);

    queue<int>q;

    for (int i = 0; i < k; ++i) {

        cin >> x;

        nodes[--x]->color = 0;

        q.push(x);

    }

    for (int i = 0; i < n-1; ++i) {

        cin >> u >> v;

        u--, v--;

        nodes[u]->neighbours.push_back(nodes[v]);

        nodes[v]->neighbours.push_back(nodes[u]);

    }

    q.push(0);

    nodes[0]->color = 1;

    BFS(nodes, q);

    for (int i = 1; i < n; ++i) {

        if(nodes[i]->neighbours.size() == 1 && nodes[i]->color == 1){

            yes;

            return;

        }

    }

    no;

}



int main() {

    fast

    int t; cin >> t;

    while (t--)

        solve();

    return 0;

}