#include<bits/stdc++.h>



using namespace std;



#define ll long long

#define fr(m) for(int i=0; i<m; i++)

#define fro(m) for(int i=1; i<m; i++)

#define frj(m) for(int j=0; j<m; j++)

#define frr(n) for(int i=n; i>=0; i--)

#define pb push_back

#define pf push_front

#define orr ||

#define nl '\n'

#define nll cout<<'\n'

#define mod 1000000007

#define inf (1LL<<62)

#define inff (1<<30)

#define yes cout<<"YES"<<nl

#define no cout<<"NO"<<nl

#define ff first

#define ss second

#define all(v) v.begin(), v.end()

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)



int main()

{

    fastio;

    int t, cnt=1;

    cin>>t;

    while(t--){

        int n;

        cin>>n;

        ll r[n], c[n];

        pair<ll,ll>arr[n];

        fr(n) cin>>r[i], arr[i].ff=r[i];

        fr(n) cin>>c[i], arr[i].ss=c[i];

        sort(arr,arr+n);

        fr(n) r[i]=arr[i].ff, c[i]=arr[i].ss;

        ll prevx=1, prevy=1, ans=0;

        fr(n){

            if(prevx==r[i] && prevy==c[i]) continue;

            if((prevx+prevy)&1^1){

                if(abs(prevx-prevy)+1==abs(r[i]-c[i])){

                    prevx=r[i], prevy=c[i];

                    continue;

                }

                else if(abs(prevx-prevy)==abs(r[i]-c[i])){

                    ans+=abs(prevx-r[i]);

                    prevx=r[i], prevy=c[i];

                    continue;

                }

                else{

                    ll diffthen=abs(r[i]-c[i]), diffnow=abs(prevx-prevy);

                    ans+=abs(diffthen-diffnow)/2;

                    prevx=r[i], prevy=c[i];

                    continue;

                }

            }

            else{

                if(abs(prevx-prevy)==abs(r[i]-c[i])){

                    prevx=r[i], prevy=c[i];

                    continue;

                }

                else{

                    ll diffthen=abs(r[i]-c[i]), diffnow=abs(prevx-prevy);

                    ans+=(abs(diffthen-diffnow)+1)/2;

                    prevx=r[i], prevy=c[i];

                    continue;

                }

            }

        }

        cout<<ans<<nl;

    }

    return 0;

}