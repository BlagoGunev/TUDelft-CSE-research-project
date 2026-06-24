#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <algorithm>

#define edge pair<int,int>

#define FOR(i,a,b) for(int i = a; i < b; i++)

using namespace std;

// reversing the prufer code
int main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<edge> edges;

    map<int, int> num_children;

    vector<int> asc_imp;

    vector<int> code;
    FOR(i, 0, n-1) {
        int t;
        cin >> t;
        code.push_back(t);
        num_children[t]++;
    }

    int root = code[0];

    priority_queue<int, vector<int>, greater<int> > leaves;

    FOR(i, 1, n+1) {
        if (num_children[i] == 0) {
            leaves.push(i);
        }
    }

    FOR(i, 0, n-1) {
        int child = leaves.top();
        leaves.pop();
        int parent = code[n - 2 - i];

        num_children[parent]--;
        if (num_children[parent] == 0) {
            leaves.push(parent);
        }

        edges.push_back(edge(parent, child));
    }

    cout << root << '\n';
    for (edge e : edges) {
        cout << e.first << " " << e.second << '\n';
    }
}