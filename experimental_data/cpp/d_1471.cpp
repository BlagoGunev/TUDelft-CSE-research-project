#include<bits/stdc++.h>

using namespace std;

#define ll long long int

#define pb push_back

#define mp make_pair

#define ld long double

#define inp(arr,n) for(ll i = 0;i<n;i++){ cin>>arr[i]; }

#define out(arr,n) for(ll i = 0;i<n;i++){ cout<<arr[i]<<" "; };cout<<endl;

#define rep(a111,i,n) for(ll i = a111;i<n;i++)

#define del(vec,x) vec.erase(std::remove(vec.begin(), vec.end(), x), vec.end())

#define all(s) s.begin(),s.end()

#define endl '\n'

 

struct custom_hash {

    static uint64_t splitmix64(uint64_t x) {

        // http://xorshift.di.unimi.it/splitmix64.c

        x += 0x9e3779b97f4a7c15;

        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;

        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;

        return x ^ (x >> 31);

    }

 

    size_t operator()(uint64_t x) const {

        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

        return splitmix64(x + FIXED_RANDOM);

    }

};

#pragma GCC target ("avx2")

#pragma GCC optimization ("O3")

#pragma GCC optimization ("unroll-loops") 

ll mod =  3;

ll power(ll a,ll n)

{

    ll prod = 1;

    rep(0,i,n)

    {

        prod = prod*a;

    }

    return prod;

}

ll bexp(ll a,ll n)

{

    ll prod = 1;

    while(n>0)

    {

        if(n%2 == 1)

        {

            prod = (prod*a)%mod;

        }

        a = (a*a)%mod;

        n = n/2;

    }

    return prod;

}

set<ll>gg;

ll a[200001];

void delete1(ll n)

{

    auto it = gg.lower_bound(n);

    // it--;

    while(it!=gg.end() && a[(*it)] >= a[n])

    {

        it = gg.erase(it);

    }

    gg.insert(n);

}

ll sq[1000001] = {0};

ll spf[1000001] = {0};

int main()

{

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    ll t = 1;

    cin>>t;

    // int flag = 0;

    // ll i1 = 0;

    // cout<<t<<endl;

    rep(1,i,1e3 + 1)

    {

        sq[i*i] = 1;

    }

    // spf[2] = 2;

    spf[1] = 1;

    rep(2,i,1000001)

    {

        if(spf[i] == 0)

        {

            for(ll j = i;j<1000001;j+=i)

            {

                spf[j] = i;

            }

        }

    }

    while(t--)

    {

        ll n;

        cin>>n;

        ll a[n+1];

        inp(a,n);

        ll cnt1 = 0;

        unordered_map<ll,ll,custom_hash>gg;

        rep(0,i,n)

        {

            if(sq[a[i]])

            {

                cnt1++;

            }

            else

            {

                ll x = spf[a[i]];

                ll cnt = 1;

                ll prod = 1;

                while(spf[a[i]]!=1)

                {

                    a[i] = a[i]/spf[a[i]];

                    if(spf[a[i]] != x)

                    {

                        if(cnt%2 == 1)

                        {

                            prod = prod*x;

                        }

                        cnt = 1;

                    }

                    else

                    {

                        cnt++;

                    }

                    x = spf[a[i]];

                }

                gg[prod]++;

            }

        }

        ll max1 = 0;

        ll cnt2 = cnt1;

        ll max2 = 0;

        for(auto it: gg)

        {

            if(it.second%2 == 0)

            {

                cnt1 += it.second;

            }

            else

            {

                max1 = max(max1,it.second);

            }

            max2 = max(max2,it.second);

        }

        max1 = max(max1,cnt1);

        ll q;

        cin>>q;

        rep(0,i,q)

        {

            ll x;

            cin>>x;

            if(x == 0)

            {

                cout<<max(cnt2,max2)<<endl;

            }

            else

            {

                cout<<max1<<endl;

            }

        }





    }

}