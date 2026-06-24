#include<bits/stdc++.h>

#include<unordered_map>

using namespace std;

#define ll long long 

const ll INF_MUL=1e13;                                                             

const ll INF_ADD=1e18;

#define rep(i,a,b) for (ll i=a; i<b; i++)

#define setBits(x) builtin popcount(x) 

#define pb push_back               

#define mp make_pair           

#define f first                                       

#define s second                                        

#define pll pair<ll,ll>    

#define vl vector<ll>   

#define vvl vector<vector<ll> >

#define vvvl vector<vector<vector<ll> > > 

#define all(v) v.begin(),v.end()

#ifndef ONLINE_JUDGE    

#define debug(x) cerr<<#x<<" "; _print(x); cerr<<nline;

#else

#define debug(x);      

#endif                 

void _print(ll x){cerr<<x;}     

void _print(string x){cerr<<x;}  

const ll MOD=1e9+7;        

const ll MAX=500500;

const int N = 1e5+2;



void solve(){

        ll n , q;

        cin>>n>>q;

        vl v(n);

        

        rep(i,0,n){

            cin>>v[i];

        }

        vl sum(n);

        sum[0] = v[0];

        vl x(n);

        x[0]=v[0];

        rep(i,1,n){

            sum[i] = sum[i-1]+v[i];

            x[i] = (x[i-1]^v[i]);

            

        }

        ll f = sum[n-1] - x[n-1];



        //cout<<sum[n-1]<<" "<<x[n-1]<<" "<<f<<" ";

        ll l , r;

        cin>>l>>r;

        l--,r--;

        int i = 0 , j = 0 , y , z , len=n+1;

        while(i<n && j<n && i<=j){

            ll s = sum[j];

            if(i>0)s-=sum[i-1];

            ll xr = x[j];

            if(i>0)xr^=x[i-1];

            if(s-xr<f){

                j++;

            }

            else{

                if(j-i+1<len){

                    len = j-i+1;

                    y = i+1 , z = j+1;

                }

                i++;

            }

        }

        cout<<y<<" "<<z<<endl;





}

int main()                                                                            

{ 

    ios_base::sync_with_stdio(false);                                    

    cin.tie(NULL);                         

    cout.tie(NULL);                  

    ll test_cases;                   

    cin>>test_cases; 

    while(test_cases--){

        solve();

    }

    //cout<<(21^32^10);

return 0;

}