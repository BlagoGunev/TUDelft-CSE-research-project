#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define ll long long
using namespace std;
typedef vector<ll> vint;
typedef pair<int,int> pii;


vector<vint> jzksm(vector<vint> a, ll k) {
    int n = a.size();
    vector<vint> ans(n, vint(n));
    for(int i=0;i<n;i++) ans[0][i]=1;
    ll mod = 1e9 + 7;
    function<vector<vint>(vector<vint>&, vector<vint>&)>
        tt = [&](vector<vint>& a, vector<vint>& b) {
        vector<vint> an(n, vint(n));
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                for (int k = 0;k < n;k++) {
                    an[i][j] += (a[i][k] * b[k][j]) % mod;
                    an[i][j] %= mod;
                }
            }
        }
        return an;
    };
    while (k) {
        if (k & 1) {
            ans = tt(ans, a);
        }
        a = tt(a, a);
        k >>= 1;
    }
    return ans;
}


ll mod=1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m,n; cin>>m>>n;
	vint s(m),l(m);
	for(int i=0;i<m;i++) cin>>s[i];
	for(int i=0;i<m;i++) cin>>l[i];
	vint ans(m);
	ans[0]=1;
	auto sol=[&](ll t,ll i,ll j) {
	    return t*((s[i]*s[j]+s[i]*l[j]+l[i]*s[j])%mod)%mod;
	};
	for(int i=0;i<n;i++) {
	    vint nans(m);
	    for(int j=0;j<m;j++) {
	        for(int k=0;k<m;k++) {
	            nans[j]+=sol(ans[k],k,j);
	            nans[j]%=mod;
	        }
	    }
	    ans=nans;
	}
	ll an=0;
	for(int i=0;i<m;i++) an=(an+ans[i])%mod;
	cout<<an<<endl;
	return 0;
}