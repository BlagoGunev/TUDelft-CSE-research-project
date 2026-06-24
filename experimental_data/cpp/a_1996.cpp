#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long int> vi;
#define pb push_back
#define mp make_pair
#define all(c) c.begin(), c.end()
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define get(n) ll n; cin >> n;
#define gets(n, m) ll n, m; cin >> n >> m;
#define getss(n, m, o) ll n, m, o; cin >> n >> m >> o;
#define show(n) cout << n << endl;
#define getv(n) vi v(n); loop(i, 0, n) cin >> v[i];
#define sort(v) sort(all(v));
#define getstr(s) string s; cin >> s;
#define showstr(s) cout << s << endl;
#define showv(v) loop(i, 0, v.size()) cout << v[i] << " ";
#define endl "\n";
#define sp " ";
#define getmatrix(n, m) vector<vector<ll>> v(n, vector<ll>(m)); loop(i, 0, n) loop(j, 0, m) cin >> v[i][j];
#define showmatrix(n, m) loop(i, 0, n) {loop(j, 0, m) cout << v[i][j] << " "; cout << endl;}
#define gethashmap(n) map<ll, ll> m; loop(i, 0, n) {int a; cin >> a; m[a]++;}
#define showhashmap for (auto it = m.begin(); it != m.end(); it++) cout << it->first << sp << it->second << endl;
#define getset(n) set<int> s; loop(i, 0, n) {int a; cin >> a; s.insert(a);}
#define sumv(v) accumulate(all(v), 0);

long long int NcR(int n, int r)
{
 
    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;
 
    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
 
            // gcd of p, k
            long long m = __gcd(p, k);
 
            // dividing by gcd, to simplify
            // product division by their gcd 
            // saves from the overflow
            p /= m;
            k /= m;
 
            n--;
            r--;
        }
 
        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }
 
    else
        p = 1;
 
    // if our approach is correct p = ans and k =1
   return p;
}

void yesno (bool c) {
    if (c) {       cout << "YES" << endl;
    }   
     else { 
            cout << "NO" << endl;
    }
}
const ll sqrt_lim=1000001;
set<long long> prime_squares()
{
    static bool arr[sqrt_lim];

    for (int i = 2; i*i < sqrt_lim; i++)
    {
        if (!arr[i])
        {
            for (int j = i*i; j < sqrt_lim; j += i)
            {
                arr[j] = true;
            }
        }
    }

    set<long long> res;
    for (int i = 2; i < sqrt_lim; i++)
    {
        if (!arr[i])
            res.insert(i);
    }
    return res;
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       get(n);
         int x = n/4;
         if(n%4!=0){
             x++;
         }
            cout<<x<<endl;

    }
    return 0;
}