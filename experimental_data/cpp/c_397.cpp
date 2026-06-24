#include <bits/stdc++.h>



#define mp make_pair



using namespace std;



typedef long long ll;

typedef long long ld;



int di[] = {1, 0, -1, 0};

int dj[] = {0, 1, 0, -1};



const ll mod = 1e9 + 7;

map<ll, ll> freq;

vector<ll> prime;

bitset<100010> bs;

ll fact[500000];

void g()

{

    fact[0] = 1;

    for (ll i=1;i<500000;i++)

        fact[i] = (i * fact[i-1]) % mod;

    bs.set();

    bs[1] = bs[0] = 0;

    for (ll i=2;i<=100000LL;i++)

    {

        if (bs[i])

        {

            prime.push_back(i);

            for (ll j=i*i;j<=100000LL;j+=i)

                bs[j] = 0;

        }

    }

}



void f(ll x)

{

    if (x<=100000 && bs[x])

    {

        freq[x]++;

        return;

    }



    for (auto i : prime)

    {

        if (x == 1 || i*i > x) break;

        while (x % i == 0)

            freq[i]++, x /= i;

    }

    if (x != 1)

        freq[x]++;

}



pair<ll, pair<ll, ll> > extendedEuclid(ll a, ll b) {

    if (a == 0) return make_pair(b, make_pair(0, 1));

    pair<ll, pair<ll, ll> > p;

    p = extendedEuclid(b % a, a);

    return make_pair(p.first, make_pair(p.second.second - p.second.first * (b / a), p.second.first));

}



ll modInverse(ll a, ll m) {

    return (extendedEuclid(a, m).second.first + m) % m;

}



ll c(ll i, ll j)

{

    if (i < j)

        return 0;

    ll x = fact[i];



    ll y = (fact[j] * fact[i-j]) % mod;



    return (x * modInverse(y , mod)) % mod ;

}





void mult(ll& i , ll j)

{

    i = ((i%mod) * (j%mod)) % mod;

}



int main(int argc, char *argv[])

{

    g();



    int n;

    scanf("%d",&n);

    int x;

    for (int i = 0; i < n; ++i) {

        scanf("%d", &x);

        f(x);

    }

    ll ans = 1;

    for (auto i : freq)

    {

        mult(ans, c(i.second + n - 1, i.second));

    }

    printf("%I64d\n", ans);

    return 0;

}