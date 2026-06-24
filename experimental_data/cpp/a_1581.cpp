#include<bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ll long long

#define all(x) x.begin(), x.end()

#define endl '\n'

#define T  ll t ; cin >> t; while(t--)

//const int W=1e5+1;

//ll fr[];

const ll mod=1e9+7;

//int fp(int b,int p)

//{

//    if(p==0)return 1;

//    ll x=fp(b,p>>1);

//    x*=x;

//    x%=mod;

//    if(p&1)x*=b;

//    return x%mod;

//}

//const int N=1e7;

//int prime[N];

//void sieve(){

//    for (ll i = 2; i<N ; ++i)

//    {

//       if(prime[i])

//           continue;

//       for (ll j = i; j < N; j+=i)

//       {

//           prime[j]=i;

//       }

//    }

//}

int main() {

    fast

    T {

        int n;

        cin>>n;

        ll ans=1;

        for (int i = 3; i <= n*2; ++i) 

        {

            ans%=mod;

            ans*=i;

            ans%=mod;

        }

        cout<<ans<<endl;

    }

}

//830455698

//890219710

//822421174