#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fi first
#define se second
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ps push
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)b((x).size())
#define FOR(i,k) for(int i = 0; i < (k); i++)
#define foll(i,k) for(long long i = 0; i < (k); i++)
#define FORr(i,k) for(int i = (k)-1; i >= 0; i--)
#define folr(i,k) for(long long i = (k)-1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 998244353;
const int MAXN = 3000010;

unordered_map<ll, ll> m;

ll dp(ll a){
    if(m.count(a))return m[a];
    if(a%2){
        m[a] = (dp(a/2) + dp(a/2+1))%MOD;
    }else{
        m[a] = dp(a/2);
    }
    return m[a];
}

unordered_map<ll, ll> s;

ll slv(ll N){
    if(s.count(N)){
    }else if(N%2){
        s[N] = (slv(N/2)*2 + dp(N/2 + 1))%MOD;
    }else{
        s[N] = (2*slv(N/2) + 2*slv((N-1)/2))%MOD;
    }
    return s[N];
}

void solve(){
    ll N, M; cin >> N >> M;
    if(M > 2){
        if(N%2){
            N = (N+1)/2;
            N%=MOD;
            cout << (N*N)%MOD << endl;
        }else{
            cout << (((N/2)%MOD)*((N/2+1)%MOD))%MOD << endl;
        }
    }else if(M == 1){
        cout << N%MOD << endl;
    }else{
        cout << slv(N) << endl;
    }





	return;
}

int main(){
	int T = 1;
	cin >> T;
    m[0] = 0;
    m[1] = 1;
    m[2] = 1;
    s[0] = 0;
    s[1] = 1;
    s[2] = 2;
	while(T--)solve();
	return 0;
}