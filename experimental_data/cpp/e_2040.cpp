#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 99824435
vector<vector<int>> v;
vector<int> pa, deg, de;
void dfs(int x, int p, int depth){
    pa[x] = p, de[x] = depth;;
    for (auto el : v[x]){
        if (el != p){
            dfs(el, x, depth + 1);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--){
        int n, q, a, b, x, p;
        cin>>n>>q;
        v.assign(n + 1, vector<int>()), pa.assign(n + 1, 0), de.assign(n + 1, 0), deg.assign(n + 1, 0);
        for (int i = 0; i < n - 1; i++){
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
            deg[a]++, deg[b]++;
        }
        dfs(1, 1, 0);
        while (q--){
            cin>>x>>p;
            vector<int> so;
            ll ans = 0;
            if (de[x] % 2 == 1) ans++;
            while (x != 1){
                x = pa[x];
                if (x != 1) so.push_back(deg[x]);
                x = pa[x];
            }
            sort(so.begin(), so.end());
            int si = so.size();
            for (int i = 0; i < so.size(); i++){
                if (i >= si - p){
                    ans += 2;
                }
                else{
                    ans += so[i] * 2;
                }
                ans %= mod;
            }
            cout<<ans<<"\n";
        }
    }
}