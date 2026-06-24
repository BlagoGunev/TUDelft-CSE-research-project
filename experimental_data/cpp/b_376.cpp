#include <bits/stdc++.h>



using namespace std;



int n, m;

int x[101];



int main() {

    //freopen("input.txt", "r", stdin);

    memset(x, 0, sizeof(x));

    cin >> n >> m;

    for(int i = 1; i <= m; i++) {

        int u, v, s;

        cin >> u >> v >> s;

        x[u] += s;

        x[v] -= s;

    }



    int res = 0;

    for(int i = 1; i <= n; i++) {

        if (x[i] > 0) {

            res += x[i];

        }

    }



    cout << res << endl;

}