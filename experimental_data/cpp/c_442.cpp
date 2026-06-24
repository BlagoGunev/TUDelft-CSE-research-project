#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Fit(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007
#define sz(a) ((int)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return s == 0 ? 0 : cntbit(s >> 1) + (s & 1);}

#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-15
typedef pair<int, int> II;

#define maxn 1000005

int n;
ll a[maxn];
int nex[maxn], pre[maxn], flag[maxn];
ll res = 0;

void xoa(int i){
    flag[i] = 1;
    int u = pre[i], v = nex[i];
    nex[u] = v;
    pre[v] = u;
    res += min(a[u], a[v]);
    int uu = nex[u], vv = pre[u];
    if(a[uu] >= a[u] && a[vv] >= a[u]){
        xoa(u);
    }
}

int main(){
//  freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    ms(a, 0);
    For(i, 1, n){
        cin >> a[i];
        nex[i] = i + 1;
        pre[i] = i - 1;
    }

    ms(flag, 0);
    For(i, 2, n - 1){
        int u = pre[i], v = nex[i];
        if(a[u] >= a[i] && a[v] >= a[i]){
            xoa(i);
        }
    }
    vector<int> V;
    For(i, 1, n) if(!flag[i]) V.pb(a[i]);
    sort(all(V));
    for(int i = sz(V) - 3; i >= 0; i--){
        res += V[i];
    }
    cout << res << endl;

    return 0;
}