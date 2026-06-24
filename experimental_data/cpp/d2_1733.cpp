#include<bits/stdc++.h>

#define ll long long

#define int long long

#define rep(i,a,b) for(int i=a;i<b;i++)

#define rrep(i,a,b) for(int i=a;i>=b;i--)

#define repin rep(i,0,n)

#define di(a) int a;cin>>a;

#define precise(i) cout<<fixed<<setprecision(i)

#define vi vector<int>

#define si set<int>

#define mii map<int,int>

#define take(a,n) for(int j=0;j<n;j++) cin>>a[j];

#define give(a,n) for(int j=0;j<n;j++) cout<<a[j]<<' ';

#define vpii vector<pair<int,int>>

#define sis string s;

#define sin string s;cin>>s;

#define db double

#define be(x) x.begin(),x.end()

#define pii pair<int,int>

#define pb push_back

#define pob pop_back

#define ff first

#define ss second

#define lb lower_bound

#define ub upper_bound

#define bpc(x) __builtin_popcountll(x) 

#define btz(x) __builtin_ctz(x)

using namespace std;



const long long INF=1e18;

const long long M=1e9+7;

const long long MM=998244353;

  

int power( int N, int M){

    int power = N, sum = 1;

    if(N == 0) sum = 0;

    while(M > 0){if((M & 1) == 1){sum *= power;}

    power = power * power;M = M >> 1;}

    return sum;

}

 

void solve()

{

    di(n) di(x) di(y)

    string a,b;

    cin>>a>>b;

    vi v;

    repin{

        if(a[i]!=b[i]){v.pb(i);}

    }

    if(v.size()%2){cout<<"-1\n";return;}

    if(v.size()==0){cout<<"0\n";return;}

    if(x>y){

        int p = v.size()/2;

        // if(p%2==0){cout<<p*y<<"\n";return;}

        int f=0;

        rep(i,1,v.size()){

            if(v[i]==v[i-1]+1)f=1;

        }

        if(v.size()==2 && f==1){cout<<min(2*y,x)<<"\n";return;}

        cout<<p*y<<"\n";return;

    }

    vi dp(v.size()+1,INF);

    dp[v.size()]=0;

    rrep(i,v.size()-2,0){

        int sm=0;

        rep(j,i+1,v.size()){

            if((j-i-1)%2==0){

                dp[i]=min(dp[i],sm+min(x*v[j]-x*v[i],y)+dp[j+1]);

            }

            else{

                sm+=min(y,v[j]*x-v[j-1]*x);

            }

        }

        i--;

    }

    cout<<dp[0]<<"\n";

}



signed main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    #ifdef NCR

        init();

    #endif

    #ifdef SIEVE

        sieve();

    #endif

    di(t)

    while(t--)

        solve();

    return 0;

}