#include <iostream>

#include <string>

#include <math.h>

#include <stack>

#include <set>

#include <ctime>

#include <vector>

#include <string.h>

#include <queue>

#include <sstream>

#include <algorithm>

#include <bitset>

#include <random>

#include <chrono>

#include <map>

#include <iomanip>

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)

#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)

#define mem(a,b) memset(a,b,sizeof(a));

#define lowbit(a) ((a)&-(a))

#define lbit(a) (__builtin_ffsll(a))

#define IOS   ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

#define ubit(a) (64-__builtin_clzll(a))

//lowbit -> 10100??100(???) lbit ->?????1???(???)  ubit ->?????1???

//__builtin_popcountll(x)?????1???

using namespace std;

const int N=1e6+5;

const int long long inf=0x3f3f3f3f3f3f3f3f;

#define xs(a) cout<<setiosflags(ios::fixed)<<setprecision(9);

const long long int mod=1e9+7;

#define ull unsigned long long

#define ll long long

typedef pair<ll,ll> pll;

ll C(ll x_,ll y_){x_=x_-y_+1;ll ans=1;FOR(i,1,y_){ans*=x_++;ans/=i;}return ans;}

//ll PP[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

/*-----------------------------------------------------------------------------------------------*/

ll a[N],vis[N];

vector<vector<ll>>G;//G.resize(n, vector<ll>(m, 0)); ????n?m????



ll sum[N];

ll n;

void add(ll x,ll y){for(;x<=n+5;x+=(-x&x)){sum[x]+=y;}}

ll ask(ll x,ll y=0){for(;x;x-=(-x&x)){y+=sum[x];}return y;}

ll l[N],r[N];

ll f[N];

signed main(){IOS

		ll n,k;cin>>n>>k;

		FOR(i,1,n)cin>>l[i]>>r[i]>>a[i];

		ROF(i,n,1){

			ll nd = a[i] + (i < n && r[i] == l[i + 1] ? f[i + 1] : 0);

			if((r[i]-l[i]+1)*k<nd){

				cout<<-1<<endl;

				return 0;

			}

			f[i]=max(0ll,nd-(r[i]-l[i])*k);

		}

		ll ans=0,tp=k;

		FOR(i,1,n){

			if(tp<f[i])ans+=tp,tp=k;

			ans+=a[i];

			tp=(tp-a[i])%k;

			if(tp<0)tp+=k;

		}

		cout<<ans<<endl;

	return 0;

}