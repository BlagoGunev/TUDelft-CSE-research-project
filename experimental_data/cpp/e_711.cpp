#include <bits/stdc++.h>



using namespace std;





#define fr first

#define sc second

#define pb push_back

#define ins insert

#define input freopen("input.txt","r",stdin)

#define output freopen("output.txt","w",stdout)

#define mp make_pair

#define fast_io ios_base::sync_with_stdio(0);

#define forn() for(int i=0;i<n;i++)

#define fori(n) for(ll i=0;i<(ll)n;i++)

#define forj(n) for(ll j=0;j<(ll)n;j++)





typedef long long ll;

typedef unsigned long long ull;

typedef vector<int> vi;

typedef pair<int,int> pii;



const int inf = 1e9;

const double eps = 1e-4;

const int maxn = 1e5 + 55;

ll base = 1e6+3;



string itos(int x){

    string ans = "";

    while(x > 0){

        ans +=((x%10) + '0');

        x/=10;

    }

    reverse(ans.begin(), ans.end());

    return ans;

}



ll stoi(string str){

    ll ans = 0;

    ll k = 1;

    for(int i = str.length()-1; i >= 0; i--){

        ans+=(str[i]-'0')*k;

        k*=10;

    }

    return ans;

}



ll power(ll base1, ll exp)

{

    ll ans = 1;

    while(exp)

    {

        if(exp&1) ans = (ans*base1)%base;

        base1 = (base1*base1)%base;

        exp>>=1;

    }

    return ans;

}



int main()

{

    //input;

    //fast_io;

    ll n, k;

    cin >> n >> k;

    if(n <= 63 && k > (1LL<<n))

    {

        cout << 1 << " " << 1;

        return 0;

    }

    ll v2 = 0;

    int digits = __builtin_popcountll(k - 1);

    v2 = k - 1 - digits;

    ll ntmp = n % (base - 1);

    if(ntmp < 0)

        ntmp += (base - 1);

    ll ktmp = k % (base - 1);

    if(ktmp < 0) 

        ktmp += (base - 1);

    ll v2tmp = v2 % (base - 1);

    if(v2tmp < 0) 

        v2tmp += (base - 1);

    ll exponent = ntmp*(ktmp - 1) - v2tmp;

    exponent %= (base - 1);

    if(exponent < 0) 

        exponent += base - 1;

    ll denom = power(2, exponent);

    ll numpart = 0;

    if(k - 1 >= base)

        numpart = 0;

    else{

        ll prod = 1;

        ll ntmp2 = power(2, ntmp);

        prod = power(2, v2tmp);

        prod = power(prod, base - 2);

        if(prod < 0) prod += base;

        for(ll y = 1; y < k; y++)

        {

            prod = (prod * (ntmp2 - y))%base;

        }

        numpart = prod;

    }

    ll num = (denom - numpart)%base;

    num %= base; denom %= base;

    if(num < 0) num += base;

    if(denom < 0) denom += base;

    cout << num << " " << denom;

    return 0;

}