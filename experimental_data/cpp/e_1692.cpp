#include <bits/stdc++.h>

#include <numeric>



using namespace std;

typedef long long ll;

typedef long double ld;



typedef pair<int, int> pi;

typedef pair<ll, ll> pl;

typedef pair<ld, ld> pd;



typedef vector<int> vi;

typedef vector<ll> vl;

typedef vector<ld> vd;

typedef vector<pi> vpi;

typedef vector<pl> vpl;



#define F first

#define S second

#define pb push_back

#define mp make_pair

#define ub(v,val) upper_bound(v.begin(),v.end(),val)

#define lb(v,val) lower_bound(v.begin(),v.end(),val)

#define rep(i, a, b) for(int i = a; i < (b); i++)

#define rrep(i, a, b) for(int i = (b)-1; i >= a; i--)

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define PI 3.141592654



void solve(){

    int n, s, sum = 0, ans = INT_MAX;

    cin >> n >> s;

    vi a(n);

    vi p(n);

    rep(i, 0, n){

        cin >> a[i];

        sum += a[i];

        p[i] = sum;

    }

    int l = -1, r = n, m;

    while(r > l+1){

        m = (l+r)/2;

        if(p[m] <= s){

            l = m;

        } else{

            r = m;

        }

    }

    r = l;

    if(r != -1 && p[r] == s){

        ans = min(ans, n-1-r);

    }

    rep(i, 1, n){

        l = i-1; r = n;

        while(r > l+1){

            m = (l+r)/2;

            if(p[m]-p[i-1] <= s){

                l = m;

            } else{

                r = m;

            }

        }

        r = l;

        if(r != -1 && p[r]-p[i-1] == s){

            ans = min(ans, n-1-r+i);

        }

    }

    if(ans == INT_MAX){

        cout << "-1\n";

        return;

    }

    cout << ans << '\n';

}



int main()

{

    fast;

    int t;

    cin >> t;

    while(t--){

        solve();

    }

}