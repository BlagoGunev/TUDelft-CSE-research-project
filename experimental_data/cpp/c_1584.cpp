#pragma GCC optimize("Ofast")

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#pragma GCC optimize("unroll-loops")



#include<bits/stdc++.h>

using namespace std;

 

#define endl '\n'

#define debug(x) cout << x << endl;

#define ll long long

#define mod 1000000007

#define pb push_back

#define fs first

#define sec second 

#define print(x) cout << x << endl

#define prec(n) fixed<<setprecision(n)

#define all(x) (x).begin(), (x).end()



long long gcd(long long  a, long long  b)

{

  if (b == 0)

    return a;

  return gcd(b, a % b);

}

 

long long lcm(ll a, ll b)

{

    return (a / gcd(a, b)) * b;

}

 

bool isPrime(int n) {

    for (int i = 2; i*i <= n; ++i) {

        if(n%i == 0) return false;

    }

    return true;

}

 

ll summ(ll n)

{

    if(n==0)return 0;

    else return(n%10 + summ(n/10));

}

 

string DecimalToBinary(int num)

{

    string str;

      while(num){

      if(num & 1) // 1

        str+='1';

      else // 0YES

 

        str+='0';

      num>>=1; // Right Shift by 1 

    }

 

    return str;

}

 

 



int main()

{

    #ifndef ONLINE_JUDGE

    freopen("IN.txt","r",stdin);

    freopen("per.txt","w",stdout);

    #endif 



    ios_base::sync_with_stdio(false);

    cin.tie(NULL); 



    ll t;

    cin >> t;

    while(t--)

    {

        ll n;

        cin >> n;

        ll a[n];

        for(int i=0;i<n;i++)

        {

            cin >> a[i];

        }

        ll b[n];

        for(int i=0;i<n;i++)

        {

            cin >> b[i];

        }

        sort(a,a+n);

        sort(b,b+n);

        int f=0;

        for(int i=0;i<n;i++)

        {

           if(a[i]==b[i] || a[i]+1==b[i])

            {

                continue;

            }

            else f=-1;

        }



        if(f!=-1)

        {

            cout << "YES" << endl;

        }

        else cout << "no" << endl;







    }

}