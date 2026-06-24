#include<iostream>

#include<iterator>

#include<algorithm>

#include<bits/stdc++.h>



using namespace std;



typedef  long long  int ll;

typedef  long double ld;

typedef std::vector<int> vi;

typedef std::vector<ll> vll;

typedef std::vector<ld> vld;

typedef std::vector<std::vector<ll> > vvll;

typedef std::vector<std::vector<ld> > vvld;

typedef std::vector<std::vector<std::vector<ll> > > vvvll;

typedef std::vector<string> vstr;

typedef std::vector<std::pair<ll,ll> > vpll;

typedef std::pair<ll,ll> pll;



#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;

#define ordered_set     tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>



#define fast            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define pb              push_back

#define nl              "\n"

#define all(c)          (c).begin(),(c).end()

#define iotam1            cout<<-1<<nl

#define cty             cout<<"YES"<<nl

#define ctn             cout<<"NO"<<nl

#define lmax            LLONG_MAX

#define lmin            LLONG_MIN

#define sz(v)           (v).size()

#define deci(n)         fixed<<setprecision(n)

#define c(x)            cout<<(x)

#define csp(x)          cout<<(x)<<" "

#define c1(x)           cout<<(x)<<nl

#define c2(x,y)         cout<<(x)<<" "<<(y)<<nl

#define c3(x,y,z)       cout<<(x)<<" "<<(y)<<" "<<(z)<<nl

#define c4(a,b,c,d)     cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<nl

#define c5(a,b,c,d,e)   cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<nl

#define c6(a,b,c,d,e,f) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<" "<<(f)<<nl



#define f(i_itr,a,n) for(ll i_itr=a; i_itr<n; i_itr++)

#define rev_f(i_itr,n,a) for(ll i_itr=n; i_itr>a; i_itr--)

#define arri(n, arr) for(ll i_itr=0; i_itr<n; i_itr++) cin>>arr[i_itr]

#define a_arri(n, m, arr) for(ll i_itr=0; i_itr<n; i_itr++) for (ll j_itr=0; j_itr<m; j_itr++) cin>>arr[i_itr][j_itr]

#define pb push_back

#define fi first

#define se second

#define print(vec,a,b) for(ll i_itr=a;i_itr<b;i_itr++) cout<<vec[i_itr]<<" ";cout<<"\n";

#define input(vec,a,b) for(ll i_itr = a;i_itr<b;i_itr++) cin>>vec[i_itr];

#define ms(a,val) memset(a,val,sizeof(a))





const ll mod = 1000000007;

const long double pi=3.14159265358979323846264338327950288419716939937510582097494459230;



ll pct(ll x) { return __builtin_popcount(x); } // # of set bits

ll poww(ll a, ll b) { ll res=1; while(b) { if(b&1)	res=(res*a); a=(a*a); b>>=1; } return res; }

ll modI(ll a, ll m=mod) { ll m0=m,y=0,x=1;  if(m==1) return 0;  while(a>1)  { ll q=a/m; ll t=m;  m=a%m;  a=t; t=y; y=x-q*y;  x=t; } if(x<0) x+=m0; return x;}

ll powm(ll a, ll b,ll m=mod) {ll res=1;	while(b) {	if(b&1)	res=(res*a)%m;	a=(a*a)%m; b>>=1;	}	return res;}

//******************************************************************************************************************************************* /



const ll N = 500 + 5;



string str[N];



void ok_boss()

{

    ll n,m;

    cin >> n >> m;



    f(i,0,n)

        str[i].clear(),cin >> str[i];



    if(m%3 != 1)

    {

        for(ll i=1;i<m;i+=3)

        {

            f(j,0,n)

                str[j][i] = 'X';

        }



        for(ll i=2;i<m;i+=3)

        {

            bool ok=0;



            f(j,0,n)

            {

                if(str[j][i] == 'X')

                {

                    str[j][i+1] = 'X';

                    ok=1;

                    break;

                }

            }



            if(ok)

                continue;



            f(j,0,n)

            {

                if(str[j][i+1] == 'X')

                {

                    str[j][i] = 'X';

                    ok=1;

                    break;

                }

            }



            if(ok)

                continue;



            str[0][i] = str[0][i+1]= 'X';



        }

    }

    else

    {

        for(ll i=0;i<m;i+=3)

        {

            f(j,0,n)

                str[j][i] = 'X';

        }



        for(ll i=1;i<m;i+=3)

        {

            bool ok=0;



            f(j,0,n)

            {

                if(str[j][i] == 'X')

                {

                    str[j][i+1] = 'X';

                    ok=1;

                    break;

                }

            }



            if(ok)

                continue;



            f(j,0,n)

            {

                if(str[j][i+1] == 'X')

                {

                    str[j][i] = 'X';

                    ok=1;

                    break;

                }

            }



            if(ok)

                continue;



            str[0][i] = str[0][i+1]= 'X';



        }



    }



    f(i,0,n)

        c1(str[i]);



}



int main()

{

    fast;



    ll qq_itr=1;

    cin >> qq_itr;

    while (qq_itr--)

        ok_boss();

    return 0;

}