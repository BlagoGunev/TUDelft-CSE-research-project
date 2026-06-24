///**Bismillahir Rahmanir Raheem**
///**       Mizanul Hoque       **
///**           IIUC            **
///###############################
#include<bits/stdc++.h>
using namespace std;
///POLICY BASED DATA STRUCTURE..
///order_of_key return number of element which are strictly greater/smaller than x..
///find_by_order return ans iterator corresponding to the xth position of the set..

//#include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

#define faster ios_base::sync_with_stdio(false);cin.tie(NULL)

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define sz(n) (int)(n).size()
#define eps 1e-10

#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;

#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))

#define pi 2*acos(0)  /// acos(-1.0)
#define deg_to_rad(x) ((x)*((2*acos(0))/180.0))
#define rad_to_deg(x) ((x)*(180.0/(2*acos(0))))

#define fi first
#define sc second
#define mp make_pair
#define __lcm(a,b) (a/__gcd(a,b)*b)

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int M = 1e9 + 7;
const int N = 200020;

//ll n,m,i,k,h;

vector<ll>prime_divisor[N];
int vis[N];
vector<int>edge[N];

bool cmp(pair<ll,ll>p1,pair<ll,ll>p2)
{
    return p1.fi<p2.fi;
}




void solve()
{
     ll i,j,k,n,m,p,q,x,y,z,u,v,l,r,mod=1e9+7,mx,mn,mx1,mn1,cnt1,cnt;
    cin>>n;
    string s;
    vector<int>vv;
   for(i=0;i<n;i++)
   {
    cin>>s;
    for(j=0;j<sz(s);j++)
    {
        if(s[j]=='#')
        {
            vv.pb(j+1);
            break;
        }
    }
   }
   reverse(all(vv));
   for(i=0;i<sz(vv);i++)
   {
    cout<<vv[i]<<" ";
   }
   cout<<endl;

}


int main()
{
    faster;
    ll tc=1;
    cin>>tc;
    for(ll t=1;t<=tc;t++)
    {
        /// cout<<"Case "<<t<<": ";
         solve();
    }

    return 0;
}