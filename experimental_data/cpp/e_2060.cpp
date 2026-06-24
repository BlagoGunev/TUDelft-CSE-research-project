#include <bits/stdc++.h>

using namespace std;

#define int long long

vector <int> dsu(200002, -1);
vector <int> siz(200002, 1);
int findr(int cur) {
    if(dsu[cur] == -1) {
        return cur;
    }
    return dsu[cur] = findr(dsu[cur]);
}

vector <int> dsu2(200002, -1);
vector <int> siz2(200002, 1);
int findr2(int cur) {
    if(dsu2[cur] == -1) {
        return cur;
    }
    return dsu2[cur] = findr2(dsu2[cur]);
}

signed main() {
    //your code goes here
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, m, k;
        cin >> n >> m >> k;
        vector <vector <int>> arr(n);
        for(int i = 0; i < n; i++) {
            dsu[i] = -1;
            siz[i] = 1;
            dsu2[i] = -1;
            siz2[i] = 1;
        }
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            arr[min(u, v)].push_back(max(u, v));
        }
        int com = n;
        for(int i = 0; i < k; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            int v1 = findr(u);
            int v2 = findr(v);
            if(v1 == v2) {
                continue;
            }
            int v3 = siz[v1];
            int v4 = siz[v2];
            com--;
            if(v3 >= v4) {
                dsu[v2] = v1;
                siz[v1] += v4;
            } else {
                dsu[v1] = v2;
                siz[v2] += v3;
            }
        }
        int total = 0;
        int comp = n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < arr[i].size(); j++) {
                int v = arr[i][j];
                int v2 = findr(i);
                int v3 = findr(v);
                if(v2 == v3) {
                    int va1 = findr2(i);
                    int va2 = findr2(v);
                    if(va1 == va2) {
                        continue;
                    }
                    comp--;
                    int va3 = siz2[va1];
                    int va4 = siz2[va2];
                    if(v3 >= va4) {
                        dsu2[va2] = va1;
                        siz2[va1] += va4;
                    } else {
                        dsu2[va1] = va2;
                        siz2[va2] += va3;
                    }
                } else {
                    total++;
                    continue;
                }
            }
        }
        cout << total+(comp-com) << endl;
    }
    return 0;
}