#include<bits/stdc++.h>



#define ll long long



#define F first



#define S second



using namespace std;

ll x,y;

set<ll>s;

void _clear()

{

    s.clear();

}

bool isPrime(ll n)

{

    // Check if n=1 or n=0

    if (n <= 1)

        return false;

    // Check if n=2 or n=3

    if (n == 2 || n == 3)

        return true;

    // Check whether n is divisible by 2 or 3

    if (n % 2 == 0 || n % 3 == 0)

        return false;

    // Check from 5 to square root of n

    // Iterate i by (i+6)

    for (ll i = 5; i * i <= n; i = i + 6)

        if (n % i == 0 || n % (i + 2) == 0)

            return false;



    return true;

}

void primeFactors(ll n)

{

    // Print the number of 2s that divide n

    while (n % 2 == 0)

    {

        s.insert(2);

        n = n/2;

    }



    // n must be odd at this point. So we can skip

    // one element (Note i = i +2)

    for (ll i = 3; i * i<= n; i = i + 2)

    {

        // While i divides n, print i and divide n

        while (n % i == 0)

        {

            s.insert(i);

            n = n/i;

        }

    }



    // This condition is to handle the case when n

    // is a prime number greater than 2

    if (n > 2)

        s.insert(n);

}

int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int n;

    cin>>n;

    _clear();

    for(int i=0;i<n;i++)

    {

        cin>>x>>y;

        if(x%y!=0)

            cout<<x<<endl;

        else

        {

            ll z=y;

            primeFactors(z);

            ll ans=-1e15,g;

            for(auto c:s)

            {

                g=x;

                while(g%c==0)

                {

                    if((g/c)%y!=0)

                    {

                        ans=max(ans,g/c);

                        break;

                    }

                    g/=c;

                }

            }

            cout<<ans<<endl;

        }

    }

}