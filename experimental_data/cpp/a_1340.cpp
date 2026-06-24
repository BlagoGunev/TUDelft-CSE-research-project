#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

//vector<ll> sieve(ll n){ vector<bool> isprime(n+1,true);vector<ll> prime;for (ll p = 2; p * p <= n; p++){if (isprime[p] == true){ for (ll i = p * p; i <= n; i += p) isprime[i] = false; } } for (ll p = 2; p <= n; p++) if (isprime[p]) prime.push_back(p); return prime;}



void solve(){

    ll n;cin>>n;

    ll i;vector<ll> v(n+1,0);

    for(i=1;i<=n;i++){

        cin>>v[i];

    }

    vector<ll> test(n+1,0);

    ll ref1,ref2,j;

    for(i=1;i<=n;i++){

        ref1=v[i];

        test[ref1]=1;

        for(j=i+1;j<=i+n-ref1;j++){

            ref2=(ref1+j-i);

            if(test[ref2]){

                i=j-1;

                break;

            }

            if(v[j]!=ref2){

                cout<<"No\n";return;

            }

            test[ref2]=1;

        }

        i=j-1;

    }

    cout<<"Yes\n";return;

}



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);cout.tie(NULL);

    ll t=1;

    cin>>t;

    while(t--){

        solve();

    }

    return 0;

}