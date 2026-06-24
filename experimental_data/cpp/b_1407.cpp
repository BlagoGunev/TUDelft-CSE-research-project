#include<bits/stdc++.h>

#include<unordered_map>

#include<unordered_set>

using namespace std;

#define ll long long

#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2,fma")

#pragma GCC optimize("O2")

#define yes cout << "YES" << endl;

#define no cout << "NO" << endl;

#define minus1 cout<<-1<<endl;

const ll mod = 1e9+7;

const ll Mod = 998244353;

ll gcd(ll a,ll b){

    if(b==0)

    return a;

    return gcd(b,a%b);

}

ll lcm(ll a, ll b){

    return(a/gcd(a,b))*b;

}

void primeFactors(ll n,unordered_map<ll,ll>&m){

    while(n%2==0){

        m[2]++;

        n = n/2;

    }

    for(int i=3;i<=sqrt(n);i=i+2){

        while(n%i==0){

            m[i]++;

            n = n/i;

        }

    }

    if(n>2)

    m[n]++;

}

ll Factors(ll n){

    for (ll i=sqrt(n); i>=1; i--){

        if (n%i == 0){

            return i;

        }

    }

    return 1;

}

ll bits(ll n){

    ll total=0;

    while(n>0){

        if(n&1)

        total++;

        n=n>>1;

    }

    return total;

}

ll power(ll n){

    if(n==0)return 1;

    if(n&1){

    ll x=power((n-1)/2);

    return (((x%mod)*(x%mod))%mod)*2;

    }

    ll x=power(n/2);

    return ((x%mod)*(x%mod))%mod;

}

bool isvowel(char c){

    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')

    return true;

    return false;

}

void solve(){

    ll n;

    cin>>n;

    vector<ll>arr(n);

    for(ll i=0;i<n;i++)cin>>arr[i];

    vector<bool>temp(n,false);

    ll maximum=arr[0];ll maxindex=0;

    for(int i=0;i<n;i++){

        if(arr[i]>maximum){

            maximum=arr[i];

            maxindex=i;

        }

    }

    vector<ll>ans;

    ll Gcd=maximum;

    temp[maxindex]=true;

    ans.push_back(Gcd);

    for(int i=1;i<n;i++){

        ll maxgcd=0;ll maxindex=0;

        for(int j=0;j<n;j++){

            if(temp[j]==false){

                ll currgcd=gcd(arr[j],Gcd);

                if(currgcd>maxgcd){

                    maxgcd=currgcd;

                    maxindex=j;

                }

            }

        }

        Gcd=maxgcd;

        ans.push_back(arr[maxindex]);

        temp[maxindex]=true;

    }

    for(int i=0;i<ans.size();i++)

    cout<<ans[i]<<" ";

    cout<<"\n";

}

int main(){

    ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);

    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    #endif

	ll t=1;

	cin>>t;

	while(t--){

        solve();

	}

	return 0;

}