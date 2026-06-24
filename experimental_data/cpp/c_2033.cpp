#include<bits/stdc++.h>             //Written by ThiDaiLoc
using namespace std;  
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> trp;
typedef vector<ll> vi;
typedef vector<pll> vp;

#define fu(i,a,b)   for(ll i=a;i<=b;i++)
#define f1(i,n)     for(ll i=1;i<=n;i++)
#define fs(i,s)     for(ll i=0;i+1<=s.length();i++)
#define fd(i,b,a)   for(ll i=b;i>=a;i--)
#define fuv(i,a)    for(ll i=0;i<a.size();i++)
#define fdv(i,a)    for(ll i=(ll)a.size()-1;i>=0;i--)
#define ms(a,x)     memset(a, x, sizeof a)
#define prec(n)     fixed<<setprecision(n)
#define uni(a)      (a).erase(unique(all(a)), (a).end())
#define pb(i)       push_back(i)
#define popb()      pop_back()
#define sc(a)       cin>>a
#define sc2(a,b)    cin>>a>>b
#define pr(a)       cout<<a<<endl
#define pr2(a,b)    cout<<a<<" "<<b<<endl
#define rpr(a)      return cout<<a<<endl,0
#define prY         cout<<"YES"<<endl
#define prN         cout<<"NO"<<endl
#define bit(n,i)    (((n)>>(i))&1)
#define lowb(a,n,x) lower_bound(a,a+n,x) -a
#define lowb2(a,x)  lower_bound(all(a),x) -a.begin()
#define all(x)      (x).begin(), (x).end()
#define sz(a)       (ll)a.size()
#define le(s)       (ll)s.length()      
#define ast(x,a,b)  assert(x>=a and x<=b)               
#define re          return  
#define mp(a,b)     make_pair(a,b)
#define se          second
#define fi          first 
#define debug(x)    cerr << #x << " = " << x << endl
#define INPUT       freopen("locin.txt", "r", stdin)
#define OUTPUT      freopen("locout.txt", "w", stdout)
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline ll mnz(ll& a,ll b){return a=(a>b?b:a);}
inline ll mxz(ll& a,ll b){return a=(a<b?b:a);}
inline string toString(ll n) {stringstream ss; ss << n;return ss.str();}
double const eps = 1e-6;
ll const Base=1e9+7,oo=2e18,MAXN=1e6;


ll A[MAXN+5];

ll Solves(){
    
    ll n,m,k,cnt=0,ans=0,x,y,q,c,sum=0,v,t;
    // PROCESS IN HERE

	sc(n);
	f1(i,n)sc(A[i]);
	
	f1(i,n){
		ll l=i;
		ll r=n-i+1;
		if(l>r)break;
		if(l==r-1 and A[l]==A[r])ans++;
		if(i==1)continue;
		if(l==r){
			ans+=(A[l-1]==A[l]);
			ans+=(A[r+1]==A[r]);
		}
		else{
			
			if(A[l]==A[r]){
				if(A[l-1]==A[r+1] and A[l-1]==A[l])ans+=2;
				else if(A[l]==A[l-1] or A[l]==A[r+1])ans++;
			}
			else{
				if(A[l-1]==A[r+1] and (A[l-1]==A[l] or A[l-1]==A[r])){
					ans++;
				}
			}
		}
//		debug(ans);
	} 
	pr(ans);


    re 0;
    // Hack it if you can :)
}

int main(){
    //INPUT;
    if(fopen("locin.txt", "r"))INPUT;
    ll JUDGE_ONLINE = 1;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll test=1;
  sc(test);
    fu(T,1,test){
//      cout<<"Case #"<<T<<": ";
        Solves();
    }
    if (!JUDGE_ONLINE) cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";  
        
}