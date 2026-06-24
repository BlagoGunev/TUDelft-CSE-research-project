#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

long long INF=numeric_limits<long long>::max();

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    ll n,ans(0);
    cin >> n;
    if(n%2==0)
    {
        ans = n/2;
    }
    else
    {
        ll m = sqrt(n);
        bool run = 0;
        if(m%2==0)m--;
        for(ll i = 3; i <= m; i+=2)
        {
            run = 1;
            if(n%i==0)
            {
                n -= i;
                break;
            }
            if(i==m)n = 0;
        }
        if(!run)n = 0;
        ans = n/2 + 1;
    }
    cout << ans << endl;
}