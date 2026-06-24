#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <assert.h>
#include <map>
#include <set>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <time.h>
#include <string.h>
#include <queue>
#include <complex>
#include <stack>
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef complex<double> base;
ll mod=(119 << 23) + 1;
double eps=1e-9;
ll exp(ll x,ll y){if(y<0) return 0; ll ret=1;for(;y;y>>=1,x=(x*x)%mod){if(y&1)ret=(ret*x)%mod;}return ret;}
ll pexp(ll x, ll y){if(y<0) return 0; ll ret=1; for(;y;y>>=1,x=(x*x)){if(y&1)ret=(ret*x);}return ret;}
ll gcd(ll x,ll y){if(!x||!y) return x+y; return x%y==0?y:gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
ll bsum(ll u,ll b){ll ret=0;if(u<b)return u;while(u){ret+=u%b;u/=b;}return ret;}
ll prival(ll u,ll p){ll cn=0;while(u%p==0){cn++;u=u/p;}return cn;}
ll minv(ll a,ll b){return 1<a?b-minv(b%a,a)*b/a:1;}
ll extm(ll a,ll b){ll ret=0;while(a!=0){if(a%2==1){ret+=b;ret%=mod;}a>>=1;b=(2*b)%mod;}return ret;}   
ll eaphi(ll x){ll t=x,ret=x,i;for(i=2;i*i<=x;i++){if(t%i==0){ret-=ret/i;while(t%i==0) t/=i;}}if(t!=1) ret-=ret/t;return ret;}
ll eadivc(ll x){ll ret=0;ll i;for(i=1;i*i<=x;i++){if(x%i==0 && i*i!=x) ret+=2;if(x%i==0 && i*i==x) ret+=1;}return ret;}
bool isprime(ll x){if(x<=1) return false; for(ll i=2;i*i<=x;i++){if(x%i==0){return false;}}return true;}
typedef vector<ll> vl;

// thanks benq
int get(int s) {
    return s > 1 ? 32 - __builtin_clz(s - 1) : 0;
}

namespace NTT {
    const ll mod = (119 << 23) + 1, root = 3; // = 998244353
    // For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
    // (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.
        
    ll modpow(ll b, ll p) { return !p?1:modpow(b*b%mod,p/2)*(p&1?b:1)%mod; }
    
    ll inv (ll b) { return modpow(b,mod-2); }
    
    vl ntt(vl& a) { 
        int n = a.size(), x = get(n); 
        vl res, RES(n), roots(n);
        roots[0] = 1, roots[1] = modpow(root,(mod-1)/n);
        FOR(i,2,n) roots[i] = roots[i-1]*roots[1] % mod;
        
        res = a;
        FOR(i,1,x+1) {
            int inc = n>>i;
            F0R(j,inc) for (int k = 0; k < n; k += inc) {
                int t = 2*k%n+j;
                RES[k+j] = (res[t]+roots[k]*res[t+inc]) % mod;
            }
            swap(res,RES);
        }
        
        return res;
    }
    
    vl ntt_rev(vl& a) {
        vl res = ntt(a);
        ll in = inv(a.size());
        F0R(i,sz(res)) res[i] = res[i]*in % mod;
        reverse(res.begin() + 1, res.end());
        return res;
    }
    
    vl brute(vl& a, vl& b) {
        vl c(sz(a)+sz(b)-1);
        F0R(i,sz(a)) F0R(j,sz(b)) c[i+j] = (c[i+j]+a[i]*b[j])%mod;
        return c;
    }
    
    vl conv(vl a, vl b) {
        int s = sz(a)+sz(b)-1, L = get(s), n = 1<<L;
        if (s <= 0) return {};
        if (s <= 200) return brute(a,b);
        
        a.resize(n); a = ntt(a);
        b.resize(n); b = ntt(b);
        
        F0R(i,n) a[i] = a[i]*b[i] % mod;
        a = ntt_rev(a);
        
        a.resize(s);
        return a;
    }
}

vl Fin, stf; ll n, l, r, ans, ansp;
ll fac[222222];
ll invfac[222222];

ll ncr(ll u, ll v)
{
	if(u<v || u<0 || v<0) return 0;
	ll ret=fac[u];
	ret=(ret*invfac[u-v])%mod;
	ret=(ret*invfac[v])%mod;
	return ret;
}

vl getprd(int l, int r)
{
	vl ret; ret.clear();
	//cout<<l<<" "<<r<<endl;
	if(l>r) 
	{
		ret.push_back(1);
		return ret;
	}
	if(l==r)
	{
		ret.push_back(mod-l); ret.push_back(1);
		return ret;
	}
	return NTT::conv(getprd(l,(l+r)/2),getprd((l+r)/2+1,r));
}

int main(void)
{
	ll i, j; cin>>n>>l>>r;
	if(l==0 || r==0 || l+r-2>n-1) 
	{
		cout<<0; return 0;
	}
	if(n==1)
	{
		cout<<1; return 0;
	}
    Fin = getprd(0,n-2);
	ans=Fin[l+r-2];
	if((n-1-(l+r-2))%2==1) ans=mod-ans;
	//cout<<ans<<endl;
	fac[0]=1; invfac[0]=1;
	for(i=1 ; i<=2*n ; i++)
	{
		fac[i]=(i*fac[i-1])%mod;
		invfac[i]=exp(fac[i],mod-2);
	}
	ansp=ncr(l+r-2,l-1);
	cout<<(ans*ansp)%mod;
	return 0;
}