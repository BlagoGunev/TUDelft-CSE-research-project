#include <bits/stdc++.h>

#define     fast                   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define     endl                   '\n'

#define     gi(x)                  while(cin>>x)

#define     gi2(x,y)               while(cin>>x>>y)

#define     gi3(x,y,z)             while(cin>>x>>y>>z)

#define     fr(i,n)                for(int i=0;i<n;i++)

#define     fr1(i,n)               for(int i=1;i<=n;i++)

#define     ll                     long long

#define     mk                     make_pair

#define     ull                    unsigned long long

#define     pb(x)                  push_back(x)

#define     loop(i,a,b)            for(int i=a;i<b;++i)

#define     rloop(i,a,b)           for(int i=a-1;i>=b;i--)

#define     sort_arr(a,n)          sort(a,a+n)

#define     vsort_arr(a)           sort(a,a+n,greater<int>())

#define     sort_vec(v)            sort(v.begin(), v.end());

#define     vsort_vec(v)           sort(v.begin(), v.end(),greater<int>());

#define     exit                   return 0

#define     all(v)                 v.begin(),v.end()

#define     mem(a,v)               memset(a,v,sizeof(a))

#define     max2(a,b)              max(a,b)

#define     max3(a,b,c)            max(a,max(b,c))

#define     min2(a,b)              min(a,b)

#define     min3(a,b,c)            min(a,min(b,c))

#define     sz(x)                  int(x.size())

#define     py                     cout<<"yes\n"

#define     pn                     cout<<"no\n"

#define     Py                     cout<<"Yes\n"

#define     Pn                     cout<<"No\n"

#define     PY                     cout<<"YES\n"

#define     PN                     cout<<"NO\n"

const double pi = 3.141592653;

using namespace std;



bool isPrime(long long n)

{

    // Corner case

    if (n <= 1)

        return 0;



    // Check from 2 to sqrt(n)

    for (long long i = 2; i <= sqrt(n); i++)

        if (n % i == 0)

            return false;



    return true;

}

long long fact(int n){

        long long ans = 1;

for(int i = 2 ; i <= n ; i++)

         ans *= i ;

        return ans;

}

/*

int factorial(int n) {

  if(n > 1)

    return n * factorial(n - 1);

  else

    return 1;

}

*/

//ll gcd(int a, int b) {

//    while (b) {

//        long long r = a % b;

//        a = b;

//        b = r;

//    }

//    return a;

//}

long long lcm(long long a, long long b){

    return (a / gcd(a, b)) * b;

    }

int fib(int n)

{

    if (n <= 1)

        return n;

    return fib(n-1) + fib(n-2);

}

bool check_perfect_square(long long n){

    double sqrt_n = sqrt(n);

    if(sqrt_n == int(sqrt_n))

        return true;

    else

        return false;

}

bool check_pilandrom(string val)

{

    fr(i,val.size())

    if(val[i]!=val[val.size()-1-i])

        return 0;

    return 1;

}

bool ispalindrome(string s)

{

    string t=s;

    reverse(s.begin(),s.end());

    for(int i=0;i<s.size();i++)

        if(s[i]!=t[i])

            return false;

    return true;

}





ll binary_search(ll n){

    ll l=0,r=1e10;

    while (l<r){

        ll mid =(r+l)/2;

        ll ans=mid*(mid+1)/2;

        if(ans>=n)r=mid;

        else l = mid+1;



    }

    return l;

}

void solve(){



}

int main(){

// la ana mesh 3la mauram   ✘︵✘

    fast

    int ts;

    cin >> ts;

    while(ts--)

    {

        string val;

        cin>>val;

        ll ans;

        if(val[0] > val[1]) ans = (val[0] - 'a' ) * 25 + ( val[1] - 'a' ) + 1;

        else ans = (val[0] - 'a' ) * 25 + ( val[1] - 'a' ) ;

        cout<<ans<<endl;

    }

}