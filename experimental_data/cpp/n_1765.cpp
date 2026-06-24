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

    string s ;

    int k ;

    cin>>s>>k ;

    int n = s.size() ;

    vector<int> pos(11,-1) ;

    vector<vector<int>> nex(n+1 , vector<int>(11 , -1)) ;

    for(int i = n-1 ; i>=0 ; i--){

        pos[s[i]-'0'] = i ;

        for(int j = 0 ; j<10 ; j++){

            nex[i][j] = pos[j] ;

        }

    }

    string res = "" ;

    int i = 0 ;

    int kk = k ;

    for(int len = 0 ; len<n-kk ; len++){

        if(i>=n) break ;

        for(int j = 0 ; j<10 ; j++){

            if(i==0 && j==0) continue ;

            if(nex[i][j]==-1) continue ;

            if(nex[i][j] - i>k) continue ;

            k-= (nex[i][j] - i) ;

            res += char(j + '0') ;

            i = nex[i][j]+1 ;

            break ;

        }

    }

//    assert(k==0) ;

    cout<<res<<endl;

}

int main()

{

    io() ;

    ll tt = 1 ;

    cin>>tt ;

    while(tt--) solve() ;

    return 0 ;

}