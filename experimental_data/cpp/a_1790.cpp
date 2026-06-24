#include<bits/stdc++.h>

using namespace std;

typedef long long ll ;

typedef long double ld ;

#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)

#define pb push_back

#define pi pair<ll,ll>

#define pll pair<ll,ll>

#define yes cout<<"YES"<<endl;

#define no cout<<"NO"<<endl;

#define flag cout<<"hi"<<endl;

#define fr(i,a,b) for(ll i = a;i < (ll)b;i++)

#define rfr(i,a,b) for(ll i = a;i > (ll)b;i--)

#define F first

#define S second

#define all(x) (x).begin(), (x).end()

#define alll(x) ((x).begin()+1), (x).end()

#define MOD mod

#define endl '\n'

const ll mod = 1e9+7 ;

void io()

{

    ios::sync_with_stdio(false) ;

    cin.tie(NULL) ;//freopen("grader.in.4","r",stdin) ;freopen("grader.out.4","w",stdout) ;

}

void dbg(vector<ll> tab)

{

    for(auto it : tab) cout<<it<<" ";

    cout<<endl;

}

void dbgg(pi p)

{

    cout<<p.F<<" "<<p.S<<endl;

}

void dbgpi(vector<pi> tab)

{

    for(auto it : tab) dbgg(it) ;

}

template<class T> bool ckmax(T& a, const T& b)

{

    return a < b ? a = b, 1 : 0;

}

template<class T> bool ckmin(T& a, const T& b)

{

    return a > b ? a = b, 1 : 0;

}

template<class T> void add(T& a, const T& b)

{

    a = a + b ;

    if(a>mod) a-= mod ;

}

void nop()

{

    cout<<-1<<endl;

    return;

}





void solve()

{

    string s = "314159265358979323846264338327" ;

    string t ; cin>>t ;

    int i = 0 ;

    while(i<t.size() && s[i]==t[i]) i++ ;

    cout<<i<<endl;

}

int main()

{

    io() ;

    ll tt = 1 ;

    cin>>tt ;

    while(tt--) solve() ;

    return 0 ;

}