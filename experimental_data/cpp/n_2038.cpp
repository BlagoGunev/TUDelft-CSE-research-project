#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define repn(i,n) for(int i=0;i<(n);++i)
#define sizc(x) ((int)(x).size())
#define allc(x) (x).begin(),(x).end()
#define fir first
#define sec second

void solve(){
    string s;cin>>s;
    if(s[0]<s[2])s[1]='<';
    if(s[0]==s[2])s[1]='=';
    if(s[0]>s[2])s[1]='>';
    cout<<s<<'\n';
}

signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int T;cin>>T;
    while(T--)solve();
}