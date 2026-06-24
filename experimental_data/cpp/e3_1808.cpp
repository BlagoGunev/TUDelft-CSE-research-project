// LUOGU_RID: 155272802
#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
#define isz(v) (int)(v.size())
using namespace std;

const int maxn=2005;
const int inf=0x3f3f3f3f;
int mod;

namespace Solve {
	struct mint {
		int val;
		mint():val(0) {}
		mint(ll tval) {
			if(-mod<=tval&&tval<2*mod) {
				if(tval>=mod) {
					tval-=mod;
				} 
				if(tval<0) {
					tval+=mod;
				}
			} else {
				tval%=mod;
				if(tval<0) {
					tval+=mod;
				}			
			}
			val=tval;
		}
		mint& operator += (const mint &b) {
			val=val+b.val>=mod?val+b.val-mod:val+b.val;
			return *this;
		}
		mint& operator -= (const mint &b) {
			val=val-b.val<0?val-b.val+mod:val-b.val;
			return *this;
		}
		mint& operator *= (const mint &b) {
			val=1ll*val*b.val>=mod?1ll*val*b.val%mod:val*b.val;
			return *this;
		}
		mint& operator /= (const mint &b) {
			*this*=b.inv();
			return *this;
		}
		friend mint operator + (const mint &a,const mint &b) {
			mint ans=a;
			ans+=b;
			return ans;
		}
		friend mint operator - (const mint &a,const mint &b) {
			mint ans=a;
			ans-=b;
			return ans;
		}
		friend mint operator * (const mint &a,const mint &b) {
			mint ans=a;
			ans*=b;
			return ans;
		}
		friend mint operator / (const mint &a,const mint &b) {
			mint ans=a;
			ans/=b;
			return ans;
		}
		friend bool operator ! (const mint &v) {
			return !v.val;
		}
		friend mint operator - (const mint &v) {
			return mod-v;
		}
		friend mint& operator ++ (mint &v) {
			v+=1;
			return v;
		}
		friend mint operator ++ (mint &v,signed _) {
			mint t=v;
			v+=1;
			return t;
		}
		friend mint& operator -- (mint &v) {
			v-=1; 
			return v;
		}
		friend mint operator -- (mint &v,signed _) {
			mint t=v;
			v-=1;
			return t;
		}
		friend bool operator < (const mint &a,const mint &b) {
			return a.val<b.val;
		}
		friend bool operator == (const mint &a,const mint &b) {
			return a.val==b.val;
		}
		friend bool operator != (const mint &a,const mint &b) {
			return a.val!=b.val;
		}
		friend istream& operator >> (istream &is,mint &x) {
			ll val;
			is>>val;
			x=mint(val); 
			return is;
		}
		friend ostream& operator << (ostream &os,const mint &x) {
			os<<x.val;
			return os;
		}
		mint qpow(ll y) const {
			mint x=*this,ans=1;
			if(y<0) {
				y=-y;
				x=inv();
			}
			while(y) {
				if(y&1) {
					ans*=x;
				} 
				x*=x;
				y>>=1;
			}
			return ans;
		}
		mint inv() const {
			// mod must be a prime
			return qpow(mod-2);
		}
		mint sqrt() {
			mint a=*this; 
			auto check=[&](mint x) {
				return x.qpow((mod-1)/2)==1;
			};
			static mt19937 rnd(73385);
			mint b=rnd()%mod;
			while(check(b*b-a)) {
				b=rnd()%mod;
			}
			static mint val=b*b-a;
			struct Complex {
				mint real,imag;
				Complex(mint treal=0,mint timag=0):real(treal),imag(timag) {}
				Complex operator * (const Complex &rhs) {
					return {real*rhs.real+imag*rhs.imag*val,real*rhs.imag+imag*rhs.real};
				}
				Complex& operator *= (const Complex &rhs) {
					return *this=*this*rhs;
				}
			};
			auto qpow=[&](Complex x,int y) {
				Complex ans={1};
				while(y) {
					if(y&1) {
						ans*=x;
					}
					x*=x;
					y>>=1;
				}
				return ans;
			};
			mint ans=qpow({b,1},(mod+1)/2).real;
			return min(ans,mod-ans);
		}
	};
	mint qpow(mint x,ll y) {
		return x.qpow(y);
	}
	mint inv(mint x) {
		return x.inv();
	}
	void clear() {
		
	}
	void main(int tid) {
		ll n;
		int k;
		cin>>n>>k>>mod;
		if(k%2==0) {
			mint v=(qpow(k-2,n)-qpow(-2,n))/k;
			cerr<<v<<"\n";
			mint ans=(qpow(k,n-1)+v)*(k/2);
			for(int s=0;s<=k-1;s+=2) {
				int x=s/2,y=(s+k)/2;
				if(1ll*x*(n%k)%k==s||(1ll*x*((n-1)%k)+y)%k==s) {
					ans+=(n&1?-1:1)*qpow(2,n-1);
				}
			}
			cout<<qpow(k,n)-ans<<"\n";
		} else {
			mint v=(qpow(k-1,n)-qpow(-1,n))/k;
			cerr<<v<<"\n";
			mint ans=v*k;
			for(int s=0;s<=k-1;s++) {
				int x=s&1?(s+k)/2:s/2;
				if(1ll*x*(n%k)%k==s) {
					ans+=n&1?-1:1;
				}
			}
			cout<<qpow(k,n)-ans<<"\n";
		}
	}
	void init() {
		
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	Solve::init();
	for(int t=1;t<=T;t++) {
		Solve::main(t);
		Solve::clear();
	}
#ifndef ONLINE_JUDGE
	cerr<<"Time: "<<(1.0*clock()/CLOCKS_PER_SEC)*1000<<"ms\n";
#endif
}