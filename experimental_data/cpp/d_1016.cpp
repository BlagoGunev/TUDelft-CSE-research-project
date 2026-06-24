#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int NMAX = 105;
int v[NMAX][NMAX];
int l[NMAX], c[NMAX];

int main() {
   // freopen("A.in", "r",stdin);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        cin >> l[i];
    for(int i = 1; i <= m; i ++)
        cin >> c[i];
    for(int i = 1; i < n; i ++)
        for(int j = 1; j < m; j ++)
            v[i][j] = 2;
    for(int i = 1; i < n; i ++) {
        int aux = 0;
        for(int j = 1; j < m; j ++) {
            aux ^= v[i][j];
        }
        v[i][m] = aux ^ l[i];
    }


    for(int j = 1; j <= m; j ++) {
        int aux = 0;
        for(int i = 1; i < n; i ++)
            aux ^= v[i][j];
        v[n][j] = aux ^ c[j];
    }


    for(int i = 1; i <= n; i ++) {
        int aux = 0;
        for(int j = 1; j <= m; j ++)
            aux ^= v[i][j];
        if(aux != l[i]) {
            cout << "NO";
            return 0;
        }
    }


    for(int j = 1; j <= m; j ++) {
        int aux = 0;
        for(int i = 1; i <= n; i ++) {
            aux ^= v[i][j];
        }
        if(aux != c[j]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
    return 0;
}