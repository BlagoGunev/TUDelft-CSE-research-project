#include <iostream>

#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout<<#x<<" :: "<<x<<endl;

#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;

#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;

#define boost ios::sync_with_stdio(0); cin.tie(0) 

#define fi first

#define se second

#define pb(x) push_back(x)

#define mp(x,y) make_pair(x,y)

typedef long long ll;

typedef long double ld;

typedef pair<ll, ll> pii;

typedef unsigned long long ull;

#define YES cout<<"YES"<<"\n";

#define NO cout<<"NO"<<"\n";



/***************************************************************************/

ll d;

long long power(long long a,long long b,ll flag=0){

    if(b==0){

        return 1;

    }

    long long  z;

    if(flag){

        z= power(((a%d)*(a%d))%d,b>>1,flag);

    }

    else{

        z = power((a*a),b>>1,flag);

    }

    if(b&1){

        if(flag){

            z= (z*(a%d))%d;

        }

        else

            z=(z*a);

    }

    if(flag)

    return z%d;

    return z;

}

int main(){

    boost; 

    ll t=0;cin>>t;

    for(ll test=1;test<=t;test++){

        ll a,b;

        cin>>a>>b>>d;

        ll curr_a=a, curr_b=b, curr_d=d;

        ll flag=1;

        ll cnt=0;

        for(;;d/=2,a/=2,b/=2,cnt++){

            if(d%2) break;

            if(a%2||b%2){

                flag=0;

                break;

            }

        }

        if(!flag){

            cout<<"-1\n";

            continue;

        }

        ll taken_bits= 30- cnt;

        ll INV= (d+1)/2;

        INV= power(INV,taken_bits,1);

        ll x= (INV*(1-power(2,taken_bits,1)))%d;

        x+=d;

        x%=d;

        ll ans= power(2,taken_bits+cnt)*x+ power(2,taken_bits+cnt)-power(2,cnt);

        cout<<ans<<"\n";

    }

    return 0;

}