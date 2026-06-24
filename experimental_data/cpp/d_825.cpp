/*********** [ scopeInfinity ] ******************/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;

#define forv(it,m) for (auto it = (m).begin(); it != (m).end(); ++it)
#define rep(i,n) for (int i=0;i<n;i++)
#define endl '\n' 
#define mp make_pair
#define pb(x) push_back((x))
#define what_is(x) cerr << #x << " is " << (x) << endl;

ll MOD = 1e9+7;
ll PRIME =  102838201;
ll INF = LLONG_MAX/4;

vector<string> &split(const std::string &s, char delim, vector<string> &e) {
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim))
        e.push_back(item);
    return e;
}


ll Pow(ll a ,ll b ,ll Mo){
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % Mo)
        if (b&1) ans = ans * a % Mo;
    return ans;
}


ll nCr(ll n,ll r) {
    static ll MAXF = 1e6;
    static std::vector<ll> fact(MAXF,1);
    for (int i = 1; i < MAXF; ++i)  fact[i]=(fact[i-1]*i)%MOD;
    MAXF=0;
    return (fact[n]*Pow((fact[r]*fact[n-r])%MOD,MOD-2,MOD))%MOD;
}

vector<int> Zfunc(string &s) {
    int n=s.length();
    vector<int> z(n,0);
    for(int i=1,l=0,r=0;i<n;i++) {
        if(i<=r) 
            z[i] = min(z[i-l],r-i+1);
        while(i+z[i]<n && s[i+z[i]]==s[z[i]])
            z[i]++;
        if(r<i+z[i]-1)
            l=i,r=i+z[i]-1;
    }
    return z;
}

ll solve() {
	
	
	return 0;
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);cin.tie(0);
	// cout<<fixed<<setprecision(1);
	
	string a,b;
	cin>>a>>b;
	std::vector<ll> v(256,0);
	int cq = 0;
	for (int i = 0; a[i]; ++i)
	{
		if(a[i]=='?')
			cq++;
		v[a[i]]++;
	}
	string more;
	int c =0;
	for (int i = 0; a[i]; ++i)
	{
		c=b[i%b.length()];
		if(v[c]>0)
			v[c]--;
		else more+=c;
	}
	int cn = 0;
	for (int i = 0; a[i]; ++i)
	{

		if(a[i]=='?') {
			assert(cn<more.length());
			a[i]=more[cn++];
		}
	}
	cout<<a;

	return 0;
}