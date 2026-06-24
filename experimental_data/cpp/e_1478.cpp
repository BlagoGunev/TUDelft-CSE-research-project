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

#define ordered_set     tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>



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



const ll N = 2e5 + 5;



ll inp[N];



class segment_tree{

    public :



    ll n,h;

    vll t;

    vll d;



ll never = -1e18; ///Here store the value which will never occur in any modifications, also sum of modifications cannot reach it.

///If such "never" doesn't exist then take a boolean array to check if we have to modify or not.



    ///In all the functions range l to r is considered [l,r].

    ///0-indexed.





    int __log2(int x) {

        return 32 - __builtin_clz(x) - 1;

    }



    ll __log2l(long long x)

    {

        return 64 - __builtin_clzll(x) - 1;

    }



    segment_tree(ll n) : n(n),t(n<<1,0){

        d.resize(n+1,never);

        h = __log2l(n) + 1;

    };



    void calc(ll p, ll k) {

      if (d[p] == never) t[p] = t[p<<1] + t[p<<1|1];

      else t[p] = d[p] * k;

    }



    void apply(ll p, ll value, ll k) {

      t[p] = value * k;

      if (p < n) d[p] = value;

    }



    void build(ll l, ll r) {      ///O(log(n) + |r-l|)

        r++;

      ll k = 2;

      for (l += n, r += n-1; l > 1; k <<= 1) {

        l >>= 1, r >>= 1;

        for (ll i = r; i >= l; --i) calc(i, k);

      }

    }



    void push(ll l, ll r) {       ///O(log(n) + |r-l|)

        r++;



      ll s = h, k = 1 << (h-1);

      for (l += n, r += n-1; s > 0; --s, k >>= 1)

        for (ll i = l >> s; i <= r >> s; ++i) if (d[i] != never) {

          apply(i<<1, d[i], k);

          apply(i<<1|1, d[i], k);

          d[i] = never;

        }

    }



    void modify(ll l, ll r, ll value) {  ///O(log(n))

        r++;

      if (value == never) return;

      push(l, l);

      push(r - 1, r - 1);

      bool cl = false, cr = false;

      ll k = 1;

      for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {

        if (cl) calc(l - 1, k);

        if (cr) calc(r, k);

        if (l&1) apply(l++, value, k), cl = true;

        if (r&1) apply(--r, value, k), cr = true;

      }

      for (--l; r > 0; l >>= 1, r >>= 1, k <<= 1) {

        if (cl) calc(l, k);

        if (cr && (!cl || l != r)) calc(r, k);

      }

    }





    ll query(ll l, ll r) {       ///O(log(n))

        r++;

      push(l, l);

      push(r - 1, r-1);

      ll res = 0;

      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {

        if (l&1) res += t[l++];

        if (r&1) res += t[--r];

      }

      return res;

    }

};



void ok_boss()

{

    ll n,k;

    cin >> n >> k;

    string str1,str2;



    cin >> str1;

    cin >> str2;



    segment_tree seg_tree(n);



    f(i,0,n)

        seg_tree.modify(i,i,str2[i]-'0');



    vpll queries(k);



    ll fir,sec;



    rev_f(i,k-1,-1)

    {

        cin >> fir >> sec;

        fir--,sec--;



        queries[i] = {fir,sec};

    }



    f(i,0,k)

    {

        fir = queries[i].fi;

        sec = queries[i].se;



        ll ok = (sec - fir)/2;



        ll get_it = seg_tree.query(fir,sec);



        if(get_it <= ok)

        {

            seg_tree.modify(fir,sec,0);

        }

        else if((sec - fir + 1 - get_it) <= ok)

        {

            seg_tree.modify(fir,sec,1);

        }

        else

        {

            ctn;

            return;

        }

    }



    f(i,0,n)

    {

        str2[i] = char(seg_tree.query(i,i) + '0');

    }



    if(str1==str2)

        cty;

    else

        ctn;



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