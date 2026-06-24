#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#define lowbit(x) x&(-x)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 2e5+5, M = 6000+5;
const ll inf = 1LL << 60;
const int mod = 1e9+7;
const double esp = 1e-6;
 
template <typename T> void inline read(T& x) {
	int f = 1; x = 0; char s = getchar();
	while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
	while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
	x *= f;
}

int t,a[N],b[N];

void solve(){
    int n;
    ll k;
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    int maxx=*max_element(a+1,a+1+n);
    for(int i=1;i<=n;++i){
        a[i]=-a[i]+maxx;
    }
    k--;
    k%=2;
    while(k){
        int maxx=*max_element(a+1,a+1+n);
        for(int i=1;i<=n;++i){
            a[i]=-a[i]+maxx;
        }
        k--;
    }
    for(int i=1;i<=n;++i) cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>t;
    while(t--){
        solve();
    }
	return 0;
}