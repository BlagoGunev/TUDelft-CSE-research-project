/*Starting with the name of Allah*/

/*Md. Mainul Islam Tahim, CSE-KUET*/

//Linkedin: https://www.linkedin.com/in/md-mainul-islam/

//Codeforces: https://codeforces.com/profile/Tahim_097

//Codechef: https://www.codechef.com/users/tahim_097





//#include<bits/stdc++.h>

#include <iostream>

#include<cstdlib>

#include<cstring>

#include<cmath>

#include<vector>

#include<algorithm>

#include<iomanip>

#include<map>

#include<set>

#include<queue>

#include<string>

#include<fstream>

using namespace std;



//For Ordered_Set

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>



//Aliases

using ll = long long;

using lld = long double;

using ull = unsigned long long;



//Constants

const lld pi = 3.141592653589793238;

const ll INF = 1e18;

const ll mod = 1e9 + 7;



//TypeDEf

typedef pair<ll, ll> pll;

typedef vector<ll> vll;

typedef vector<pll> vpll;

typedef vector<string> vs;

typedef vector<vll> vvll;

typedef map<ll, ll> mll;



// Operator overloads

template<typename T1, typename T2> // cin >> pair<T1, T2>

istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second);}

template<typename T> // cin >> vector<T>

istream& operator>>(istream &istream, vector<T> &v) {for (auto &it : v)cin >> it; return istream;}

template<typename T1, typename T2> // cout << pair<T1, T2>

ostream& operator<<(ostream &ostream, const pair<T1, T2> &p)

{ return (ostream << p.first << " " << p.second); }

template<typename T> // cout << vector<T>

ostream& operator<<(ostream &ostream, const vector<T> &c)

{ for (auto &it : c) cout << it << " "; return ostream; }



// Macros

#define I ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define ff first

#define ss second

#define pb push_back

#define mp make_pair

#define fl(i,n) for(ll i=0;i<n;i++)

#define fl1(i,n) for(ll i=1;i<=n;i++)

#define flr(i,n) for(ll i=n-1;i>=0;i--)

#define py cout<<"YES\n";

#define pmm cout<<"-1\n";

#define pnn cout<<"NO\n";

#define endl "\n";

#define vs(v) sort(v.begin(),v.end());

#define vsr(v) sort(v.begin(),v.end(),greater<ll>());

#define vps(v) v.begin(),v.end()

#define T cin>>tt; while(tt--)

#define Q tt=1; while(tt--)



// Mathematical functions

ll gcd(ll a, ll b) {if (b == 0)return a; return gcd(b, a % b);} //__gcd

ll lcm(ll a, ll b) {return (a / gcd(a, b) * b);}

ll pw(ll x, ll y) { ll a = 1; for (ll i = 0; i < y; i++) a *= x; return a;}



//Sorting

bool sortac(const pair<int, int> &a, const pair<int, int> &b) {return (a.second < b.second);}

bool sortdc(const pair<int, int> &a, const pair<int, int> &b) {return (a.second > b.second);}



//Check

bool isPrime(ll n)

{

    if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false;

    for (int i = 5; i * i <= n; i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false;

    return true;

}

bool isPowerOfTwo(int n) {if (n == 0)return false; return (ceil(log2(n)) == floor(log2(n)));}

bool isPerfectSquare(ll x) {if (x >= 0) {ll sr = sqrt(x); return (sr * sr == x);} return false;}







//Variables

ll i, j, k, tt, d, e, f, h, n, m, l, r, o, p, q, t, x, y, z, mx, mn, ans;



void solve()

{

    cin >> n >> m;

    char a[n + 3][m + 3];

    for (i = 1; i <= n; i++)

    {

        for (j = 1; j <= m; j++)

            cin >> a[i][j];

    }

    if (a[1][1] == '1')

    {

        pmm

        return;

    }

    vpll x1, x2;

    for (i = n; i > 0; i--)

    {

        for (j = m; j > 0; j--)

        {

            f = 0;

            if (a[i][j] == '1')

            {

                if ((j - 1) > 0)

                {

                    x1.push_back(mp(i, j - 1));

                    x2.push_back(mp(i, j));

                    f = 1;

                }

                if (f == 1)

                    continue;

                if ((i - 1) > 0)

                {

                    x1.push_back(mp(i - 1, j));

                    x2.push_back(mp(i, j));

                }

            }

        }

    }

    l = x1.size();

    cout << l << endl

         for (i = 0; i < l; i++)

    {

        cout << x1[i].ff << " " << x1[i].ss << " " << x2[i].ff << " " << x2[i].ss << endl

    }

}



int main()

{

    I

    T

    {

        solve();

    }

    return 0;

}





//END!