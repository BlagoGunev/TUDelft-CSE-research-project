#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

#pragma GCC optimize("O3")
//#pragma GCC poizon
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define el '\n'
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define vd vector<double>
#define vl vector<ll>
#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define mi1 cout<<"-1\n"
#define itn int
#define iii tuple<int, int, int>
#define vt vector<iii>
#define vtl vector<tuple<ll,ll,ll>>
#define vp vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define vs vector<string>
#define sz size()
#define re return
#define all(x) x.begin(),x.end()
#define fro for
#define pu push
#define right gfijosdjf
#define left fgisahjfd
#define asn ans
#define con continue
#define nas ans
#define mk make_pair
#define mkt make_tuple
#define ii pair<int, int>
#define ld long double
#define y1 dsjkulfbgds
#define ook order_of_key
#define fbo find_by_order
#define iil pair<ll, ll>
#define int long long

typedef long long ll;
typedef unsigned long long ull;
const ll mod=100000000;
const ll mod2=998244353;
//const ll mod3=(1LL<<64);
const ll maxll=4*1e18+7;
const ll oo=1844674407370960000;
const double PI=3.1415926535;

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;

long double rastq2(long double x1, long double y1, long double x2, long double y2)
{
  long double a1=(x1-x2)*(x1-x2);
  long double a2=(y1-y2)*(y1-y2);
  long double a3=a1+a2;
  long double a4=sqrt(a3);

  re a4;
}

 ld rastq(ld x1,  ld y1,  ld x2,  ld y2)
{
   ld a1=(x1-x2)*(x1-x2);
   ld a2=(y1-y2)*(y1-y2);
   ld a3=a1+a2;
   ld a4=sqrt(a3);

  re a4;
}

ll rastm(ll x1, ll y1, ll x2, ll y2)
{
  re abs(x1-x2)+abs(y1-y2);
}

double angle(int x1, int y1, int x2, int y2)
{
    return acos( (x1*x2+y1*y2)/(sqrt((double)x1*x1+y1*y1)*sqrt((double)x2*x2+y2*y2)) );
}

inline int area(ii a, ii b, ii c)
{
	re (b.F-a.F) * (c.S-a.S) - (b.S-a.S) * (c.F-a.F);
}

inline bool intersect_1(int a, int b, int c, int d)
{
	if(a>b) swap(a, b);
	if(c>d) swap(c, d);

	re max(a,c) <= min(b,d);
}

bool peres(ii a, ii b, ii c, ii d)
{
	re intersect_1 (a.F, b.F, c.F, d.F) && intersect_1 (a.S, b.S, c.S, d.S) && (area(a,b,c) * area(a,b,d) <= 0) && (area(c,d,a) * area(c,d,b) <= 0);
}

ll lcm(ll x, ll y)
{
  ll gcd=__gcd(x, y);
  re (x*y)/gcd;
}

int n, x;

void solve()
{
  cin>>n>>x; vi a; a.pb(0);
  for(int i=0; i<n; i++)
  {
    int y; cin>>y;
    a.pb(y);
  }

  int ans=0;
  a.pb(x);
  for(int i=0; i<a.sz-1; i++) ans=max(ans, a[i+1]-a[i]);

  ans=max(ans, (a[a.sz-1]-a[a.sz-2])*2);

  cout<<ans<<el;
}

int32_t main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  //srand(time(0));

  //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

  int q=1;
  cin>>q;
  while(q--) solve();

  re 0;
}