#include<bits/stdc++.h>



using namespace std;

typedef long long ll;



bool dfs(int x, vector<vector<int>> &roads, vector<bool> &visited, int parent)

{

    if (visited[x]) return true;

    visited[x] = true;

    bool v = false;

    for (int child : roads[x])

    {

        if (child == parent) continue;

        if (dfs(child, roads, visited, x)) v = true;

    }

    return v;

}



// long loooooooooooooooong;

void solve(ll kkkk, ll tttt)

{

    int n; cin >> n; int w; cin >> w;

    vector<int> arr(n); for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 1; i < n; i++)

    {

        if (arr[i] == 0) continue;

        int c = min(arr[i] * i, w) / i;

        arr[0] += c;

        w-=c * i;

    }

    cout << arr[0] << endl;

}



void fast() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }



int main()

{

    fast();

//    int t = 0, i = 0;

    int t; cin >> t;

    for (int i = 1; i <= t; i++)



        solve(t, i);

    return 0;

}