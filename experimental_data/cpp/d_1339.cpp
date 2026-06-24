#include <algorithm>

#include <iostream>

#include <vector>

using namespace std;



typedef long long ll;

const int maxn = 2e5 + 7;



vector<int> v[maxn];

int dep[maxn];

int cnt[maxn];



void dfs(int u, int fa)

{

    for (auto x : v[u]) {

        if (x == fa)

            continue;

        dep[x] = dep[u] + 1;

        dfs(x, u);

    }

}



int main()

{

    ios::sync_with_stdio(false);

	cin.tie(0), cout.tie(0);



    int n;

    cin >> n;

    for (int i = 1; i < n; i++) {

        int a, b;

        cin >> a >> b;

        v[a].push_back(b);

        v[b].push_back(a);

    }



    int root = -1;

    for (int i = 1; i <= n; i++)

        if (v[i].size() == 1) {

            root = i;

            cnt[v[i][0]]++;

        }



    dfs(root, -1);



    int mx = n - 1, mn = 1;

    for (int i = 1; i <= n; i++) {

        if (v[i].size() == 1 && ((dep[i] - dep[root]) & 1))

            mn = 3;

        if (cnt[i] >= 2)

            mx -= (cnt[i] - 1);

    }

    cout << mn << ' ' << mx << '\n';



    return 0;

}