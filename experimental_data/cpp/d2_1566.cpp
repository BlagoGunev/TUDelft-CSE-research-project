#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

struct fen{
    vector<ll> fa;
    int sz = 0;

    fen(int asz){
        sz = asz+5;
        fa.resize(sz);
    }
    void add(int pos, ll val){
        for(; pos < sz; pos += pos&-pos) fa[pos] += val;
    }
    ll sum(int pos){
        int ans = 0;
        for(; pos > 0; pos -= pos&-pos) ans += fa[pos];
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vector<pi> people(n*m); //sight, m-pos
        for(int i = 0; i < n*m; i++){
            int a; cin >> a; people[i] = {a, i};
        }
        sort(people.begin(), people.end());

        vector<int> seatpos(n*m);
        for(int i = 0; i < n*m; i++) seatpos[people[i].s] = i;

        vector<int> spos(n*m);
        int cur = -1, cpos = 0;

        for(int i = 0; i < n*m; i++){
            if(people[i].f != cur){
                cur = people[i].f; cpos = i;
            }
            spos[people[i].s] = cpos;
        }

        vector<fen> psums;
        for(int i = 0; i < n; i++) psums.emplace_back(m);

        ll ans = 0;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                int i = r*m + c;
                int cr = seatpos[i]/m, cc = seatpos[i]%m;
                ans += psums[cr].sum(spos[i]-cr*m);
                psums[cr].add(cc+1,1);
            }
        }
        cout << ans << "\n";
    }
}