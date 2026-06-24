#include<bits/stdc++.h>

using namespace std;
vector<int> a;
vector<int> res;
vector<int> used;
void dfs(int v, int timer){
    if (res[v] == 0 && used[v] >= 0)
        res[v] = timer - used[v];
    used[v] = timer;
    if (res[a[v]] == 0)
        dfs(a[v], timer+1);
}
int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int q; cin >> q;
    for (int t = 0; t < q; ++t){
        int n; cin >> n;
        a.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i]--;
        }
        res.assign(n, 0);
        used.assign(n, -1);
        for (int i = 0; i < n; ++i){
            if (used[i] == -1)
                dfs(i, 0);
        }
        for (int &i : res)
            cout << i << ' ' ;
        cout << '\n';
    }
    return 0;
}