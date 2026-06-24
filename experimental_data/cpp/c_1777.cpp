#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ldb;
 
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ldb,ldb> pdd;

#define ff(i,a,b) for(int i = a; i <= b; i++)
#define fb(i,b,a) for(int i = b; i >= a; i--)
#define trav(a,x) for(auto& a : x)
 
#define sz(a) (int)(a).size()
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// os.order_of_key(k) the number of elements in the os less than k
// *os.find_by_order(k)  print the k-th smallest number in os(0-based)

const int mod = 1000000007;
const int inf = 1e9 + 5;
const int mxN = 100005; 

int n, m;
int niz[mxN];

const int N = 1e5;
vector<int> d[N + 5];

int br = 0;
int cnt[mxN];
void add(int X){
    for(auto c : d[X]){
        if(c <= m){
            br += (cnt[c] == 0);
            cnt[c] += 1;
        }
    }
}

void del(int X){
    for(auto c : d[X]){
        if(c <= m){
            cnt[c] -= 1;
            br -= (cnt[c] == 0);
        }
    }
}

void Solve(){
    cin >> n >> m;
    ff(i,1,n)cin >> niz[i];
    sort(niz + 1, niz + n + 1);

    br = 0;
    ff(i,1,m)cnt[i] = 0;

    int j = 1; int rez = inf;
    ff(i,1,n){
        add(niz[i]);
        while(j < i){
            del(niz[j]);
            if(br == m)j += 1;
            else{
                add(niz[j]);
                break;
            }
        }

        if(br == m)rez = min(rez, niz[i] - niz[j]);

    }

    cout << (rez == inf ? -1 : rez) << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j += i){
            d[j].pb(i);
        }
    }

    int t = 1;
    cin >> t;
    while(t--)Solve();

    return 0;
}
/*



// probati bojenje sahovski
*/