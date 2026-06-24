#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<long long, long long> pll;
typedef pair<char, int> ci;
typedef pair<string, int> si;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
#define pb push_back
#define fi first
#define se second
#define whole(v) v.begin(), v.end()
#define rwhole(v) v.rbegin(), v.rend()
#define inf INT_MAX/2
#define fro front
#define pqueue priority_queue

bool bit(ll i, ll a){
    return (1LL << i) & a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        ll a; cin >> a;
        ll ans = 1;
        while(a > 3){
            a /= 4;
            ans *= 2;
        }
        cout << ans << endl;
    }
}