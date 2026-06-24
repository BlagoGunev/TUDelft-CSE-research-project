///I'm choking
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const long long MOD = 1e9 + 7;
const int maxN = 2e5 + 5;

#define GBIT(num, i) (((num) >> (i)) & 1)

int label[maxN][11];
int find_set(int u, int base){
    return (label[u][base] < 0 ? u : label[u][base] = find_set(label[u][base], base));
}

void union_set(int u, int v, int base){
    label[u][base] += label[v][base];
    label[v][base] = u;
    //cout << "Union " << u << ' ' << v << '\n';
}

int n, m;
void solve(){
    cin >> n >> m;

    int a, d, k, l, r;

    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= 10; ++j)
            label[i][j] = -1;
    while(m--){
        cin >> a >> d >> k;
        l = a; r = a + k * d;

        l = find_set(l, d);
        while(l < r){
            a = find_set(l + d, d);
            union_set(a, l, d);
            l = find_set(l, d);
        }
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= 10; ++j){
            l = find_set(i, 0);
            r = find_set(find_set(i, j), 0);
            if(l != r)union_set(l, r, 0);
        }

    int cnt = 0;
    for(int i = 1; i <= n; ++i)
        cnt += (label[i][0] < 0);
    cout << cnt << '\n';
}

int T;
int main()
{
    if(fopen("input.txt", "r")){
        freopen("input.txt", "r", stdin);
    }
    //cin.tie(NULL)->sync_with_stdio(false);

    cin >> T;
    while(T--)solve();
    return 0;
}