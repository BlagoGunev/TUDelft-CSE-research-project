#include<bits/stdc++.h>

using namespace std;



#ifdef ayushagarwal_11

#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;

#else

#define debug(x);

#endif

#define cod(x) cout<<#x<< <<x ;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;

bool revsort(ll a, ll b) {return a > b;}





int main(){

    fastio();

    int t;

    cin>>t;

    while(t--){

        int n,m=0;

        cin>>n;

        vector<ll> st(n);

        for(int i=0;i<n;i++){

            cin>>st[i];

        }

        sort(st.begin(),st.end());

        for(int i=0,j=n-1;i<2;i++,j--){

            m+=st[j]-st[i];

        }

        cout<<m<<'\n';

    }

}