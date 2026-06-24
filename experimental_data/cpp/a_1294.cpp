/*
─────────────────────
───────────████████──
──────────███▄███████
──────────███████████
──────────███████████
──────────██████─────
──────────█████████──
█───────███████──────
██────████████████───
███──██████████──█───
███████████████──────
███████████████──────
─█████████████───────
──███████████────────
────████████─────────
─────███──██─────────
─────██────█─────────
─────█─────█─────────
─────██────██────────
─────────────────────
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#define int long long
#define read(a) int a; cin >> a;
#define readarr(a, n) int a[(n) + 1] = {}; fori(i, 1, (n)) {cin >> a[i];}
#define readmat(a, n, m) int a[n + 1][m + 1] = {}; fori(i, 1, n) {fori(j, 1, m) cin >> a[i][j];}
#define pb push_back
#define fi first
#define se second
#define rz resize
#define fori(i, a, b) for (int i = (a); i <= (b); i++)
#define ford(i, a, b) for (int i = (a); i >= (b); i--)
#define sort1(v) sort(v.begin(), v.end()) 
#define endl '\n'

using namespace std;
using namespace __gnu_pbds; 

typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair <int, int>> vpi;
typedef vector < vector <int> > vvi;

const long long inf2 = (long long)1e18;
const long long mod = (long long)(1e9+7);
const long long inf1 =(long long)(1e6+1);
 
signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    read(t);
    while(t--)
    {
        int a, b, c, n; cin >> a >> b >> c >> n;
        if ( (a+b+c+n) % 3 == 0)
        {
            int temp = (a+b+c+n)/3;
            if(temp >= a && temp >= b && temp >= c) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else cout << "NO" << endl;
    }

    
    return 0;
}